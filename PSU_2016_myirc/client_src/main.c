/*
** main.c for main in /home/guillaume2.roux/rendu/PSU_2016_myirc/client_src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Tue May 23 14:25:13 2017 Guillaume Roux
** Last update Tue Jun  6 11:03:02 2017 Guillaume Roux
*/

#include "../include/client.h"

void	my_select(int fd_max, fd_set *fd_read, fd_set *fd_write)
{
  struct timeval	tv;

  tv.tv_sec = 20;
  tv.tv_usec = 0;
  if (select(fd_max + 1, fd_read, fd_write, NULL, &tv) == -1)
    my_exit("Error : select !", EXIT_FAILURE);
}

void	run_client(int fd, t_client *client)
{
  fd_set	fd_read;
  fd_set	fd_write;

  while (1)
    {
      init_fct(&fd_read, &fd_write, fd);
      my_select(3, &fd_read, &fd_write);
      check_isset(&fd_read, &fd_write, fd, client);
    }
}

int	main()
{
  int			fd;
  t_client	*client;

  client = init_client(client);
  while (fd <= 0)
    fd = make_connect(client);
  run_client(fd, client);
  return (0);
}
