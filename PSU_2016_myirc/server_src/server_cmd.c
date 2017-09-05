/*
** server_cmd.c for server_cmd in /home/guillaume2.roux/rendu/PSU_2016_myirc/server_src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Fri Jun  9 13:44:01 2017 Guillaume Roux
** Last update Sat Jun 10 12:49:01 2017 Guillaume Roux
*/

#include "../include/my.h"

int	check_cmd3(t_env *e, int fd, char **tab)
{
  if (tab[0] && strncmp(tab[0], "PART", 4) == 0)
    {
      part_channel(tab[1], e, fd);
      return (1);
    }
  else if (tab[0] && strncmp(tab[0], "PRIVMSG", 7) == 0)
    {
      send_private_msg(tab[1], tab, e, fd);
      return (1);
    }
  else if (tab[0] && strncmp(tab[0], "USER", 4) == 0)
    disp_user(e, fd, e->clients[fd].nickname);
  return (0);
}

int	check_cmd2(t_env *e, char *buffer, int fd)
{
  char	**tab;

  tab = my_strd_to_wordtab(buffer, " ");
  if (tab[0] && strncmp(tab[0], "NICK", 4) == 0)
    {
      change_nick(tab[1], e, fd);
      return (1);
    }
  if (tab[0] && strncmp(tab[0], "QUIT", 4) == 0)
    {
      printf("%d: Connection closed\n", fd);
      close(fd);
      e->fd_type[fd] = FD_FREE;
      return (1);
    }
  if (tab[0] && strncmp(tab[0], "JOIN", 5) == 0)
    {
      join_channel(tab[1], e, fd);
      return (1);
    }
  return (check_cmd3(e, fd, tab));
}
