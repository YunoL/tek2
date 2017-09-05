/*
** my.h for my.h in /home/guillaume/rendu/PSU_2016_philo/include/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Mon Mar 13 12:17:35 2017 Guillaume Roux
** Last update Thu Jul  6 10:48:42 2017 Guillaume Roux
*/

#ifndef MY_H_
# define MY_H_

# include "extern.h"
# include "my_thread.h"
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define MAX_PHILO 1000

typedef struct 	s_philo
{
  int						i;
  int						nb_chopstick;
  int						hunger;
  t_state				state;
  pthread_t			handler;
  pthread_mutex_t	mutex;
}								t_philo;

extern pthread_mutex_t	chopsticks;
extern pthread_mutex_t	chopsticks2;
extern t_philo					*philos;
extern int							*g_chopsticks;
extern int							max_eating;
extern int 							nb_philo;

void	init_philo();
void	init_struct(t_philo* philos, int i);
void	*run_philo(void *arg);
void	philo_think(t_philo *philos);
void 	philo_eat(t_philo *philos);
void	philo_rest(t_philo *philos);
int		check_hunger(t_philo *philos);
void	case_multiple_philo(t_philo *philo);
void	case_1_philo(t_philo *philo);
void philo_create();

#endif
