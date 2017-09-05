/*
** make_msg_pos.c for make_msg_pos in /home/guillaume2.roux/rendu/PSU_2016_zappy/server_src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Fri Jun 23 11:41:51 2017 Guillaume Roux
** Last update Fri Jun 23 12:01:16 2017 Guillaume Roux
*/

#include "../include/server.h"

void	make_msg_pos(t_client *client, char *msg, int int_pos)
{
  char	*new_msg;

  new_msg = malloc(sizeof(char) * 1024);
  sprintf(msg, "message %d, %s", int_pos, msg);
  client->msg = strdup(msg);
  free(msg);
}
