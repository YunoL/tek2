/*
** move_action_fct.c for move_action_fct in /home/guillaume2.roux/rendu/PSU_2016_zappy/server_src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Mon Jun 26 15:02:48 2017 Guillaume Roux
** Last update Thu Jun 29 11:52:57 2017 Guillaume Roux
*/

#include "../include/server.h"

void	forward(t_cmd_param *cmd, t_data_server *data_server, int fd)
{
  int	old_x;
  int	old_y;
  t_client	*tmp;

  (void)cmd;
  tmp = &(data_server->clients[fd]);
  old_x = REL_X_POS(tmp->pos_x, data_server->data_flags->width);
  old_y = REL_Y_POS(tmp->pos_y, data_server->data_flags->height);
  if (tmp->orientation == 0)
    tmp->pos_y = REL_Y_POS(tmp->pos_y - 1, data_server->data_flags->height);
  else if (tmp->orientation == 2)
    tmp->pos_x = REL_X_POS(tmp->pos_x + 1, data_server->data_flags->width);
  else if (tmp->orientation == 4)
    tmp->pos_y = REL_Y_POS(tmp->pos_y + 1, data_server->data_flags->height);
  else if (tmp->orientation == 6)
    tmp->pos_x = REL_X_POS(tmp->pos_x - 1, data_server->data_flags->width);
  printf("Client %d:\nMove from :\nx : %d ; y : %d\n", fd, old_x, old_y);
  printf("to x : %d ; y : %d\n", tmp->pos_x, tmp->pos_y);
  remove_client(tmp->fd, &(data_server->map->cell[old_x][old_y]));
  client_add(tmp, &(data_server->map->cell[tmp->pos_x][tmp->pos_y]));
  make_msg(REP_GOOD, tmp);
}

void	right(t_cmd_param *cmd, t_data_server *data_server, int fd)
{
  int	old_or;
  t_client	*tmp;

  (void)cmd;
  tmp = &(data_server->clients[fd]);
  old_or = tmp->orientation;
  if (tmp->orientation < 6)
    tmp->orientation += 2;
  else
    tmp->orientation = 0;
  printf("Client %d:\norientation : %d => %d\n", fd, old_or, tmp->orientation);
  make_msg(REP_GOOD, tmp);
}

void	left(t_cmd_param *cmd, t_data_server *data_server, int fd)
{
  int	old_or;
  t_client	*tmp;

  (void)cmd;
  tmp = &(data_server->clients[fd]);
  old_or = tmp->orientation;
  if (tmp->orientation > 0)
    tmp->orientation -= 2;
  else
    tmp->orientation = 6;
  printf("Client %d:\norientation : %d => %d\n", fd, old_or, tmp->orientation);
  make_msg(REP_GOOD, tmp);
}
