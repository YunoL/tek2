/*
** tab_to_2dtab.c for tab_to_2dtab in /home/guillaume2.roux/rendu/cpp_d02m/ex02
** 
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.net>
** 
** Started on  Thu Jan  5 08:43:21 2017 Guillaume Roux
** Last update Thu Jan  5 08:43:37 2017 Guillaume Roux
*/

#include <stdlib.h>

void tab_to_2dtab(int *tab, int length, int width, int ***res)
{
	int	i;
	int	j;

	i = 0;
	*res = malloc(length * sizeof(int *));
	while (i < length)
	{
		j = 0;
		(*res)[i] = malloc(width * sizeof(int));
		while (j < width)
		{
			(*res)[i][j] = tab[i * width + j];
			j++;
		}
		i++;
	}
}