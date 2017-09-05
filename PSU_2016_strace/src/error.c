/*
** error.c for error in /home/guillaume2.roux/rendu/PSU_2016_strace/src/
**
** Made by guillaume2.roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Tue Apr 11 16:03:29 2017 guillaume2.roux
** Last update Tue Apr 11 16:04:38 2017 guillaume2.roux
*/

#include "../include/my.h"

void	my_puterr(char *str)
{
  fprintf(stderr, "%s", str);
  exit(0);
}
