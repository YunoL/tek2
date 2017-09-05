/*
** main.c for main in /home/guillaume/rendu/PSU_2016_philo/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Wed Mar  8 12:53:12 2017 Guillaume Roux
** Last update Thu Jul  6 10:59:33 2017 Guillaume Roux
*/

#include "../include/my.h"
int	max_eating;
int	nb_philo;

void	print_usage(char **av)
{
  if (strcmp(av[1], "-h") == 0)
    fprintf(stderr, "USAGE:\t%s -p nb_philo -e max_eat\n", av[0]);
}

int	check_param(char **av)
{
  if (strcmp(av[1], "-p") != 0 || atoi(av[2]) == 0 || strcmp(av[3], "-e") != 0)
    return (1);
  else if (atoi(av[4]) == 0)
    return (1);
  return (0);
}

int	main(int ac, char **av)
{
  if (ac == 5 && check_param(av) == 0)
    {
      RCFStartup(ac, av);
      nb_philo = atoi(av[2]);
      max_eating = atoi(av[4]);
      philo_create();
      RCFCleanup();
    }
  if (ac == 2)
    print_usage(av);
  else if (check_param(av) == 1)
    fputs("Error : Bad parameters!\n", stderr);
  return (0);
}
