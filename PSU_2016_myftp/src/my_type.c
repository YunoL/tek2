/*
** my_type.c for my_type in /home/guillaume2.roux/rendu/PSU_2016_myftp/src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Thu May 18 16:58:44 2017 Guillaume Roux
** Last update Thu May 18 17:00:11 2017 Guillaume Roux
*/

#include "../include/my.h"

void	my_type(char *cmd, client_s *my_client)
{
  my_write(my_client->client_fd, Msg200);
}
