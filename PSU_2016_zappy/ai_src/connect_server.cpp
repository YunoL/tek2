//
// connect_server.cpp for zappy in /home/lurivar/rendu/PSU_2016_zappy/ai_src/
//
// Made by Luc Normandon
// Login   <luc.normandon@epitech.eu@epitech.eu>
//
// Started on  Thu Jun 22 11:56:20 2017 Luc Normandon
// Last update Thu Jun 22 16:30:42 2017 Luc Normandon
//

#include "../include/client.hpp"

int	make_connect(data_flags *d_flags)
{
  int	fd;
  struct protoent	*pe;
  struct sockaddr_in	s_in;

  if (!(pe = getprotobyname("TCP")))
    my_exit("Error : getprotobyname", EXIT_FAILURE);
  fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  if (fd == -1)
    closing("Error : can't create socket", fd, EXIT_FAILURE);
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(d_flags->getPort());
  s_in.sin_addr.s_addr = inet_addr(d_flags->machine.c_str());
  if (connect(fd, (struct sockaddr *) &s_in, sizeof(s_in)) ==  - 1)
    closing("Error : can't connect", fd, EXIT_FAILURE);
  d_flags->fd = fd;
  return d_flags->getfd();
}
