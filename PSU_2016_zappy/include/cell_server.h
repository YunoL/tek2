/*
** cell_server.h for PSU_2016_zappy in /home/turba_d/projets/PSU_2016_zappy/include
**
** Made by dorian turba
** Login   <turba_d@epitech.net>
**
** Started on  Tue Jun 20 11:30:15 2017 dorian turba
** Last update Wed Jun 28 17:24:24 2017 dorian turba
*/

#ifndef CELL_SERVER_H
# define CELL_SERVER_H

# include "init_server.h"

typedef struct		s_client_list
{
  t_client		*client;
  struct s_client_list	*next;
}			t_client_list;

typedef struct		s_cell_server
{
  t_client_list		*client_list;
  int			linemate_nbr;
  int			deraumere_nbr;
  int			sibur_nbr;
  int		     	mendiane_nbr;
  int		     	phiras_nbr;
  int		     	thystame_nbr;
  int			life_units;
}			t_cell_server;

#endif /* !CELL_SERVER_H */
