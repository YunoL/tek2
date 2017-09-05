/*
** my_select_server.c for my_select_server.c in /home/guillaume2.roux/rendu/PSU_2016_zappy/server_src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Tue Jun 20 11:56:18 2017 Guillaume Roux
** Last update Tue Jun 20 11:59:04 2017 Guillaume Roux
*/

#include "../include/server.h"
#include "../include/init_server.h"

int	get_fd_max(t_data_server *data_server, fd_set *fd_read, fd_set *fd_write)
{
  int	fd_max;
  int	i;

  FD_ZERO(fd_read);
  FD_ZERO(fd_write);
  fd_max = 0;
  for (i = 0; i < MAX_FD; i++)
    {
      if (data_server->fd_type[i] != FD_FREE)
	{
	  FD_SET(i, fd_read);
	  FD_SET(i, fd_write);
	  fd_max = i;
	}
    }
  return (fd_max);
}

void	my_select(int fd_max, fd_set *fd_read, fd_set *fd_write)
{
  struct timeval	tv;

  tv.tv_sec = 20;
  tv.tv_usec = 0;
  if (select(fd_max + 1, fd_read, fd_write, NULL, &tv) == -1)
    my_exit("Error : select !", EXIT_FAILURE);
}

void	my_isset(t_data_server *data_server, fd_set *fd_read, fd_set *fd_write)
{
  int	i;

  for (i = 0; i < MAX_FD; i++)
    {
      if (FD_ISSET(i, fd_read))
	data_server->fct_read[i](data_server, i);
      else if (FD_ISSET(i, fd_write))
	data_server->fct_write[i](data_server, i);
    }
}
