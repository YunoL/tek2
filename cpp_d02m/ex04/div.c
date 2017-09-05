/*
** div.c for div in /home/guillaume2.roux/rendu/cpp_d02m/ex04
** 
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.net>
** 
** Started on  Thu Jan  5 10:33:34 2017 Guillaume Roux
** Last update Thu Jan  5 10:33:37 2017 Guillaume Roux
*/

#include "castmania.h"

int	integer_div(int a, int b)
{
  if (b == 0)
    return (0);
  return (a / b);
}

float	decimale_div(int a, int b)
{
  if (b == 0)
    return (0.0f);
  return ((float)a / b);
}

void	exec_div(t_div *operation)
{
  if (operation->div_type == INTEGER)
    ((t_integer_op*)operation->div_op)->res = integer_div(((t_integer_op*)operation->div_op)->a, ((t_integer_op*)operation->div_op)->b);
  else if (operation->div_type == DECIMALE)
    ((t_decimale_op*)operation->div_op)->res = integer_div(((t_decimale_op*)operation->div_op)->a, ((t_decimale_op*)operation->div_op)->b);
}
