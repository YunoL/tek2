/*
** create_philo.c for creation_philo in /home/guillaume2.roux/rendu/PSU_2016_philo/src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Thu Jul  6 10:35:27 2017 Guillaume Roux
** Last update Thu Jul  6 14:58:03 2017 Guillaume Roux
*/

#include "../include/my.h"

void philo_create()
{
  pthread_t	id;
  int	i;

  id = 0;
  pthread_create(&id, NULL, &run_philo, "0");
  usleep(1);
  id = 1;
  for (i = 1; i < nb_philo; i++)
    {
      pthread_create(&id, NULL, &run_philo, "1");
      usleep(10000);
      id++;
    }
}
