/*
** check_dir.c for check_dir in /home/guillaume2.roux/rendu/PSU_2016_myftp/src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Tue May 16 16:48:09 2017 Guillaume Roux
** Last update Fri May 19 13:14:34 2017 Guillaume Roux
*/

#include "../include/my.h"

char	*home_dir;

void	check_dir()
{
  if (chdir(home_dir) == -1)
    my_exit("Error : can't access directory", EXIT_FAILURE);
}
