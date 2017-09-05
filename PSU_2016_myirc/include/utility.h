/*
** utility.h for utility in /home/guillaume2.roux/bootstrap/PSU_2016_myirc/include/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Thu Jun  1 11:00:26 2017 Guillaume Roux
** Last update Fri Jun  9 12:25:56 2017 Guillaume Roux
*/

#ifndef UTILITY_H
# define UTILITY_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>

# define USER_MSG "001 NICK: connected"

// nick messages
# define ERR_NONICKNAMEGIVEN "No nickname given"
# define ERR_ERRONEUSNICKNAME "432 <nick> :Erroneus nickname"
# define ERR_NICKNAMEINUSE "Nickname is already in use"
# define ERR_NICKCOLLISION "436 <nick> :Nickname collision KILL"

// join messages
# define ERR_NEEDMOREPARAMS "Not enough parameters"
# define ERR_CHANNELISFULL "471 <channel> :Cannot join channel (+l)"
# define ERR_NOSUCHCHANNEL "No such channel"
# define RPL_TOPIC "Welcome in the channel"
# define ERR_TOOMANYCHANNELS "You have joined too many channels"

// part messages
# define ERR_NOTONCHANNEL "You're not on that channel"

// server messages
# define ERR_NOSUCHSERVER "402 <server name> :No such server"

// msg messages
# define ERR_NORECIPIENT "441 No recipient given"
# define ERR_NOSUCHNICK "No such nick/channel"
# define ERR_NOTEXTTOSEND "No text to send"

// users messages
# define RPL_USERSSTART "392 :UserID Terminal Host"
# define RPL_NOUSERS "395 :Nobody logged in"
# define RPL_USERS "393"
# define RPL_ENDOFUSERS "394 :End of users"

// names messages
# define RPL_NAMREPLY "353 <channel> :<nick>"
# define RPL_ENDOFNAMES "366 <channel> :End of /NAMES list"

// list messages
# define RPL_LISTSTART "321 Channel :Users Name"
# define RPL_LIST "322 <channel> <# visible> :<topic>"
# define RPL_LISTEND "323 :End of /LIST"

// server messages
# define ERR_ALREADYREGISTRED "462 :You may not reregister\n"

# define FD_FREE 0
# define FD_CLIENT 1
# define FD_SERVER 2
# define MAX_FD 255
# define MAX_LEN_NAME 9
# define MAX_LEN_CHANNEL 200
# define MAX_READ 512

typedef struct	s_circ_buff
{
  uint8_t *	const	buffer;
  int	head;
  int	tail;
  int	max_len;
  size_t	size;
}		t_circ_buff;

typedef struct	s_channel
{
  char	*name;
  struct s_channel	*next;
}		t_channel;

void	my_puterr(char *str);
char	*get_next_line(const int fd);
void	my_exit(char *msg, int value);
void	closing(char *msg, int fd, int value);
char	**my_strd_to_wordtab(char *str, char *delim);
int	xstrcmp(const char *s1, const char *s2);
int	circ_buff_push(t_circ_buff *c, uint8_t data);
int	circ_buff_pop(t_circ_buff *c, uint8_t *data);
int	xatoi(const char *str);
char	*xstrcat(char *s1, char *s2);

#endif
