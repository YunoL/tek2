/*
** menger.c for menger in /home/guillaume2.roux/rendu/cpp_d01/ex01
** 
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.net>
** 
** Started on  Wed Jan  4 08:56:47 2017 Guillaume Roux
** Last update Wed Jan  4 09:34:26 2017 Guillaume Roux
*/

#include <stdio.h>

void	menger(int size, int lvl, int x, int y)
{
  int	i;

  i = 0;
  if (size >= 3 && lvl > 0)
    {
      size = size / 3;
      printf("%.3d %.3d %.3d\n", size, x + size, y + size);
      lvl--;
      while (i < 9)
      {
        if (i != 4)
          menger(size, lvl, (x + i / 3 * size), y + (i * size) % (size * 3));
        i++;
      }
      return;
    }
    return;
}
