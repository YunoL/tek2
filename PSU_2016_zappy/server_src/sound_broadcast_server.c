/*
** sound_broadcast_server.c for PSU_2016_zappy in /home/turba_d/projets/PSU_2016_zappy/server_src
**
** Made by dorian turba
** Login   <turba_d@epitech.net>
**
** Started on  Wed Jun 21 10:45:32 2017 dorian turba
** Last update Fri Jun 23 13:07:30 2017 dorian turba
*/

#include "../include/server.h"

int	pyth(int a, int b)
{
  return (sqrt(pow(a, 2) + pow(b, 2)));
}

int	echo_from(t_trigo_data *data, int pos)
{
  int	d;
  int	width;
  int	height;
  int	tmp;

  ((width = data->flags_data->width) && (height = data->flags_data->height));
  d = pyth(data->dest_x - data->src_x, data->dest_y - data->src_y);
  if ((tmp = PYTH1) < d)
    ((d = tmp) && (pos = NORTH));
  if ((tmp = PYTH2) < d)
    ((d = tmp) && (pos = NORTHWEST));
  if ((tmp = PYTH3) < d)
    ((d = tmp) && (pos = WEST));
  if ((tmp = PYTH4) < d)
    ((d = tmp) && (pos = SOUTHWEST));
  if ((tmp = PYTH5) < d)
    ((d = tmp) && (pos = SOUTH));
  if ((tmp = PYTH6) < d)
    ((d = tmp) && (pos = SOUTHEST));
  if ((tmp = PYTH7) < d)
    ((d = tmp) && (pos = EST));
  if ((tmp = PYTH8) < d)
    ((d = tmp) && (pos = NORTHEST));
  return (pos); // quel écran est plus proche
}

int		angle_calcul(t_trigo_data *data, int pos)
{
  int		x_mod;
  int		y_mod;
  int		hypo;
  double	cos;
  int		width;
  int		height;

  ((width = data->flags_data->width) && (height = data->flags_data->height));
  x_mod =((pos > 1 && pos < 5) ? (4) : ((pos > 5) ? (2) : (3)));
  y_mod =((pos < 3 || pos > 7) ? (1) : ((pos > 3 && pos < 7) ? (3) : (2)));
  hypo = pyth(XOPTI, YOPTI);
  cos = hypo / YOPTI;
  cos = (cos * (180/M_PI)) * (-x_mod);
  return (((cos > -45 && cos < 45) ? (1) :
	   ((cos == -45) ? (2) :
	    ((cos < -45 && cos > -135) ? (3) :
	     ((cos == -135) ? (4) :
	      ((cos < -135 || cos > 135) ? (5) :
	       ((cos == 135) ? (6) :
		((cos > 45 && cos < 135) ? (7) : (8)))))))));
}

void	output_broadcast(t_trigo_data *tri_data)
{
  int	i;
  int	int_pos;

  for	(i = -1; i < MAX_FD; ++i)
    {
      if (tri_data->serv_data->fd_type[i] == FD_CLIENT)
	{
	  tri_data->dest_x = tri_data->serv_data->clients[i].pos_x;
	  tri_data->dest_y = tri_data->serv_data->clients[i].pos_y;
	  int_pos = echo_from(tri_data, 0);
	  int_pos = angle_calcul(tri_data, int_pos);// calcul d'angle
	      if (int_pos == 0)
		make_msg_pos(&(tri_data->serv_data->clients[i]), tri_data->msg, int_pos);
	  else
	    {
	      int_pos = int_pos - tri_data->serv_data->clients[i].orientation;
	      make_msg_pos(&(tri_data->serv_data->clients[i]), tri_data->msg, int_pos);
	    }
	}
    }
}
