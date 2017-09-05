/*
** moving_client.c for moving_client in /home/guillaume2.roux/rendu/PSU_2016_zappy/server_src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Thu Jun 29 14:15:49 2017 Guillaume Roux
** Last update Fri Jun 30 12:27:29 2017 Guillaume Roux
*/

#include "../include/server.h"

void	moving_client(t_data_server *data_server, int fd_client, int x, int y)
{
  t_client	*client;
  t_cell_server	*current_cell;
  t_cell_server	*moved_cell;

  client = &(data_server->clients[fd_client]);
  current_cell = &(data_server->map->cell[client->pos_x][client->pos_y]);
  moved_cell = &(data_server->map->cell[x][y]);
  client->pos_x = REL_X_POS(x, data_server->data_flags->width);
  client->pos_y = REL_Y_POS(y, data_server->data_flags->height);
  client_add(client, moved_cell);
  remove_client(client->fd, current_cell);
}

void	pushing(int orientation, t_client *pushed_client,
		t_data_server *data_server)
{
  char	*msg;

  if (orientation == 0)
    moving_client(data_server, pushed_client->fd, pushed_client->pos_x,
		  pushed_client->pos_y - 1);
  else if (orientation == 2)
    moving_client(data_server, pushed_client->fd, pushed_client->pos_x + 1,
		  pushed_client->pos_y);
  else if (orientation == 4)
    moving_client(data_server, pushed_client->fd, pushed_client->pos_x,
		  pushed_client->pos_y + 1);
  else if (orientation == 6)
    moving_client(data_server, pushed_client->fd, pushed_client->pos_x - 1,
		   pushed_client->pos_y);
  msg = xmalloc(sizeof(char) * 100);
  sprintf(msg, "eject : %d", orientation);
  pushed_client->msg = strdup(msg);
  free(msg);
}
