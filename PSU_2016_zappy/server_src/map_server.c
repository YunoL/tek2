/*
** map_server.c for map_server in /home/guillaume2.roux/rendu/PSU_2016_zappy/server_src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Tue Jun 20 15:19:25 2017 Guillaume Roux
** Last update Wed Jun 28 15:29:28 2017 Guillaume Roux
*/

#include "../include/server.h"

void	init_map(t_map *map, t_data_flags *data_flags)
{
  int	i;
  int	j;

  map->width = data_flags->width;
  map->height = data_flags->height;
  map->cell = xmalloc(sizeof(t_cell_server *) * map->width);
  for (i = 0; i < map->width; i++)
    {
      map->cell[i] = xmalloc(sizeof(t_cell_server) * map->height);
      for (j = 0; j < map->height; j++)
	init_cell(&(map->cell[i][j]));
    }
}
