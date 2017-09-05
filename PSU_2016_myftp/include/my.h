/*
** my.h for my in /home/guillaume2.roux/rendu/PSU_2016_myftp/include/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Wed May 10 09:10:48 2017 John Doe
** Last update Wed May 24 10:56:51 2017 Guillaume Roux
*/

#ifndef MY_H
# define MY_H

# define USAGE "Usage : ./server port path"

# define Msg125 "125 Data connection already open; transfer starting.\n"
# define Msg150 "150 File status okay; about to open data connection.\n"
# define Msg200 "200 Command okay.\n"
# define Msg202 "202 Command not implemented, superfluous at this site.\n"
# define Msg211 "211 System status, or system help reply.\n"
# define Msg212 "212 Directory status.\n"
# define Msg213 "213 File status.\n"
# define Msg214 "214 Help message.\n"
# define Msg215 "215 NAME system type.\n"
# define Msg220 "220 Service ready for new user.\n"
# define Msg221 "221 Service closing control connection.\n"
# define Msg225 "225 Data connection open; no transfer in progress.\n"
# define Msg226 "226 Closing data connection.\n"
# define Msg227 "227 Entering Passive Mode (h1,h2,h3,h4,p1,p2).\n"
# define Msg230 "230 User logged in, proceed.\n"
# define Msg250 "250 Requested file action okay, completed.\n"
# define Msg257 "257 PATHNAME created.\n"
# define Msg331 "331 User name okay, need password.\n"
# define Msg332 "332 Need account for login.\n"
# define Msg350 "350 Requested file action pending further information.\n"
# define Msg425 "425 Can't open data connection.\n"
# define Msg450 "450 Requested file action not taken.\n"
# define Msg500 "500 Unknown command.\n"
# define Msg501 "501 Syntax error in parameters or arguments.\n"
# define Msg502 "502 Command not implemented.\n"
# define Msg503 "503 Bad sequence of commands.\n"
# define Msg504 "504 Command not implemented for that parameter.\n"
# define Msg530 "530 Not logged in.\n"
# define Msg550 "550 Requested action not taken.\n"

# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <dirent.h>
# include <netinet/in.h>
# include <arpa/inet.h>

typedef int bool;
# define true 1
# define false 0

extern char	*home_dir;
extern int addr_port[6];
extern bool	user_value;
extern bool pass_value;

typedef struct client_s
{
  int	client_fd;
  int	transf_mode;
  bool	is_co;
  bool	is_root;
}client_s;

void	my_exit(char *msg, int value);
void	closing(char *msg, int fd, int value);
void	my_write(int fd, char *str);
char	*get_next_line(const int fd);
int		create_socket();
void	manage_client(int client_fd);
int	execute(client_s *my_client);
int	strcicmp(char const *a, char const *b, int i);
void	check_user(char *buffer, int client_fd);
void	check_pass(char *buffer, int client_fd);
void	free_tab(char **tab);
void	identification(client_s *my_client);
void	my_quit(client_s *my_client);
void	my_pwd(int client_fd);
void	my_list(char *pathname, client_s *my_client);
char	**my_strd_to_wordtab(char *str, char *delim);
void	my_pasv(client_s *my_client);
void	check_dir();
void	my_type(char *cmd, client_s *my_client);
void	my_port(client_s *my_client, char *cmd);
void	my_dele(client_s *my_client, char *param);
void	my_help(client_s *my_client);
void	my_stor(client_s *my_client, char *param);
void	my_retr(client_s *my_client, char *param);

#endif
