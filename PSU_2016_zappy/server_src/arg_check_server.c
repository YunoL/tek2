/*
** arg_check_server.c for PSU_2016_zappy in /home/turba_d/projets/PSU_2016_zappy/server_src
**
** Made by dorian turba
** Login   <turba_d@epitech.net>
**
** Started on  Mon Jun 19 10:28:20 2017 dorian turba
** Last update Fri Jun 30 18:13:06 2017 Guillaume Roux
*/

#include "../include/arg_check_server.h"
#include "../include/err_server.h"
#include "../include/server.h"

void	print_usage()
{
  dprintf(1, "%s", USAGE);
  return;
}

int	arg_num_check(int ac)
{
  if (ac == 1)
    return (error(INV_NBR_ARG));
  else
    return (0);
}

int	arg_flag_check(int ac, char **av, t_data_flags *data_flags)
{
  if (ac == 2 && (strcmp(av[1], "-help") == 0 || strcmp(av[1], "-h") == 0))
    {
      print_usage();
      return (1);
    }
  else
    {
      if (get_flags_value(av, data_flags) == 1)
	return (1);
    }
  return (0);
}

int	check_init_value(t_data_flags *data_flags)
{
  if (data_flags->port == 0 || data_flags->width <= 0
      || data_flags->height <= 0 || data_flags->clients_nb <= 0)
    return (1);
  return (0);
}

int	arg_check_server(int ac, char **av, t_data_flags *data_flags)
{
  if (arg_num_check(ac) == 1)
    return (1);
  if (arg_flag_check(ac, av, data_flags) == 1)
    return (1);
  return (0);
}
