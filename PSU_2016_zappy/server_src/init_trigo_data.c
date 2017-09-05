/*
** init_trigo_data.c for init_trigo_data in /home/guillaume2.roux/rendu/PSU_2016_zappy/server_src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Fri Jun 23 12:08:30 2017 Guillaume Roux
** Last update Fri Jun 23 12:18:02 2017 Guillaume Roux
*/

#include "../include/server.h"

// Il faut initialiser aux bonnes valeurs les coordonnées
void	init_trigo_data(t_trigo_data *trigo_data, t_data_flags *data_flags,
			t_data_server *data_server)
{
  trigo_data->src_x = 0;
  trigo_data->src_y = 0;
  trigo_data->dest_x = 0;
  trigo_data->dest_y = 0;
  trigo_data->angle = 0;
  trigo_data->r_pos = 0;
  trigo_data->flags_data = data_flags;
  trigo_data->serv_data = data_server;
  trigo_data->msg = NULL;
}
