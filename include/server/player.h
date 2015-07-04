/*
** player.h for  in /home/zwertv_e/rendu/PSU_2014_zappy
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Tue Jun 23 14:52:23 2015 zwertv_e
** Last update Sat Jul  4 18:37:39 2015 Antoine Plaskowski
*/

#ifndef		PLAYER_H__
# define	PLAYER_H__

typedef	struct	s_lvlup	t_lvlup;
typedef	struct	s_player	t_player;

typedef	enum
  {
    NORTH = 0,
    SOUTH = 1,
    WEST = 2,
    EAST = 3
  }		t_dir;

# include	"time_utils.h"
# include	"inv.h"
# include	"node.h"
# include	"map.h"
# include	"action.h"
# include	"client.h"

# define	NB_LEVEL	(6)

struct		s_lvlup
{
  size_t        nb_players;
  t_inv	        ressources;
};

struct		s_player
{
  t_node	node;
  t_coord	coord;
  t_dir		dir;
  size_t	range;
  char		*team;
  t_inv		inv;
  t_time	act;
  t_time	food;
  t_action	*action;
  t_client	*client;
};

t_player	*init_player(t_map * const map, char * const team,
			     size_t const x, size_t const y);
void		move(t_map const * const map, t_player * const player);
void		rotate_left(t_player * const player);
void		rotate_right(t_player * const player);

bool		take_item(t_map * const map,
			  t_player * const player, int const type);
bool		drop_item(t_map * const map,
			  t_player * const player, int const type);
bool		expulse_players(t_game * const game,
				t_map * const map,
				t_player const * const player);
bool		player_levelup(t_game * const game,
			       t_map * const map, t_player * const player,
			       bool const do_);
char		*player_view(t_game const * const game,
			    t_map const * const map,
			    t_player const * const player);

t_player	*find_free_player(t_player *player, char * const team);
bool		add_action(t_player * const player, char * const str,
			   size_t const t);
size_t		player_team_online(t_player * player, char * const team);

char		*concat(char *str1, char const * const str2,
			bool const do_free);
void		find_squares(t_map const * const map,
			     t_player const * const player, t_coord *list,
			     size_t const range);
size_t		find_nb_squares(size_t const accu, size_t const range);
size_t		get_x(t_map const * const map, t_player const * const player,
		      int const h, int const w);
size_t		get_y(t_map const * const map, t_player const * const player,
		      int const h, int const w);
t_player	*delete_player(t_player *player);

#endif		/* PLAYER_H__ */
