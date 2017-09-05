/*
** main.c for main in /home/guillaume2.roux/rendu/PSU_2016_myirc/server_src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Tue May 23 14:22:57 2017 Guillaume Roux
** Last update Tue Jun  6 17:32:28 2017 Guillaume Roux
*/

#include "../include/my.h"

int	get_fd_max(t_env *e, fd_set *fd_read, fd_set *fd_write)
{
  int	fd_max;
  int	i;

  FD_ZERO(fd_read);
  FD_ZERO(fd_write);
  fd_max = 0;
  for (i = 0; i < MAX_FD; i++)
    {
      if (e->fd_type[i] != FD_FREE)
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

void	my_isset(t_env *e, fd_set *fd_read, fd_set *fd_write)
{
  int	i;

  for (i = 0; i < MAX_FD; i++)
    {
      if (FD_ISSET(i, fd_read))
	e->fct_read[i](e, i);
      else if (FD_ISSET(i, fd_write))
	e->fct_write[i](e, i);
    }
}

int	main(int ac, char **av)
{
  int	fd_max;
  fd_set	fd_read;
  fd_set	fd_write;
  t_env	*e;

  if (ac != 2 || strcmp(av[1], "--help") == 0)
    my_exit(SRV_USAGE, EXIT_FAILURE);
  if ((e = malloc(sizeof(t_env))) == NULL)
    my_exit("Error : malloc !", EXIT_FAILURE);
  if (atoi(av[1]) > INT_MAX || atoi(av[1]) <= 0)
      my_exit("Error : Your port must be a valid number !", EXIT_FAILURE);
  e->port = atoi(av[1]);
  add_server(e);
  while (42)
    {
      fd_max = get_fd_max(e, &fd_read, &fd_write);
      my_select(fd_max, &fd_read, &fd_write);
      my_isset(e, &fd_read, &fd_write);
    }
  return (0);
}
