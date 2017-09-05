/*
** quit.c for quit in /home/guillaume2.roux/rendu/PSU_2016_myftp/src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Tue May 16 11:01:54 2017 Guillaume Roux
** Last update Fri May 19 11:52:37 2017 Guillaume Roux
*/

#include "../include/my.h"

void	my_quit(client_s *my_client)
{
  my_write(my_client->client_fd, Msg221);
  my_client->is_co = false;
}
