/*
** send_to_all.c for send_to_all in /home/guillaume2.roux/rendu/PSU_2016_myirc/server_src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Sat Jun 10 12:35:05 2017 Guillaume Roux
** Last update Sun Jun 11 16:06:09 2017 Guillaume Roux
*/

#include "../include/my.h"

void	send_all_channel(t_env *e, int fd, char *msg)
{
  int	j;

  if (e->clients[fd].channel != NULL)
{
for (j = 0; j < MAX_FD; j++)
  {
    if (e->fd_type[j] == FD_CLIENT && e->fds[j] != 0 && e->fds[j] != fd &&
  channel_in_list(e->clients[fd].channel, e->clients[j].channel) == 0)
msg_for(e, j, msg, e->clients[fd].nickname);
  }
}
}
