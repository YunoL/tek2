/*
** philosopher.c for philosopher in /home/guillaume/rendu/PSU_2016_philo/src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Mon Mar 13 14:42:10 2017 Guillaume Roux
** Last update Thu Jul  6 14:24:46 2017 Guillaume Roux
*/

#include "../include/my.h"
pthread_mutex_t	chopsticks;
pthread_mutex_t	chopsticks2;
static pthread_mutex_t	tmp;

void	do_all()
{
  lphilo_sleep();
  pthread_mutex_lock(&chopsticks);
  lphilo_take_chopstick(&chopsticks);
  lphilo_release_chopstick(&chopsticks);
  pthread_mutex_unlock(&chopsticks);
  pthread_mutex_lock(&chopsticks2);
  lphilo_take_chopstick(&chopsticks2);
  lphilo_release_chopstick(&chopsticks2);
  pthread_mutex_unlock(&chopsticks2);
  lphilo_think();
  lphilo_eat();
}

void		*run_philo(void *arg)
{
  int	i;
  int	k;

  k = atoi(arg);
  pthread_mutex_lock(&tmp);
  for (i = 0; i < (max_eating - k); i++)
    do_all();
  pthread_mutex_unlock(&tmp);
  return (0);
}
