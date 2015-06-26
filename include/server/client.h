/*
** client.h for  in /home/zwertv_e/rendu/PSU_2014_myirc
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Thu Apr  9 16:43:20 2015 zwertv_e
** Last update Fri Jun 26 14:25:46 2015 Antoine Plaskowski
*/

#ifndef		CLIENT_H_
# define	CLIENT_H_

typedef	struct	s_client	t_client;

# include	"accept_client.h"
# include	"cbuf.h"
# include	"node.h"
# include	"player.h"

typedef	struct	s_string	t_string;
struct		s_string
{
  t_node	node;
  char		*str;
};

struct		s_client
{
  t_node	node;
  t_clientaddr	ca;
  t_cbuf	cbuf;
  t_string	*to_write;
  t_player	*player;
};

t_client	*add_client(t_client *list, t_clientaddr const * const ca);
t_client	*remove_client(t_client *list, t_client *to_rem);

#endif		/* !CLIENT_H_ */
