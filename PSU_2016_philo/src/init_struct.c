/*
** init_struct.c for init_struct in /home/guillaume/rendu/PSU_2016_philo/src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Tue Mar 14 16:11:00 2017 Guillaume Roux
** Last update Thu Jul  6 11:01:01 2017 Guillaume Roux
*/

#include "../include/my.h"

int *g_chopsticks;

void	philo_think(t_philo *philos)
{
  g_chopsticks[philos->i] = 1;
  lphilo_take_chopstick(&chopsticks);
  pthread_mutex_unlock(&chopsticks);
  lphilo_release_chopstick(&chopsticks);
  lphilo_think();
  philos->state = THINK;
  while (philos->state != EAT)
    {
      pthread_mutex_lock(&chopsticks);
      lphilo_take_chopstick(&chopsticks);
      if (g_chopsticks[(philos->i + 1) % nb_philo] == 0)
	philo_eat(philos);
      else
	{
	  pthread_mutex_unlock(&chopsticks);
	  lphilo_release_chopstick(&chopsticks);
  }
    }
}

void	philo_eat(t_philo *philos)
{
  g_chopsticks[philos->i] = 1;
  g_chopsticks[(philos->i + 1) % nb_philo] = 1;
  pthread_mutex_unlock(&chopsticks);
  lphilo_eat();
  pthread_mutex_lock(&chopsticks);
  pthread_mutex_lock(&chopsticks2);
  lphilo_take_chopstick(&chopsticks);
  lphilo_take_chopstick(&chopsticks2);
  g_chopsticks[philos->i] = 0;
  g_chopsticks[(philos->i + 1) % nb_philo] = 0;
  philos->state = EAT;
  philos->hunger++;
  pthread_mutex_unlock(&chopsticks);
  pthread_mutex_unlock(&chopsticks2);
  lphilo_release_chopstick(&chopsticks);
  lphilo_release_chopstick(&chopsticks2);
}

void	philo_rest(t_philo *philos)
{
  pthread_mutex_unlock(&chopsticks);
  philos->state = REST;
  lphilo_sleep();
}
