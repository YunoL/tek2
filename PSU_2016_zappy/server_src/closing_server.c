/*
** closing_server.c for closing_server in /home/guillaume2.roux/rendu/PSU_2016_zappy/server_src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Tue Jun 20 11:52:09 2017 Guillaume Roux
** Last update Tue Jun 20 11:52:39 2017 Guillaume Roux
*/

#include "../include/server.h"

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
