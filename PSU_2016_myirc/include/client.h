/*
** client.h for client in /home/guillaume2.roux/bootstrap/PSU_2016_myirc/include/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Thu Jun  1 10:58:39 2017 Guillaume Roux
** Last update Fri Jun  9 12:12:05 2017 Guillaume Roux
*/

#ifndef CLIENT_H
# define CLIENT_H

# define CLIENT_USAGE "USAGE: ./client host port"
# define DEFAULT_PORT 6667

# include "utility.h"
# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <stdio.h>

typedef struct	s_client
{
  char		*host;
  char		*username;
  char		*nickname;
  t_channel	*channel;
  char		*msg;
  char		*to_server;
  char		*to_client;
  int			fd;
}		t_client;

t_client	*init_client(t_client *client);
void	init_fct(fd_set *fd_read, fd_set *fd_write, int fd);
void	check_isset(fd_set *fd_read, fd_set *fd_write, int fd, t_client *client);
void	check_cmd(char *buffer, t_client *client);
void	read_server(int fd, t_client *client);
void	read_input(t_client *client);
void	write_client(t_client *client);
void	write_server(int fd, t_client *client);
void	part_channel(char *channel, t_client *client, char *buffer);
void	list_users(t_client *client, char *buffer);
void	list_names(char *channel, t_client *client, char *buffer);
void	connect_server(char *arg, t_client *client);
void	make_msg(t_client *client, char *msg, int nb);
void	need_more_param(t_client *client, char *cmd);
void	too_many_chan(t_client *client, char *channel);
void	no_such_chan(t_client *client, char *channel);
void	add_channel(t_client *client, char *channel);
void	remove_channel(t_client *client, char *channel);
int	get_channel(t_client *client, char *channel);
int	make_connect(t_client *client);
void	no_nickname_given(t_client *client);
void	not_on_channel(t_client *client, char *channel);
void	disp_list(t_client *client, char *buffer);
void	private_msg(char *nickname, char *msg, t_client *client, char *buffer);
int	check_channel(char *channel);
void	disp_user(t_client *client, char *buffer);

#endif
