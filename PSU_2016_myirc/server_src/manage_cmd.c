/*
** manage_cmd.c for manage_cmd in /home/guillaume2.roux/bootstrap/PSU_2016_myirc/server_src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Thu Jun  1 12:59:49 2017 Guillaume Roux
** Last update Mon Jun 19 10:51:42 2017 Guillaume Roux
*/

#include "../include/my.h"

void	join_channel(char *channel, t_env *e, int fd)
{
  char	*msg;

  msg = malloc(sizeof(char) * 4096);
  if (!channel)
    return;
  if (get_channel(e, channel, fd) != 0)
    add_channel(e, channel, fd);
  if (already_there(e, channel) != 0)
    add_in_list(e, channel);
  sprintf(msg, ":%s JOIN %s", e->clients[fd].nickname, channel);
  e->clients[fd].msg = strdup(msg);
  free(msg);
}

void	change_nick(char *nickname, t_env *e, int fd)
{
  int	i;
  char	*msg;

  if (!nickname)
    return;
  msg = malloc(sizeof(char) * 4096);
  for (i = 0; i < MAX_FD; i++)
    {
      if (xstrcmp(e->clients[i].nickname, nickname) == 0)
	{
	  sprintf(msg, "433 %s :%s", nickname, ERR_NICKNAMEINUSE);
	  e->clients[fd].msg = strdup(msg);
	  free(msg);
	  return;
	}
    }
  sprintf(msg, ":%s is now known as %s", e->clients[fd].nickname, nickname);
  e->clients[fd].nickname = strdup(nickname);
  free(msg);
}

void	server_cmd(char *buffer, t_env *e, int fd)
{
  char	**tab;

  tab = my_strd_to_wordtab(buffer, " ");
  if (tab[0] && strncmp(tab[0], "/join", 5) == 0)
    join_channel(tab[1], e, fd);
  else if (tab[0] && strncmp(tab[0], "/nick", 5) == 0)
    change_nick(tab[1], e, fd);
  else if (tab[0] && strncmp(tab[0], "/part", 5) == 0)
    part_channel(tab[1], e, fd);
  else if (tab[0] && strncmp(tab[0], "/users", 6) == 0)
    list_users(e, fd);
  else if (tab[0] && strncmp(tab[0], "/names", 6) == 0)
    list_names(tab[1], e, fd);
  else if (tab[0] && strncmp(tab[0], "/list", 5) == 0)
    disp_list(tab[1], e, fd);
  else if (tab[0] && strncmp(tab[0], "/msg", 4) == 0)
    send_private_msg(tab[1], tab, e, fd);
}

void	msg_for(t_env *e, int fd, char *msg, char *nickname)
{
  char	*tmp;
  int	i;

  tmp = malloc(sizeof(char) * 4096);
  sprintf(tmp, ":%s :%s", nickname, msg);
  e->clients[fd].msg = strdup(tmp);
  free(tmp);
}

void	check_cmd(char *buffer, t_env *e, int fd)
{
  int	i;

  if (buffer[strlen(buffer) - 1] == '\n')
    buffer[strlen(buffer) - 1] = '\0';
  if (buffer[0] == '/')
    server_cmd(buffer, e, fd);
  else
    if (check_cmd2(e, buffer, fd) == 1);
}
