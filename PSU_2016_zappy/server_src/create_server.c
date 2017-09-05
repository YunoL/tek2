/*
** create_server.c for create_server in /home/guillaume2.roux/rendu/PSU_2016_zappy/server_src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Tue Jun 20 11:09:55 2017 Guillaume Roux
** Last update Fri Jun 30 18:19:31 2017 Guillaume Roux
*/

#include "../include/server.h"
#include "../include/init_server.h"

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

void server_read(t_data_server *data_server, int fd)
{
  add_client(data_server, fd);
}

void	init_server(t_data_server *data_server, int fd, t_data_flags *data_flags)
{
  data_server->fd_type[fd] = FD_SERVER;
  data_server->fd_server = fd;
  data_server->fct_read[fd] = server_read;
  data_server->fct_write[fd] = NULL;
  data_server->map = xmalloc(sizeof(t_map));
  init_map(data_server->map, data_flags);
  data_server->data_flags = data_flags;
}

int	count_team(t_data_flags *data_flags)
{
  int	nb_team;
  t_team_names	*tmp;

  tmp = data_flags->team_names;
  for (nb_team = 0; tmp; tmp = tmp->next);
  return (nb_team);
}

void	add_server(t_data_server *data_server, t_data_flags *data_flags)
{
  int	fd;
  struct sockaddr_in	s_in;

  fd = create_socket();
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(data_flags->port);
  s_in.sin_addr.s_addr = INADDR_ANY;
  if (bind(fd, (struct sockaddr*)&s_in, sizeof(s_in)) == -1)
    closing(BIND_ERR, fd, EXIT_FAILURE);
  if (listen(fd, (count_team(data_flags) * data_flags->clients_nb)) == -1)
    closing(LISTEN_ERR, fd, EXIT_FAILURE);
  init_server(data_server, fd, data_flags);
}
