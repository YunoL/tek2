/*
** send_msg.c for send_msg in /home/guillaume2.roux/rendu/PSU_2016_myirc/server_src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Tue Jun  6 17:16:04 2017 Guillaume Roux
** Last update Tue Jun  6 17:19:26 2017 Guillaume Roux
*/

#include "../include/my.h"

void	send_msg(t_env *e, int fd, char *msg)
{
  char	*tmp;

  tmp = malloc(sizeof(char) * 4096);
  sprintf(tmp, "%s", msg);
  e->clients[fd].msg = strdup(msg);
  free(tmp);
}
