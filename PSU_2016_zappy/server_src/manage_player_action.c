/*
** manage_player_action.c for manage_player_action in /home/guillaume2.roux/rendu/PSU_2016_zappy/server_src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Mon Jun 26 15:08:17 2017 Guillaume Roux
** Last update Thu Jun 29 14:29:52 2017 Guillaume Roux
*/

#include "../include/server.h"

void	inventory(t_cmd_param *cmd, t_data_server *data_server, int fd)
{
  char	*msg;
  t_client	*client;

  (void)cmd;
  client = &(data_server->clients[fd]);
  msg = xmalloc(sizeof(char) * 512);
  sprintf(msg,
	  "[food %d, sibur %d, phiras %d, mendiane %d, thystame %d, linemate %d, deraumere %d]",
	  client->life_units, client->sibur_carried, client->phiras_nbr,
	  client->mendiane_carried, client->thystame_nbr, client->linemate_carried,
	  client->deraumere_carried);
  client->msg = strdup(msg);
  free(msg);
}

void	connect_nbr(t_cmd_param *cmd, t_data_server *data_server, int fd)
{
  char	*msg;
  t_client	*client;
  t_team_names	*tmp;

  (void)cmd;
  client = &(data_server->clients[fd]);
  tmp = data_server->data_flags->team_names;
  while (tmp)
    {
      if (xstrcmp(tmp->name, client->team) == 0)
	{
    msg = xmalloc(sizeof(char) * 512);
    sprintf(msg, "%d", tmp->place_left);
    client->msg = strdup(msg);
    free(msg);
	}
      tmp = tmp->next;
    }
}

void	my_fork(t_cmd_param *cmd, t_data_server *data_server, int fd)
{
  (void)cmd;
}

void	eject(t_cmd_param *cmd, t_data_server *data_server, int fd)
{
  t_client	*client;
  t_cell_server	*cell;
  t_client_list	*tmp;

  (void)cmd;
  client = &(data_server->clients[fd]);
  cell = &(data_server->map->cell[client->pos_x][client->pos_y]);
  tmp = cell->client_list;
  while (tmp)
    {
      if (tmp->client->fd != fd && tmp->client->fd != 0)
	pushing(client->orientation, tmp->client, data_server);
      tmp = tmp->next;
    }
}
