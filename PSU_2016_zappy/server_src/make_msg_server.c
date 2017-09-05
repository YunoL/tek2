/*
** make_msg_server.c for make_msg_server in /home/guillaume2.roux/rendu/PSU_2016_zappy/server_src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Wed Jun 21 13:54:27 2017 Guillaume Roux
** Last update Wed Jun 21 14:01:17 2017 Guillaume Roux
*/

#include "../include/server.h"

void	make_msg(char *txt, t_client *client)
{
  char	*msg;

  msg = malloc(sizeof(char) * strlen(txt));
  sprintf(msg, "%s", txt);
  client->msg = strdup(msg);
  free(msg);
}
