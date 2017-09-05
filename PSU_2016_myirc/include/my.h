/*
** my.h for my in /home/guillaume2.roux/rendu/PSU_2016_myirc/include/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Tue May 23 14:21:30 2017 Guillaume Roux
** Last update Sun Jun 11 16:05:53 2017 Guillaume Roux
*/

#ifndef MY_H_
# define MY_H_

# define SRV_USAGE "USAGE: ./server port"

# include <time.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <sys/time.h>
# include <limits.h>
# include <netdb.h>
# include <ctype.h>
# include <dirent.h>
# include <ctype.h>
# include "utility.h"

typedef void(*fct)();

typedef struct	s_client
{
  char		*host;
  char		*username;
  char		*nickname;
  t_channel	*channel;
  char		*msg;
}		t_client;

typedef struct	s_env
{
  char		fd_type[MAX_FD];
  fct 		fct_read[MAX_FD];
  fct 		fct_write[MAX_FD];
  int 		port;
  int			fds[MAX_FD];
  t_client	clients[MAX_FD];
  t_channel	*channel_list;
}		t_env;

void	my_exit(char *str, int value);
void	add_server(t_env *e);
int	create_socket();
void	closing(char *msg, int fd, int value);
void add_client(t_env *e, int s);
void	client_write(t_env *e, int fd);
void client_read(t_env *e, int fd);
char	*get_next_line(const int fd);
t_client	*init_client(t_client *client);
void	init_fct(fd_set *fd_read, fd_set *write, int fd);
void	check_cmd(char *buffer, t_env *e, int fd);
void	part_channel(char *channel, t_env *e, int fd);
void	list_users(t_env *e, int fd);
void	list_names(char *channel, t_env *e, int fd);
void	remove_channel(t_env *e, char *channel, int fd);
void	add_channel(t_env *e, char *channel, int fd);
int	channel_in_list(t_channel *fd_chan, t_channel *i_chan);
int	get_channel(t_env *e, char *channel, int fd);
int	already_there(t_env *e, char *channel);
void	add_in_list(t_env *e, char *channel);
void	disp_list(char *str, t_env *e, int fd);
void	send_private_msg(char *nickname, char **tab, t_env *e, int fd);
void	send_msg(t_env *e, int fd, char *msg);
void	disp_user(t_env *e, int fd, char *buffer);
int	check_cmd2(t_env *e, char *buffer, int fd);
void	join_channel(char *channel, t_env *e, int fd);
void	change_nick(char *nickname, t_env *e, int fd);
int	is_separator(char c);
int	is_maj(char *line);
char	*make_cmd(char **tab, int pos);
int	is_a_cmd(char *line);
void	msg_for(t_env *e, int fd, char *msg, char *nickname);
void	send_all_channel(t_env *e, int fd, char *msg);

#endif
