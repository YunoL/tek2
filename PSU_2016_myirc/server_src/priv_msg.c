/*
** priv_msg.c for priv_msg in /home/guillaume2.roux/rendu/PSU_2016_myirc/server_src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Tue Jun  6 13:02:22 2017 Guillaume Roux
** Last update Fri Jun  9 23:35:56 2017 Guillaume Roux
*/

#include "../include/my.h"

int	find_nick(char *nickname, t_env *e)
{
  int	i;

  for (i = 0; i < MAX_FD; i++)
    {
      if (xstrcmp(nickname, e->clients[i].nickname) == 0)
	return (i);
    }
  return (0);
}

char	*concat_msg(char **tab)
{
  int	i;
  char	*msg;

  msg = malloc(sizeof(char) * 4096);
  msg = strcpy(msg, tab[2]);
  for (i = 3; tab[i]; i++)
    {
      strcat(msg, " ");
      strcat(msg, tab[i]);
    }
  return (msg);
}

void	send_private_msg(char *nickname, char **tab, t_env *e, int fd)
{
  int	fd_dest;
  char	*msg;

  msg = malloc(sizeof(char) * 4096);
  if ((fd_dest = find_nick(nickname, e)) > 0)
    {
      sprintf(msg, ":%s PRIVMSG %s :%s", e->clients[fd].nickname, nickname, concat_msg(tab));
      e->clients[fd_dest].msg = strdup(msg);
    }
  else
    {
      sprintf(msg, "401 %s :%s", nickname, ERR_NOSUCHNICK);
      e->clients[fd].msg = strdup(msg);
    }
  free(msg);
}
