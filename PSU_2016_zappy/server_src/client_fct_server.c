/*
** client_fct_server.c for client_fct_server in /home/guillaume2.roux/rendu/PSU_2016_zappy/server_src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Tue Jun 20 11:45:21 2017 Guillaume Roux
** Last update Thu Jun 29 14:49:03 2017 Guillaume Roux
*/

#include "../include/server.h"
#include "../include/init_server.h"

void	client_write(t_data_server *data_server, int fd)
{
  if (data_server->clients[fd].msg)
    {
      dprintf(fd, "%s\r\n", data_server->clients[fd].msg);
      free(data_server->clients[fd].msg);
    }
  data_server->clients[fd].msg = NULL;
}

int	check_team_name(char *buffer, int fd, t_data_server *data_server)
{
  t_team_names	*tmp;
  t_client	*client;
  char	*msg;
  t_data_flags	*f_data;

  tmp = data_server->data_flags->team_names;
  client = &(data_server->clients[fd]);
  f_data = data_server->data_flags;
  for (;tmp; tmp = tmp->next)
    {
      if (strcmp(buffer, tmp->name) == 0)
	{
	  if (tmp->place_left <= 0)
	    return (0);
	  tmp->place_left--;
	  msg = malloc(sizeof(char) * 100);
	  sprintf(msg, "%d\n%d %d", tmp->place_left, f_data->width, f_data->height);
	  client->team = strdup(buffer);
	  printf("Ajout de %d à la team %s\n", fd, buffer);
	  make_msg(msg, client);
	  return (1);
  }
    }
  return (0);
}

void client_read(t_data_server *data_server, int fd)
{
  int r;
  char	buf[4096];
  int	i;

  r = read(fd, buf, 4096);
  if (r > 0)
    {
      buf[r - 1] = '\0';
      printf("Client command : %s\n", buf);
      if (check_team_name(buf, fd, data_server));
      else
	manage_cmd_server(buf, data_server, fd);
    }
  else
    {
      printf("%d: Connection closed\n", fd);
      close(fd);
      data_server->fd_type[fd] = FD_FREE;
    }
}
