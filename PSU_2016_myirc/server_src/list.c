/*
** list.c for list in /home/guillaume2.roux/rendu/PSU_2016_myirc/server_src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Tue Jun  6 12:17:11 2017 Guillaume Roux
** Last update Mon Jun 19 10:44:44 2017 Guillaume Roux
*/

#include "../include/my.h"

int	already_there(t_env *e, char *channel)
{
  t_channel	*tmp;

  tmp = e->channel_list;
  while (tmp)
    {
      if (xstrcmp(tmp->name, channel) == 0)
	return (0);
      tmp = tmp->next;
    }
  return (1);
}

void	add_in_list(t_env *e, char *channel)
{
  t_channel	*tmp;
  t_channel	*new;

  tmp = e->channel_list;
  while (tmp && tmp->next)
    tmp = tmp->next;
  new = malloc(sizeof(t_channel));
  new->name = strdup(channel);
  new->next = NULL;
  if (tmp)
    tmp->next = new;
  else
    e->channel_list = new;
}

char	*make_chan_list(t_env *e)
{
  char	*chan_list;
  t_channel	*tmp;

  chan_list = malloc(sizeof(char) * 4096);
  tmp = e->channel_list;
  while (tmp)
    {
      if (tmp->name)
	{
	  chan_list = xstrcat(chan_list, tmp->name);
	  chan_list = xstrcat(chan_list, "\n");
  }
      tmp = tmp->next;
    }
  return(chan_list);
}

void	disp_list(char *str, t_env *e, int fd)
{
  t_channel	*tmp;
  char	*msg;

  tmp = e->channel_list;
  msg = malloc(sizeof(char) * 4096);
  sprintf(msg, "%s\n%s%s", RPL_LISTSTART, make_chan_list(e), RPL_LISTEND);
  e->clients[fd].msg = strdup(msg);
  free(msg);
}
