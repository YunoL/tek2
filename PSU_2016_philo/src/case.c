/*
** case.c for case in /home/guillaume2.roux/rendu/PSU_2016_philo/src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Thu Jul  6 07:15:42 2017 Guillaume Roux
** Last update Thu Jul  6 10:23:16 2017 Guillaume Roux
*/

#include "../include/my.h"

void	case_1_philo(t_philo *philo)
{
  philo_rest(philo);
}

int	check_hunger(t_philo *philo)
{
  int	i;

  for (i = 0; i < nb_philo; i++)
    {
      if (philo[i].hunger >= max_eating)
	return (1);
    }
  return (0);
}

void	case_multiple_philo(t_philo *philo)
{
  int		left_chop;
  int		right_chop;

  while (check_hunger(philo) != 1)
    {
      pthread_mutex_lock(&chopsticks);
      left_chop = g_chopsticks[philo->i];
      right_chop = g_chopsticks[(philo->i + 1) % nb_philo];
      if (left_chop == 0 && right_chop == 0 && philo->state != EAT)
	philo_eat(philo);
      else if (left_chop == 0 && philo->state != THINK && philo->state != EAT)
	philo_think(philo);
      else
	philo_rest(philo);
    }
}
