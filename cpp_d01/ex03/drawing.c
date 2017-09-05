/*
** drawing.c for drawing in /home/guillaume2.roux/rendu/cpp_d01/ex03
** 
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.net>
** 
** Started on  Wed Jan  4 13:00:36 2017 Guillaume Roux
** Last update Wed Jan  4 13:00:46 2017 Guillaume Roux
*/

#include "drawing.h"

void	draw_square(uint32_t **img, t_point *orig, size_t size, uint32_t color)
{
	size_t	y;
	size_t	x;

	for (y = orig->y; y < orig->y + size; ++y)
	{
		for (x = orig->x; x < orig->x + size; ++x)
			img[y][x] = color;
	}
}