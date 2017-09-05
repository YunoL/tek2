/*
** utility.c for utility in /home/guillaume2.roux/rendu/PSU_2016_myftp/src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Fri May 12 13:06:48 2017 Guillaume Roux
** Last update Thu May 18 14:28:43 2017 Guillaume Roux
*/

#include "../include/my.h"

void	my_write(int fd, char *str)
{
  if (write(fd, str, strlen(str)) == -1)
    my_exit("Error : write", EXIT_FAILURE);
}

void	my_exit(char *msg, int value)
{
  if (msg)
    fprintf(stderr, "%s\n", msg);
  exit(value);
}

void	closing(char *msg, int fd, int value)
{
  if (close(fd) == -1)
    my_exit(msg, value);
  my_exit(msg, value);
}
