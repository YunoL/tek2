//
// main.cpp for main in /home/guillaume2.roux/rendu/PSU_2016_zappy/ai_src/
//
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.eu>
//
// Started on  Thu Jun 15 12:09:27 2017 Guillaume Roux
// Last update Sun Jul  2 13:26:24 2017 Luc Normandon
//

#include "../include/client.hpp"
#include "../include/arg_check_client.hpp"

void	my_select(int fd_max, fd_set *fd_read, fd_set *fd_write)
{
  struct timeval	tv;

  tv.tv_sec = 20;
  tv.tv_usec = 0;
  if (select(fd_max + 1, fd_read, fd_write, NULL, &tv) == -1)
    my_exit("Error : select !", EXIT_FAILURE);
}

void	run_client(int fd, data_flags *d_flags)
{
  fd_set	fd_read;
  fd_set	fd_write;
  bool    is_playing;

  is_playing = false;
  while (1)
    {
      init_fct(&fd_read, &fd_write, fd);
      my_select(fd + 1, &fd_read, &fd_write);
	    d_flags->fd_read = fd_read;
	    d_flags->fd_write = fd_write;
      if (!is_playing)
        {
          check_isset(&fd_read, &fd_write, fd, d_flags);
          is_playing = start_playing(d_flags, fd);
        }
      else
        {
          client_playing(fd, d_flags);
        }
    }
}

int main(int ac, char **av)
{
  int fd;
  data_flags	d_flags(0, NULL);

  if (arg_check_client(ac, av, &d_flags) == 1)
    return 1;
  while (fd <= 0)
    fd = make_connect(&d_flags);
  d_flags.fd = fd;
  run_client(fd, &d_flags);
  return 0;
}
