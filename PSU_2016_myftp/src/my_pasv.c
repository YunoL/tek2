/*
** my_pasv.c for my_pasv in /home/guillaume2.roux/rendu/PSU_2016_myftp/src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Tue May 16 16:32:40 2017 Guillaume Roux
** Last update Fri May 19 11:06:50 2017 Guillaume Roux
*/

#include "../include/my.h"

int	addr_port[6];

void	my_pasv(client_s *my_client)
{
  my_client->transf_mode = 1;
  my_write(my_client->client_fd, Msg227);
}
