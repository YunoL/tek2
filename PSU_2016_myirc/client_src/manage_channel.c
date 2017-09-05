/*
** manage_channel.c for manage_channel in /home/guillaume2.roux/rendu/PSU_2016_myirc/client_src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Fri Jun  2 21:23:42 2017 Guillaume Roux
** Last update Wed Jun  7 12:18:33 2017 Guillaume Roux
*/

#include "../include/client.h"

int	check_channel(char *channel)
{
  int	i;

  if ((channel[0] != '&' && channel[0] != '#') || strlen(channel) > MAX_LEN_CHANNEL)
    return (1);
  for (i = 0; channel[i]; i++)
    {
      if (channel[i] == ',' || channel[i] == ' ')
	return (1);
    }
  return (0);
}

void	add_channel(t_client *client, char *channel)
{
  t_channel	*tmp;
  t_channel	*new;

  tmp = client->channel;
  while (tmp && tmp->next)
    tmp = tmp->next;
  new = malloc(sizeof(t_channel));
  new->name = strdup(channel);
  new->next = NULL;
  if (tmp)
    tmp->next = new;
  else
    client->channel = new;
}

void	remove_channel(t_client *client, char *channel)
{
  t_channel	*tmp;
  t_channel	*old;

  tmp = client->channel;
  old = NULL;
  while (tmp)
    {
      if (xstrcmp(tmp->name, channel) == 0)
	{
	  free(tmp->name);
	  if (old)
	    old->next = tmp->next;
	  else
	    client->channel = tmp->next;
	  free(tmp);
	  return;
	}
      old = tmp;
      tmp = tmp->next;
    }
}

int	get_channel(t_client *client, char *channel)
{
  t_channel	*tmp;

  tmp = client->channel;
  while (tmp)
    {
      if (xstrcmp(tmp->name, channel) == 0)
	return (0);
      tmp = tmp->next;
    }
  return (1);
}
