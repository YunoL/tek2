/*
** manage_client.c for manage_client in /home/guillaume2.roux/rendu/PSU_2016_myftp/src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Mon May 15 14:51:51 2017 Guillaume Roux
** Last update Thu May 18 19:18:07 2017 Guillaume Roux
*/

#include "../include/my.h"

bool	user_value;
bool pass_value;

void	init_client(client_s *my_client, int client_fd)
{
  my_client->client_fd = client_fd;
  my_client->transf_mode = 0;
  my_client->is_co = true;
  my_client->is_root = false;
}

void	manage_client(int client_fd)
{
  client_s	my_client;

  init_client(&my_client, client_fd);
  while (my_client.is_co == true)
    {
      if (user_value != true || pass_value != true)
	identification(&my_client);
      else if (execute(&my_client) == 0)
	my_quit(&my_client);
    }
}
