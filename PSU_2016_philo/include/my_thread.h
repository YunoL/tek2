/*
** my_thread.h for my_thread in /home/guillaume2.roux/rendu/PSU_2016_philo/include/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Thu Jul  6 09:44:12 2017 Guillaume Roux
** Last update Thu Jul  6 09:58:11 2017 Guillaume Roux
*/

#ifndef MY_THREAD_H
# define MY_THREAD_H

# include <pthread.h>

typedef enum	s_state
{
  THINK,
  REST,
  EAT
}		t_state;

typedef struct	s_mutex
{
  pthread_mutex_t	mutex;
  struct s_mutex	*next;
}		t_mutex;

typedef struct	s_philosophe
{
  t_state	state;
  int	nb_philo;
  int	rank;
  pthread_mutex_t	mutex;
  pthread_t	handler;
  struct s_philosophe *next;
}		t_philosophe;

#endif
