/*
** sound_broadcast.h for PSU_2016_zappy in /home/turba_d/projets/PSU_2016_zappy/include
** 
** Made by dorian turba
** Login   <turba_d@epitech.net>
** 
** Started on  Wed Jun 21 10:47:50 2017 dorian turba
** Last update Thu Jun 22 13:22:22 2017 dorian turba
*/

#ifndef SOUND_BROADCAST_H
# define SOUND_BROADCAST_H

# include "server.h"

# define PYTH1		pyth(data->dest_x - data->src_x + width, data->dest_y - data->src_y)
# define NORTH		1
# define PYTH2		pyth(data->dest_x - data->src_x, data->dest_y - (data->src_y - height))
# define NORTHWEST	2
# define PYTH3		pyth(data->dest_x - (data->src_x - width), data->dest_y - (data->src_y - height))
# define WEST		3
# define PYTH4		pyth(data->dest_x - (data->src_x - width), data->dest_y - data->src_y)
# define SOUTHWEST	4
# define PYTH5		pyth(data->dest_x - (data->src_x - width), data->dest_y - (data->src_y + height))
# define SOUTH		5
# define PYTH6		pyth(data->dest_x - data->src_x, data->dest_y - (data->src_y + height))
# define SOUTHEST	6
# define PYTH7		pyth(data->dest_x - (data->src_x + width), data->dest_y - (data->src_y + height))
# define EST		7
# define PYTH8		pyth(data->dest_x - (data->src_x + width), data->dest_y - data->src_y)
# define NORTHEST	8
# define XOPTI		data->dest_x - (data->src_x + (x_mod * width))
# define YOPTI		data->dest_y - (data->src_y + (y_mod * height))

#endif /* !SOUND_BROADCAST_H */
