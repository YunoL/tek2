/*
** make_msg.c for make_msg in /home/guillaume2.roux/rendu/PSU_2016_myirc/client_src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Fri Jun  2 11:33:58 2017 Guillaume Roux
** Last update Fri Jun  2 11:36:07 2017 Guillaume Roux
*/

#include "../include/client.h"

void	make_msg(t_client *client, char *msg, int nb)
{
  if (nb == 0)
    {
      if (client->to_client)
	free(client->to_client);
      client->to_client = strdup(msg);
    }
  else if (nb == 1)
    {
      if (client->to_server)
	free(client->to_server);
      client->to_server = strdup(msg);
    }
}
