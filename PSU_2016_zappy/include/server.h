/*
** server.h<test> for PSU_2016_zappy in /home/turba_d/projets/PSU_2016_zappy/server_src
**
** Made by dorian turba
** Login   <turba_d@epitech.net>
**
** Started on  Mon Jun 19 09:30:50 2017 dorian turba
** Last update Fri Jun 30 18:19:52 2017 Guillaume Roux
*/

#ifndef SERVER_H
# define SERVER_H

# include <stdio.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>
# include <stdlib.h>
# include <unistd.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <string.h>
# include <time.h>
# include <math.h>
# include "cell_server.h"
# include "init_server.h"
# include "arg_check_server.h"
# include "err_server.h"
# include "sound_broadcast.h"
# include "action_time.h"
# include "manage_cmd_server.h"
# include "command_save_server.h"
# include "look_server.h"

# define DEFAULT_PORT 4242
# define DEFAULT_WIDTH 42
# define DEFAULT_HEIGHT 42
# define DEFAULT_TIME 100

# define BIND_ERR "Error : bind, can't assign address to server"
# define LISTEN_ERR "Error : listen, can't create queue"

# define REL_X_POS(x, width) ((x % width + width) % width)
# define REL_Y_POS(y, height) ((y % height + height) % height)

# define DIVIDER 2205
# define P_LINEMATE (21 / 6 * 1.4) / DIVIDER
# define P_DERAUMERE (11.5 / 6 * 1.2) / DIVIDER
# define P_SIBUR (15.5 / 6 * 1.2) / DIVIDER
# define P_MENDIANE (6.5 / 6 * 0.8) / DIVIDER
# define P_PHIRAS (10.5 / 6 * 1) / DIVIDER
# define P_THYSTAME (1 / 6 * 0.6) / DIVIDER
# define P_FOOD (7.5) / DIVIDER
# define CALC_P ((rand() % 100000) * data_flags->width * data_flags->height * nb_player)

extern double	timer;

typedef struct	s_map
{
  t_cell_server	**cell;
  int		width;
  int		height;
  int		linemate_rate;
  int		deraumere_rate;
  int		ibur_rate;
  int		mendiane_rate;
  int		phiras_rate;
  int		thystame_rate;
  int		life_units_rate;
}		t_map;

typedef struct		s_team_names
{
  char			*name;
  int	place_left;
  struct s_team_names	*next;
}			t_team_names;

typedef struct s_data_flags
{
  int		port;
  int		width;
  int		height;
  t_team_names	*team_names;
  int		clients_nb;
  int		freq;
} t_data_flags;

typedef struct	s_action
{
  double	time_start;
  double	time_end;
  t_client	*client;
  void	(*cmd_fct)(/* arg */);
  struct s_action	*next;
}		t_action;

typedef struct	s_trigo_data
{
  int		src_x;
  int		src_y;
  int		dest_x;
  int		dest_y;
  int		angle;
  int		r_pos;	// Macro pour localiser l'écran où se trouve le point le plus proche
  t_data_flags	*flags_data;
  t_data_server	*serv_data;
  char		*msg;
}		t_trigo_data;

void	init_data_flags(t_data_flags *data_flags);
void	add_name(char *name, t_data_flags *data_flags);
void	remove_name(char *name, t_data_flags *data_flags);
void	*xmalloc(int size);
int	xstrcmp(const char *s1, const char *s2);
int	xatoi(char *s);
int	get_flags_value(char **av, t_data_flags *data_flags);
void	get_names(char **av, int i, t_data_flags *data_flags);
int	is_flag(char *s);
void	closing(char *msg, int fd, int value);
void	my_exit(char *msg, int value);
void	my_select(int fd_max, fd_set *fd_read, fd_set *fd_write);
void	client_write(t_data_server *data_server, int fd);
void	client_read(t_data_server *data_server, int fd);
void	my_isset(t_data_server *data_server, fd_set *fd_read, fd_set *fd_write);
int	get_fd_max(t_data_server *data_server, fd_set *fd_read, fd_set *fd_write);
void	add_client(t_data_server *data_server, int s);
void	add_server(t_data_server *data_server, t_data_flags *data_flags);
void	client_add(t_client	*client, t_cell_server *cells);
void	print_usage();
int	arg_num_check(int ac);
int	arg_flag_check(int ac, char **av, t_data_flags *data_flags);
int	arg_check_server(int ac, char **av, t_data_flags *data_flags);
int	error(char *msg);
void	init_cell(t_cell_server *cell);
void	output_broadcast(t_trigo_data *tri_data);
int	angle_calcul(t_trigo_data *tri_data, int pos);
int	echo_from(t_trigo_data *data, int pos);
int	pyth(int a, int b);
void	make_msg(char *txt, t_client *client);
void	make_msg_pos(t_client *client, char *msg, int int_pos);
void	init_trigo_data(t_trigo_data *trigo_data, t_data_flags *data_flags, t_data_server *data_server);
char	**my_strd_to_wordtab(char *str, char *delim);
void	add_action(t_action *action, t_client *client, double timing);
void	remove_action(t_action *begin, t_action *to_del);
void	remove_client(int fd, t_cell_server *cells);
void	client_add(t_client	*client, t_cell_server *cells);
void	init_map(t_map *map, t_data_flags *data_flags);
int	check_init_value(t_data_flags *data_flags);
void	count_team_members(t_data_server *data_server);
void	pushing(int orientation, t_client *pushed_client, t_data_server *data_server);
void	obj_generation(t_data_server *data_server);
void	check_time(t_data_server *data_server);

#endif /* !SERVER_H */
