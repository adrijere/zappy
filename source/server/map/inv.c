/*
** inv.c for  in /home/zwertv_e/rendu/PSU_2014_zappy
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Thu Jul  2 18:59:57 2015 zwertv_e
** Last update Sat Jul  4 23:50:17 2015 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"inv.h"

t_inv		*init_inv(t_inv *inv)
{
  if (inv == NULL)
    return (NULL);
  inv->linemate = 0;
  inv->deraumere = 0;
  inv->sibur = 0;
  inv->mendiane = 0;
  inv->phiras = 0;
  inv->thystame = 0;
  inv->food = 0;
  return (inv);
}

bool		add_ressource(t_inv * const inv, int const type,
			      size_t const quantity, bool add)
{
  if (inv == NULL)
    return (true);
  if (type > FOOD + 1)
    return (true);
  if (add == true)
    (&inv->linemate)[type] += quantity;
  else
    {
      if ((&inv->linemate)[type] < quantity)
	return (true);
      (&inv->linemate)[type] -= quantity;
    }
  return (false);
}

size_t		count_ressources(t_inv const * const inv)
{
  size_t	res;

  res = 0;
  res += inv->linemate;
  res += inv->deraumere;
  res += inv->sibur;
  res += inv->mendiane;
  res += inv->phiras;
  res += inv->thystame;
  res += inv->food;
  return (res);
}

char		*get_inventory(t_inv const * const inv)
{
  char		*res;
  int		to_malloc;

  to_malloc = snprintf(NULL, 0, "{linemate %lu, deraumere %lu, \
sibur %lu, mendiane %lu, phiras %lu, thystame %lu, food %lu}", inv->linemate,
		       inv->deraumere, inv->sibur, inv->mendiane, inv->phiras,
		       inv->thystame, inv->food);
  res = malloc(sizeof(char) * (to_malloc + 1));
  snprintf(res, to_malloc + 1, "{linemate %lu, deraumere %lu, \
sibur %lu, mendiane %lu, phiras %lu, thystame %lu, food %lu}", inv->linemate,
		       inv->deraumere, inv->sibur, inv->mendiane, inv->phiras,
		       inv->thystame, inv->food);
  return (res);
}
