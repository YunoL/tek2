/*
** my_help.c for my_help in /home/guillaume2.roux/rendu/PSU_2016_myftp/src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Thu May 18 19:20:24 2017 Guillaume Roux
** Last update Thu May 18 19:33:04 2017 Guillaume Roux
*/

#include "../include/my.h"

void	my_help(client_s *my_client)
{
  my_write(my_client->client_fd, " CDUP CWD DELE LIST NOOP PASS PASV PORT ");
  my_write(my_client->client_fd, "PWD QUIT RETR STOR USER\n");
  my_write(my_client->client_fd, Msg214);
}
