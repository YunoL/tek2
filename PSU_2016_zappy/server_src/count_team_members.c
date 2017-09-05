/*
** count_team_members.c for count_team_members in /home/guillaume2.roux/rendu/PSU_2016_zappy/server_src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Thu Jun 29 12:38:32 2017 Guillaume Roux
** Last update Thu Jun 29 12:41:31 2017 Guillaume Roux
*/

#include "../include/server.h"

void	count_team_members(t_data_server *data_server)
{
  int	nb_place;
  t_team_names	*tmp;

  nb_place = data_server->data_flags->clients_nb;
  tmp = data_server->data_flags->team_names;
  while (tmp)
    {
      tmp->place_left = nb_place;
      tmp = tmp->next;
    }
}
