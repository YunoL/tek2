/*
** list_users.c for list_users in /home/guillaume2.roux/bootstrap/PSU_2016_myirc/server_src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Thu Jun  1 14:23:12 2017 Guillaume Roux
** Last update Thu Jun  8 11:55:07 2017 Guillaume Roux
*/

#include "../include/my.h"

void	list_users(t_env *e, int fd)
{
  char	*msg;

  msg = malloc(sizeof(char) * 4096);
  sprintf(msg, "%s\n%s\n%s", RPL_USERSSTART, RPL_USERS, RPL_ENDOFUSERS);
  e->clients[fd].msg = strdup(msg);
  free(msg);
}

void	list_names(char *channel, t_env *e, int fd)
{
  char	*msg;

  msg = malloc(sizeof(char) * 4096);
  sprintf(msg, "%s\n%s", RPL_NAMREPLY, RPL_ENDOFNAMES);
  e->clients[fd].msg = strdup(msg);
  free(msg);
}
