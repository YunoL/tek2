/*
** fct_client.c for fct_client in /home/guillaume2.roux/bootstrap/PSU_2016_myirc/client_src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Thu Jun  1 11:10:59 2017 Guillaume Roux
** Last update Fri Jun  9 11:48:40 2017 Guillaume Roux
*/

#include "../include/client.h"

void	write_server(int fd, t_client *client)
{
  if (client->to_server)
    {
      dprintf(fd, "%s", client->to_server);
      free(client->to_server);
      client->to_server = NULL;
    }
}

void	write_client(t_client *client)
{
  if (client->to_client)
    {
      printf("%s", client->to_client);
      free(client->to_client);
      client->to_client = NULL;
    }
}

void	read_input(t_client *client)
{
  char	buffer[4096];
  int	r;

  r = read(0, buffer, 4095);
  if (r > 0)
    {
      if (r > 1)
	buffer[r - 1] = '\0';
      check_cmd(buffer, client);
    }
}

void	read_server(int fd, t_client *client)
{
  int	r;
  char	buffer[4096];

  r = read(fd, buffer, 4096);
  if (r > 0)
    {
      buffer[r] = '\0';
      if (client->to_client)
	free(client->to_client);
      client->to_client = strdup(buffer);
    }
}
