/*
** look_server.h for PSU_2016_zappy in /home/turba_d/projets/PSU_2016_zappy/server_src
** 
** Made by dorian turba
** Login   <turba_d@epitech.net>
** 
** Started on  Wed Jun 28 12:37:06 2017 dorian turba
** Last update Fri Jun 30 13:19:11 2017 dorian turba
*/

#ifndef LOOK_SERVER_H
# define LOOK_SERVER_H

# define CALC_FOR_LOOK_X ((lk.o == 0) * rk) - (lk.o == 6) * lk.level + ((lk.o == 4) * -rk) + (lk.o == 2) * lk.level
# define CALC_FOR_LOOK_Y -(lk.o == 0) * lk.level + ((lk.o == 2) * -rk) + (lk.o == 4) * lk.level + ((lk.o == 6) * rk)

typedef struct	s_look
{
  int		o;
  int		level;
  int		width;
  int		height;
}		t_look;

#endif /* !LOOK_SERVER_H */
