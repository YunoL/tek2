/*
** init_server.c for PSU_2016_zappy in /home/turba_d/projets/PSU_2016_zappy/server_src
**
** Made by dorian turba
** Login   <turba_d@epitech.net>
**
** Started on  Mon Jun 19 09:46:08 2017 dorian turba
** Last update Fri Jun 30 18:25:36 2017 Guillaume Roux
*/

#include "../include/server.h"
#include "../include/arg_check_server.h"
#include "../include/init_server.h"

double	timer;

void	init_data_flags(t_data_flags *data_flags)
{
  data_flags->port = 0;
  data_flags->width = 0;
  data_flags->height = 0;
  data_flags->team_names = NULL;
  data_flags->clients_nb = 0;
  data_flags->freq = DEFAULT_TIME;
}

void	run_server(t_data_server *data_server)
{
  fd_set	fd_write;
  fd_set	fd_read;
  int	fd_max;

  fd_max = get_fd_max(data_server, &fd_read, &fd_write);
  my_select(fd_max, &fd_read, &fd_write);
  my_isset(data_server, &fd_read, &fd_write);
}

int	main(int ac, char **av)
{
  t_data_server	data_server;
  t_data_flags	data_flags;
  clock_t	start_t;
  clock_t	end_t;

  start_t = clock();
  init_data_flags(&data_flags);
  if (arg_check_server(ac, av, &data_flags) == 1)
    return (1);
  else
    {
      add_server(&data_server, &data_flags);
      count_team_members(&data_server);
      while (42)
	{
	  end_t = clock();
	  timer = (double) (end_t - start_t) / CLOCKS_PER_SEC;
	  run_server(&data_server);
  }
      return (0);
    }
}
