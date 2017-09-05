/*
** add.c for add in /home/guillaume2.roux/rendu/cpp_d02m/ex04
** 
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.net>
** 
** Started on  Thu Jan  5 10:33:52 2017 Guillaume Roux
** Last update Thu Jan  5 10:33:54 2017 Guillaume Roux
*/

#include "castmania.h"
#include <math.h>

int	normal_add(int a, int b)
{
  return (a + b);
}

int	absolute_add(int a, int b)
{
  return (fabs(a) + fabs(b));
}

void	exec_add(t_add *operation)
{
  if(operation->add_type == NORMAL)
    operation->add_op.res = normal_add(operation->add_op.a, operation->add_op.b);
  else if (operation->add_type == ABSOLUTE)
    operation->add_op.res = absolute_add(operation->add_op.a, operation->add_op.b);
}
