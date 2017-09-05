/*
** free.c for free in /home/guillaume2.roux/rendu/PSU_2016_strace/src/
**
** Made by guillaume2.roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Thu Apr 13 17:09:43 2017 guillaume2.roux
** Last update Thu Apr 13 17:16:50 2017 guillaume2.roux
*/

#include "../include/my.h"

void	free_tab(char ***tab)
{
  int	i;
  char	**tmp;

  tmp = *tab;
  for (i = 0; tmp[i]; i++)
    free(tmp[i]);
  free(tmp);
  *tab = (char**)0;
}
