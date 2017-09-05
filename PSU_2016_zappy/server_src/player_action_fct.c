/*
** player_action_fct.c for player_action_fct in /home/guillaume2.roux/rendu/PSU_2016_zappy/server_src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Mon Jun 26 15:04:52 2017 Guillaume Roux
** Last update Sat Jul  1 10:37:34 2017 dorian turba
*/

#include "../include/server.h"

void	fill_result_object(char *result, int nbr_obj, char *name)
{
  int	i;
  char	*space;
  char	*elem;

  i = -1;
  space = strdup(" ");
  elem = strdup(strcat(space, name));
  while (++i < nbr_obj)
    {
      result = strdup(strcat(result, elem));
    }
}

void	fill_result_look(char *result, t_cell_server *cell, int x, int y)
{
  t_client_list	*tmp;

  tmp = cell->client_list;
  while (tmp)
    {
      fill_result_object(result, 1, "player");
      tmp = tmp->next;
    }
  fill_result_object(result, cell->linemate_nbr, "linemate");
  fill_result_object(result, cell->deraumere_nbr, "deraumere");
  fill_result_object(result, cell->sibur_nbr, "sibur");
  fill_result_object(result, cell->mendiane_nbr, "mendiane");
  fill_result_object(result, cell->phiras_nbr, "phiras");
  fill_result_object(result, cell->thystame_nbr, "thystame");
  fill_result_object(result, cell->life_units, "food");
}

void	init_look(t_cmd_param *cmd, t_data_server *d_s, int fd, t_look *look)
{
  look->width = d_s->map->width;
  look->height = d_s->map->height;
  look->level = -1;
  look->o = d_s->clients[fd].orientation;
}

void		look(t_cmd_param *cmd, t_data_server *s_data, int fd)
{
  (void)cmd;
  t_look	lk;
  char		*result;
  int		rk;
  int		x;
  int		y;

  init_look(cmd, s_data, fd, &lk);
  result = strdup("[");
  while (++lk.level <= s_data->clients[fd].level && (rk = -lk.level - 1))
    {
      while (++rk <= lk.level)
	{
	  x = s_data->clients[fd].pos_x + CALC_FOR_LOOK_X;
	  y = s_data->clients[fd].pos_y + CALC_FOR_LOOK_Y;
	  x = (x % lk.width + lk.width) % lk.width;
	  y = (y % lk.height + lk.height) % lk.height;
	  fill_result_look(result, &(s_data->map->cell[x][y]), x, y);
	  if (!(lk.level == s_data->clients[fd].level && rk == lk.level))
	    result = strdup(strcat(result, ","));
	}
    }
  s_data->clients[fd].msg = strdup(strcat(result, "]"));
   free(result);
}

void	broadcast(t_cmd_param *cmd, t_data_server *data_server, int fd)
{
  t_trigo_data	t_data;

  t_data.src_x = data_server->clients[fd].pos_x;
  t_data.src_y = data_server->clients[fd].pos_y;
  t_data.flags_data = data_server->data_flags;
  t_data.serv_data = data_server;
  t_data.msg = cmd->broadcast_msg;
  output_broadcast(&t_data);
}
