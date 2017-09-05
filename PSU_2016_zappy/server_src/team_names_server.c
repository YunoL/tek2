/*
** team_names_server.c for team_names_server in /home/guillaume2.roux/rendu/PSU_2016_zappy/server_src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Mon Jun 19 14:02:58 2017 Guillaume Roux
** Last update Thu Jun 29 12:38:05 2017 Guillaume Roux
*/

#include "../include/server.h"

void	add_name(char *name, t_data_flags *data_flags)
{
  t_team_names	*tmp;
  t_team_names	*new;

  tmp = data_flags->team_names;
  while (tmp && tmp->next)
    tmp = tmp->next;
  new = xmalloc(sizeof(t_team_names));
  new->name = strdup(name);
  new->place_left = 0;
  new->next = NULL;
  if (tmp)
    tmp->next = new;
  else
    data_flags->team_names = new;
}

void	remove_name(char *name, t_data_flags *data_flags)
{
  t_team_names	*tmp;
  t_team_names	*old;

  tmp = data_flags->team_names;
  old = NULL;
  while (tmp)
    {
      if (xstrcmp(tmp->name, name) == 0)
	{
	  free(tmp->name);
	  if (old)
	    old->next = tmp->next;
	  else
	    data_flags->team_names = tmp->next;
	  free(tmp);
	  return;
	}
      old = tmp;
      tmp = tmp->next;
    }
}
