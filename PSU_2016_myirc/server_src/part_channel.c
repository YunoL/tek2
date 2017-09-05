/*
** part_channel.c for part_channel in /home/guillaume2.roux/bootstrap/PSU_2016_myirc/server_src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Thu Jun  1 14:04:17 2017 Guillaume Roux
** Last update Fri Jun  9 23:25:27 2017 Guillaume Roux
*/

#include "../include/my.h"

void	part_channel(char *channel, t_env *e, int fd)
{
  char	*msg;

  if (get_channel(e, channel, fd) == 0)
    {
      remove_channel(e, channel, fd);
      msg = malloc(sizeof(char) * 512);
      sprintf(msg, "PART %s", channel);
      e->clients[fd].msg = strdup(msg);
      free(msg);
    }
}
