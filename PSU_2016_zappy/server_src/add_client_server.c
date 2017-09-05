/*
** add_client_server.c for add_client_server in /home/guillaume2.roux/rendu/PSU_2016_zappy/server_src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Tue Jun 20 11:30:51 2017 Guillaume Roux
** Last update Fri Jun 30 12:20:46 2017 Guillaume Roux
*/

#include "../include/server.h"
#include "../include/init_server.h"

void	init_client(t_client *client, int fd, t_data_flags *data_flags)
{
  client->msg = NULL;
  client->team = NULL;
  client->linemate_carried = 0;
  client->deraumere_carried = 0;
  client->sibur_carried = 0;
  client->mendiane_carried = 0;
  client->phiras_nbr = 0;
  client->thystame_nbr = 0;
  client->life_units = 10;
  client->fd = fd;
  client->orientation = 0;
  client->pos_x = rand() % data_flags->width;
  client->pos_y = rand() % data_flags->height;
  client->level = 1;
}

void add_client(t_data_server *data_server, int s)
{
  int cs;
  struct sockaddr_in client_sin;
  int client_sin_len;
  t_cell_server	*cell;
  t_client	*client;

  client_sin_len = sizeof(client_sin);
  if ((cs = accept(s, (struct sockaddr *)&client_sin, &client_sin_len)) == -1)
    closing("Error : can't accept !", cs, EXIT_FAILURE);
  data_server->fd_type[cs] = FD_CLIENT;
  data_server->fct_read[cs] = client_read;
  data_server->fct_write[cs] = client_write;
  client = &(data_server->clients[cs]);
  init_client(client, cs, data_server->data_flags);
  cell = &(data_server->map->cell[client->pos_x][client->pos_y]);
  client_add(client, cell);
  make_msg("WELCOME", &(data_server->clients[cs]));
  printf("Client : %d\n", data_server->clients[cs].fd);
}
