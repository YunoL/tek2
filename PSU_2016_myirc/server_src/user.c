/*
** user.c for user in /home/guillaume2.roux/rendu/PSU_2016_myirc/server_src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Fri Jun  9 12:00:50 2017 Guillaume Roux
** Last update Fri Jun  9 14:20:10 2017 Guillaume Roux
*/

#include "../include/my.h"

void	disp_user(t_env *e, int fd, char *nickname)
{
  char	*msg;

  msg = malloc(sizeof(char) * 4096);
  sprintf(msg, "001 NICK: %s connected", nickname);
  e->clients[fd].msg = strdup(msg);
  free(msg);
}
