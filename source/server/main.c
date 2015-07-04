/*
** main.c for  in /home/zwertv_e/rendu/PSU_2014_zappy
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Fri Jul  3 16:46:24 2015 zwertv_e
** Last update Sat Jul  4 14:57:22 2015 Antoine Plaskowski
*/

#include        <unistd.h>
#include        <signal.h>
#include        <stdio.h>
#include	<sys/socket.h>
#include        <SDL2/SDL.h>
#include        "graphic.h"
#include	"create_binded_socket.h"
#include	"manage_select.h"
#include	"int_handler.h"
#include	"game.h"
#include	"map.h"
#include	"node.h"
#include	"player.h"
#include	"select_utils.h"
#include	"inv.h"
#include	"command.h"
#include	"kill_client.h"

static int	init_socket(char const * const port)
{
  int		sfd;

  if (signal(SIGINT, &int_handler) == SIG_ERR)
    perror("signal()");
  if ((sfd = create_binded_socket(port)) == -1)
    return (-1);
  if (listen(sfd, 42))
    {
      perror("listen()");
      return (-1);
    }
  return (sfd);
}

static bool	graphic(t_display *display, t_texture *texture, t_game *game)
{
  input(display, &game->map);
  draw_stone(&game->map, texture, display);
  draw_grid(&game->map, display);
  draw_select(display, &game->map, texture);
  SDL_RenderPresent(display->renderer);
  SDL_SetRenderDrawColor(display->renderer, 0, 127, 0, 255);
  SDL_RenderClear(display->renderer);
  SDL_SetRenderDrawColor(display->renderer, 255, 255, 255, 255);
  return (false);
}

static t_client	*game_select(t_game *game, t_client *client, int sfd)
{
  t_time	s_time;

  do_action(game->player, &s_time);
  client = manage_select(client, &s_time, sfd);
  get_cmd(game, client);
  client = kill_client(client);
  return (client);
}

static bool	init_graph(t_display *display, t_texture *texture)
{
  display->fenetre = init_video();
  init_renderer(display->fenetre, display);
  init_texture(texture, display->renderer);
  return (false);
}

int		main(int argc, char **argv)
{
  t_texture     texture;
  t_display	display;
  int		sfd;
  t_client	*client;
  t_game	game;

  /* init_graph(&display, &texture); */
  srandom((unsigned int)time(NULL));
  client = NULL;
  if (init_game(&game, argv, argc) == NULL)
    return (1);
  show_option(&game.option);
  if ((sfd = init_socket(game.option.p)) == -1)
    return (1);
  while (g_keep_running == true)
    {
      client = game_select(&game, client, sfd);
      /* graphic(&display, &texture, &game); */
    }
  while (client != NULL)
    client = sup_client(client);
  printf("Bye\n");
  close(sfd);
  delete_game(&game);
  return (0);
}
