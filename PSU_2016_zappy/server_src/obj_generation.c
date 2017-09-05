/*
** obj_generation.c for obj_generation in /home/guillaume2.roux/rendu/PSU_2016_zappy/server_src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Fri Jun 30 14:42:57 2017 Guillaume Roux
** Last update Fri Jun 30 17:57:07 2017 Guillaume Roux
*/

#include "../include/server.h"

int	count_player(t_data_server *data_server)
{
  int	i;
  int	nb;

  nb = 0;
  for (i = 0; i < MAX_FD; i++)
    {
      if (data_server->fd_type[i] == FD_CLIENT)
	nb++;
    }
  return (nb);
}

void	generate_obj(int nb, t_data_server *data_server, int obj)
{
  int	x;
  int	y;
  t_cell_server	**cell;

  cell = data_server->map->cell;
  while (nb > 0)
    {
      x = rand() % data_server->data_flags->width;
      y = rand() % data_server->data_flags->height;
      if (obj == 0)
	cell[x][y].linemate_nbr += nb;
      else if (obj == 1)
	cell[x][y].deraumere_nbr += nb;
      else if (obj == 2)
	cell[x][y].sibur_nbr += nb;
      else if (obj == 3)
	cell[x][y].mendiane_nbr += nb;
      else if (obj == 4)
	cell[x][y].phiras_nbr += nb;
      else if (obj == 5)
	cell[x][y].thystame_nbr += nb;
      else if (obj == 6)
	cell[x][y].life_units += nb;
      nb--;
    }
}

void	obj_generation(t_data_server *data_server)
{
  int r[7];
  int	nb_player;
  int	i;
  t_data_flags	*data_flags;

  nb_player = count_player(data_server);
  data_flags = data_server->data_flags;
  r[0] = (P_LINEMATE * 100000) / CALC_P;
  r[1] = (P_DERAUMERE * 100000) / CALC_P;
  r[2] = (P_SIBUR * 100000) / CALC_P;
  r[3] = (P_MENDIANE * 100000) / CALC_P;
  r[4] = (P_PHIRAS * 100000) / CALC_P;
  r[5] = (P_THYSTAME * 100000) / CALC_P;
  r[6] = (P_FOOD * 100000) / CALC_P;
  for (i = 0; i < 7; i++)
    generate_obj(r[0], data_server, i);
}
