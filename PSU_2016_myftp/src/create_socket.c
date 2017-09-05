/*
** create_socket.c for create_socket in /home/guillaume2.roux/rendu/PSU_2016_myftp/src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Mon May 15 11:24:12 2017 Guillaume Roux
** Last update Thu May 18 16:01:13 2017 Guillaume Roux
*/

#include "../include/my.h"

int			create_socket()
{
  struct protoent	*proto;
  int			s;

  if ((proto = getprotobyname("TCP")) == NULL)
    my_exit("Error : can't create socket", EXIT_FAILURE);
  if ((s = socket(AF_INET, SOCK_STREAM, proto->p_proto)) == -1)
    my_exit("Error : can't create socket", EXIT_FAILURE);
  return (s);
}
