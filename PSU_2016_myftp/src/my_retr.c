/*
** my_retr.c for my_retr in /home/guillaume2.roux/rendu/PSU_2016_myftp/src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Thu May 18 20:29:40 2017 Guillaume Roux
** Last update Thu May 18 20:33:04 2017 Guillaume Roux
*/

#include "../include/my.h"

void	my_retr(client_s *my_client, char *param)
{
  (void)param;
  if (my_client->transf_mode > 0)
    my_write(my_client->client_fd, Msg125);
  else
    my_write(my_client->client_fd, Msg425);
}
