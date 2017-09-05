/*
** manage_channel.c for manage_channel in /home/guillaume2.roux/rendu/PSU_2016_myirc/utility/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Fri Jun  2 20:31:30 2017 Guillaume Roux
** Last update Fri Jun  9 14:02:07 2017 Guillaume Roux
*/

#include "../include/my.h"

void	add_channel(t_env *e, char *channel, int fd)
{
  t_channel	*tmp;
  t_channel	*new;

  tmp = e->clients[fd].channel;
  while (tmp && tmp->next)
    tmp = tmp->next;
  new = malloc(sizeof(t_channel));
  new->name = strdup(channel);
  new->next = NULL;
  if (tmp)
    tmp->next = new;
  else
    e->clients[fd].channel = new;
}

void	remove_channel(t_env *e, char *channel, int fd)
{
  t_channel	*tmp;
  t_channel	*old;

  tmp = e->clients[fd].channel;
  old = NULL;
  while (tmp)
    {
      if (xstrcmp(tmp->name, channel) == 0)
	{
	  free(tmp->name);
	  if (old)
	    old->next = tmp->next;
	  else
	    e->clients[fd].channel = tmp->next;
	  free(tmp);
	  return;
	}
      old = tmp;
      tmp = tmp->next;
    }
}

int	channel_in_list(t_channel *fd_chan, t_channel *i_chan)
{
  t_channel	*fd_tmp;
  t_channel	*i_tmp;

  fd_tmp = fd_chan;
  while (fd_tmp)
    {
      i_tmp = i_chan;
      while (i_tmp)
	{
	  if (xstrcmp(fd_tmp->name, i_tmp->name) == 0)
	    return (0);
	  i_tmp = i_tmp->next;
	}
      fd_tmp = fd_tmp->next;
    }
  return (1);
}

int	get_channel(t_env *e, char *channel, int fd)
{
  t_channel	*tmp;

  if (!channel)
    return (1);
  tmp = e->clients[fd].channel;
  while (tmp)
    {
      if (xstrcmp(tmp->name, channel) == 0)
	return (0);
      tmp = tmp->next;
    }
  return (1);
}
