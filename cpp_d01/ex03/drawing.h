/*
** drawing.h for drawing in /home/guillaume2.roux/rendu/cpp_d01/ex03
** 
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.net>
** 
** Started on  Wed Jan  4 12:55:21 2017 Guillaume Roux
** Last update Wed Jan  4 12:55:27 2017 Guillaume Roux
*/

#ifndef DRAWING_H_
# define DRAWING_H_

# include <string.h>
# include <stdint.h>

typedef struct s_point
{
	uint32_t	x;
	uint32_t 	y;
}			t_point;

void	draw_square(uint32_t **img, t_point *orig, size_t size, uint32_t color);

#endif /* !DRAWING_H_ */