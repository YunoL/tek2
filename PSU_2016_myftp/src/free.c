/*
** free.c for free in /home/guillaume2.roux/rendu/PSU_2016_myftp/src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Mon May 15 20:15:17 2017 Guillaume Roux
** Last update Mon May 15 20:16:56 2017 Guillaume Roux
*/

#include "../include/my.h"

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}
