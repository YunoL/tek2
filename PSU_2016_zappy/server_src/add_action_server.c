/*
** add_action_server.c for add_action_server in /home/guillaume2.roux/rendu/PSU_2016_zappy/server_src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Fri Jun 23 16:28:52 2017 Guillaume Roux
** Last update Mon Jun 26 12:51:40 2017 Guillaume Roux
*/

#include "../include/server.h"

void	add_action(t_action *action, t_client *client, double timing)
{
  t_action	*tmp;
  t_action	*new;

  tmp = action;
  while (tmp && tmp->next)
    tmp = tmp->next;
  new = xmalloc(sizeof(t_action));
  new->time_start = timing;
  new->time_end = 0;
  new->client = client;
  new->cmd_fct = NULL;
  new->next = NULL;
  if (tmp)
    tmp->next = new;
  else
    action = new;
}

void	remove_action(t_action *begin, t_action *to_del)
{
  t_action	*tmp;
  t_action	*old;

  tmp = begin;
  old = NULL;
  while (tmp)
    {
      if (tmp == to_del)
	{
	  if (old)
	    old->next = tmp->next;
	  else
	    begin = tmp->next;
	  return;
	}
      old = tmp;
      tmp = tmp->next;
    }
}
