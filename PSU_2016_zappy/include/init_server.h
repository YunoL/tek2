/*
** init_server.h for PSU_2016_zappy in /home/turba_d/projets/PSU_2016_zappy/include
**
** Made by dorian turba
** Login   <turba_d@epitech.net>
**
** Started on  Mon Jun 19 09:41:53 2017 dorian turba
** Last update Tue Jun 27 15:32:52 2017 Guillaume Roux
*/

#ifndef INIT_SERVER_H
# define INIT_SERVER_H

# define MAX_FD 255
# define FD_FREE 0
# define FD_CLIENT 1
# define FD_SERVER 2

typedef void(*fct)();

typedef struct	s_client
{
  char		*msg;
  char		*team;
  int		linemate_carried;
  int		deraumere_carried;
  int		sibur_carried;
  int	     	mendiane_carried;
  int	     	phiras_nbr;
  int	     	thystame_nbr;
  int		life_units;
  int		fd;
  int		orientation; // 0 = N, 1 = NE, 2 = E, 3 = SE, 4 = S, 5 = SO, 6 = O, 7 = NO
  int		pos_x;
  int		pos_y;
  int		level;
}		t_client;

typedef	struct	s_data_server
{
  char		fd_type[MAX_FD];
  int		port;
  fct 		fct_read[MAX_FD];
  fct 		fct_write[MAX_FD];
  t_client	clients[MAX_FD];
  int		fd_server;
  struct s_map	*map;
  struct s_data_flags	*data_flags;
} t_data_server;

#endif /* !INIT_SERVER_H */
