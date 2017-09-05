/*
** my_dele.c for my_dele in /home/guillaume2.roux/rendu/PSU_2016_myftp/src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Thu May 18 19:13:49 2017 Guillaume Roux
** Last update Thu May 18 19:17:32 2017 Guillaume Roux
*/

#include "../include/my.h"

void	my_dele(client_s *my_client, char *param)
{
  if (my_client->is_root == false)
    my_write(my_client->client_fd, Msg550);
}
