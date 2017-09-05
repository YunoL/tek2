/*
** client.h for client in /home/guillaume2.roux/rendu/PSU_2016_zappy/include/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Thu Jun 15 11:38:47 2017 Guillaume Roux
** Last update Sun Jul  2 13:14:24 2017 Luc Normandon
*/

#ifndef CLIENT_HPP_
# define CLIENT_HPP_

# include <iostream>
# include <cstring>
# include <string>
# include <string.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>

class data_flags
{
public:
					data_flags(int p, char *n);
					data_flags(int p, char *n, std::string m);
					~data_flags();

	int						getPort();
	int						getfd();
	std::string		getName();
	std::string		getMachine();

	int						port;
	int						fd;
	std::string		machine;
	char					*name;
	char					*to_server;
	char					*to_client;

	int						level;

	int						food;
	int						foodprio;

	int						linemate;
	int						linemateprio;

	int						deraumere;
	int						deraumereprio;

	int						sibur;
	int						siburprio;

	int						phiras;
	int						phirasprio;

	int						mendiane;
	int						mendianeprio;

	int						thystame;
	int						thystameprio;

	fd_set				fd_read;
	fd_set				fd_write;

	std::string		obj_to_take;
	int						tile_to_go;
};

void 	my_exit(std::string str, int val);
void 	closing(std::string str, int fd, int val);
int	 	xatoi(const std::string str);
void	init_fct(fd_set *fd_read, fd_set *fd_write, int fd);
void	check_isset(fd_set *fd_read, fd_set *fd_write, int fd, data_flags *d_flags);
int		make_connect(data_flags *d_flags);
bool  start_playing(data_flags *d_flags, int fd);
void	write_server(int fd, data_flags *d_flags);
void	write_client(data_flags *d_flags);
void	read_server(int fd, data_flags *d_flags);
void  client_playing(int fd, data_flags *client);
void 	send_cmd(data_flags *client);
void 	check_answer(data_flags *client);
void	look_around(data_flags *client);
void	check_ckwa(data_flags *client, char *cmd, char *obj);
void	add_obj(data_flags *client, char obj);
char 	**my_strd_to_wordtab(char *str, char *delim);
void	look_prio(data_flags *client);
void 	goto_obj(data_flags *client);
void 	go_random(data_flags *client);
void advance(data_flags *client, int i);
void	taken_two(data_flags *client);

#endif
