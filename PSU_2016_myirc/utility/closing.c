/*
** closing.c for closing in /home/guillaume2.roux/rendu/PSU_2016_myirc/server_src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Wed May 24 10:50:15 2017 Guillaume Roux
** Last update Thu Jun  1 13:19:35 2017 Guillaume Roux
*/

#include "../include/my.h"

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

int	xstrcmp(const char *s1, const char *s2)
{
  if (!s1 || !s2)
    return (1);
  return (strcmp(s1, s2));
}
