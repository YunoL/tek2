/*
** white_rabbit.c for white_rabbit in /home/guillaume2.roux/rendu/cpp_d01/ex00
** 
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.net>
** 
** Started on  Wed Jan  4 08:10:38 2017 Guillaume Roux
** Last update Wed Jan  4 08:51:33 2017 Guillaume Roux
*/

#include <stdio.h>
#include <stdlib.h>

int	follow_the_white_rabbit(void)
{
  int	j;
  int	sum;

  sum = 0;
  while (42)
    {
      j = rand() % 37 + 1;
      if (j == 10 || j == 15 || j == 23)
	printf("devant\n");
      else if ((j >= 4 && j <= 6) || (j >= 17 && j <= 21) || j == 28)
	printf("gauche\n");
      else if (j == 8 || j == 16 || j == 26 || j == 32 || j == 40)
	printf("derriere\n");
      else if (j == 13 || j == 34 || j == 35 || j == 36 || j == 38 || j == 39)
	printf("droite\n");
      sum += j;
      if (j == 1 || j == 37 || sum >= 397)
	{
	  printf("LAPIN !!!\n");
	  return (sum);
	}
    }
  return (sum);
}