/*
** level_up_fct.c for level_up_fct in /home/guillaume2.roux/rendu/PSU_2016_zappy/server_src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Mon Jun 26 15:10:20 2017 Guillaume Roux
** Last update Fri Jun 30 13:45:00 2017 Guillaume Roux
*/

#include "../include/server.h"

void	take_cell(int *obj_cell, int *obj_client, t_client *client)
{
  int	tmp_client;
  int	tmp_cell;

  tmp_client = *obj_client;
  tmp_cell = *obj_cell;
  if (tmp_cell > 0)
    {
      tmp_cell--;
      tmp_client++;
      *obj_cell = tmp_cell;
      *obj_client = tmp_client;
      make_msg(REP_GOOD, client);
    }
  else
    make_msg(REP_BAD, client);
}

void	take(t_cmd_param *cmd, t_data_server *data_server, int fd)
{
  t_client	*client;
  t_cell_server	*cell;

  client = &(data_server->clients[fd]);
  cell = &(data_server->map->cell[client->pos_x][client->pos_y]);
  if (xstrcmp(cmd->object_name, "linemate") == 0)
    take_cell(&(cell->linemate_nbr), &(client->linemate_carried), client);
  else if (xstrcmp(cmd->object_name, "deraumere") == 0)
    take_cell(&(cell->deraumere_nbr), &(client->deraumere_carried), client);
  else if (xstrcmp(cmd->object_name, "sibur") == 0)
    take_cell(&(cell->sibur_nbr), &(client->sibur_carried), client);
  else if (xstrcmp(cmd->object_name, "mendiane") == 0)
    take_cell(&(cell->mendiane_nbr), &(client->mendiane_carried), client);
  else if (xstrcmp(cmd->object_name, "phiras") == 0)
    take_cell(&(cell->phiras_nbr), &(client->phiras_nbr), client);
  else if (xstrcmp(cmd->object_name, "thystame") == 0)
    take_cell(&(cell->thystame_nbr), &(client->thystame_nbr), client);
  else if (xstrcmp(cmd->object_name, "food") == 0)
    take_cell(&(cell->life_units), &(client->life_units), client);
}

void	set_cell(int *obj_cell, int *obj_client, t_client *client)
{
  int	tmp_client;
  int	tmp_cell;

  tmp_client = *obj_client;
  tmp_cell = *obj_cell;
  if (tmp_client > 0)
    {
      tmp_client--;
      tmp_cell++;
      *obj_cell = tmp_cell;
      *obj_client = tmp_client;
      make_msg(REP_GOOD, client);
    }
  else
    make_msg(REP_BAD, client);
}

void	set(t_cmd_param *cmd, t_data_server *data_server, int fd)
{
  t_client	*client;
  t_cell_server	*cell;

  client = &(data_server->clients[fd]);
  cell = &(data_server->map->cell[client->pos_x][client->pos_y]);
  if (xstrcmp(cmd->object_name, "linemate") == 0)
    set_cell(&(cell->linemate_nbr), &(client->linemate_carried), client);
  else if (xstrcmp(cmd->object_name, "deraumere") == 0)
    set_cell(&(cell->deraumere_nbr), &(client->deraumere_carried), client);
  else if (xstrcmp(cmd->object_name, "sibur") == 0)
    set_cell(&(cell->sibur_nbr), &(client->sibur_carried), client);
  else if (xstrcmp(cmd->object_name, "mendiane") == 0)
    set_cell(&(cell->mendiane_nbr), &(client->mendiane_carried), client);
  else if (xstrcmp(cmd->object_name, "phiras") == 0)
    set_cell(&(cell->phiras_nbr), &(client->phiras_nbr), client);
  else if (xstrcmp(cmd->object_name, "thystame") == 0)
    set_cell(&(cell->thystame_nbr), &(client->thystame_nbr), client);
  else if (xstrcmp(cmd->object_name, "food") == 0)
    set_cell(&(cell->life_units), &(client->life_units), client);
}

void	incantation(t_cmd_param *cmd, t_data_server *data_server, int fd)
{
  (void)cmd;
}
