/*
** check_flags_server.c for check_flags_server in /home/guillaume2.roux/rendu/PSU_2016_zappy/server_src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Mon Jun 19 15:04:14 2017 Guillaume Roux
** Last update Wed Jun 28 16:10:56 2017 Guillaume Roux
*/

#include "../include/server.h"

int	is_flag(char *s)
{
  if (!s)
    return (-1);
  if (xstrcmp(s, "-p") == 0)
    return (1);
  else if (xstrcmp(s, "-x") == 0)
    return (2);
  else if (xstrcmp(s, "-y") == 0)
    return (3);
  else if (xstrcmp(s, "-n") == 0)
    return (4);
  else if (xstrcmp(s, "-c") == 0)
    return (5);
  else if (xstrcmp(s, "-f") == 0)
    return (6);
  return (0);
}

void	err_names(t_data_flags *data_flags, char *name)
{
  t_team_names	*tmp;
  int	nb;

  tmp = data_flags->team_names;
  while (tmp)
    {
      if (strcmp(tmp->name, name) == 0)
	nb++;
      tmp = tmp->next;
    }
  if (nb > 1)
    my_exit("Error : name already exist", 0);
}

void	get_names(char **av, int i, t_data_flags *data_flags)
{
  while (is_flag(av[i]) == 0)
    {
      add_name(av[i], data_flags);
      err_names(data_flags, av[i]);
      i++;
    }
}

int	get_flags_value(char **av, t_data_flags *data_flags)
{
  int	i;

  for (i = 0; av[i]; i++)
    {
      if (is_flag(av[i]) == 1)
	data_flags->port = xatoi(av[i + 1]);
      else if (is_flag(av[i]) == 2)
	data_flags->width = xatoi(av[i + 1]);
      else if (is_flag(av[i]) == 3)
	data_flags->height = xatoi(av[i + 1]);
      else if (is_flag(av[i]) == 4)
	get_names(av, i + 1, data_flags);
      else if (is_flag(av[i]) == 5)
	data_flags->clients_nb = xatoi(av[i + 1]);
      else if (is_flag(av[i]) == 6)
	data_flags->freq = xatoi(av[i + 1]);
    }
  return (check_init_value(data_flags));
}
