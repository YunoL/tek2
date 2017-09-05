/*
** server.c for server in /home/guillaume2.roux/rendu/PSU_2016_myirc/server_src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Wed May 24 10:39:49 2017 Guillaume Roux
** Last update Fri Jun  9 12:18:26 2017 Guillaume Roux
*/

#include "../include/my.h"

int	create_socket()
{
  struct protoent	*proto;
  int			s;

  if ((proto = getprotobyname("TCP")) == NULL)
    my_exit("Error : can't create socket", EXIT_FAILURE);
  if ((s = socket(AF_INET, SOCK_STREAM, proto->p_proto)) == -1)
    my_exit("Error : can't create socket", EXIT_FAILURE);
  return (s);
}

void server_read(t_env *e, int fd)
{
  add_client(e, fd);
}

void	init_server(t_env *e, int fd)
{
  e->fd_type[fd] = FD_SERVER;
  e->fct_read[fd] = server_read;
  e->fct_write[fd] = NULL;
  e->fds[fd] = fd;
  e->channel_list = NULL;
}

void	add_server(t_env *e)
{
  int	fd;
  struct sockaddr_in	s_in;

  fd = create_socket();
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(e->port);
  s_in.sin_addr.s_addr = INADDR_ANY;
  if (bind(fd, (struct sockaddr*)&s_in, sizeof(s_in)) == -1)
    closing("Error : bind, can't assign address to server", fd, EXIT_FAILURE);
  if (listen(fd, 42) == -1)
    closing("Error : listen, can't create queue", fd, EXIT_FAILURE);
  e->clients->host = inet_ntoa(s_in.sin_addr);
  init_server(e, fd);
}
