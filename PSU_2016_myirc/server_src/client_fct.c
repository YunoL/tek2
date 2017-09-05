/*
** client_fct.c for client_fct in /home/guillaume2.roux/rendu/PSU_2016_myirc/server_src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Fri May 26 11:38:01 2017 Guillaume Roux
** Last update Sun Jun 11 16:05:38 2017 Guillaume Roux
*/

#include "../include/my.h"

void	client_write(t_env *e, int fd)
{
  if (e->clients[fd].msg)
    {
      dprintf(fd, "%s\r\n", e->clients[fd].msg);
      free(e->clients[fd].msg);
    }
  e->clients[fd].msg = NULL;
}

void client_read(t_env *e, int fd)
{
  int r;
  char	buf[4096];
  char	**tab;
  int	i;

  r = read(fd, buf, 4096);
  if (r > 0)
    {
      buf[r] = '\0';
      tab = my_strd_to_wordtab(buf, "\n");
      for (i = 0; tab[i]; i++)
	{
	  if (is_a_cmd(tab[i]) == 0)
	    check_cmd(make_cmd(tab, i), e, fd);
	  else
	    send_all_channel(e, fd, tab[i]);
	}
    }
  else
    {
      printf("%d: Connection closed\n", fd);
      close(fd);
      e->fd_type[fd] = FD_FREE;
    }
}
