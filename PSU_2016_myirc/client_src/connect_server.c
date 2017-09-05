/*
** connect_server.c for connect_server in /home/guillaume2.roux/rendu/PSU_2016_myirc/client_src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Fri Jun  2 11:11:14 2017 Guillaume Roux
** Last update Thu Jun  8 13:27:32 2017 Guillaume Roux
*/

#include "../include/client.h"

void	launch_connection(char *address, char *port, t_client *client)
{
  int	fd;
  struct protoent	*pe;
  struct sockaddr_in	s_in;

  if (!(pe = getprotobyname("TCP")))
    my_exit("Error : getprotobyname", EXIT_FAILURE);
  fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  if (fd == - 1)
    closing("Error : can't create socket", fd, EXIT_FAILURE);
  s_in.sin_family = AF_INET;
  if (!port)
    s_in.sin_port = htons(DEFAULT_PORT);
  else
    s_in.sin_port = htons(xatoi(port));
  s_in.sin_addr.s_addr = inet_addr(address);
  if (connect(fd, (struct sockaddr *) &s_in, sizeof(s_in)) ==  - 1)
    closing("Error : can't connect", fd, EXIT_FAILURE);
  client->fd = fd;
}

void	connect_server(char *arg, t_client *client)
{
  char	**tab;
  char	*msg;

  if (!arg)
    make_msg(client, "USAGE: /server $host[:$port]\n", 0);
  else if (client->fd != 0)
    make_msg(client, ERR_ALREADYREGISTRED, 0);
  else
    {
      tab = my_strd_to_wordtab(arg, ":");
      launch_connection(tab[0], tab[1], client);
      if (client->to_server)
	free(client->to_server);
      msg = malloc(sizeof(char) * 512);
      sprintf(msg, "/server %d", client->fd);
      make_msg(client, msg, 1);
      free(msg);
    }
}

int	make_connect(t_client *client)
{
  int	fd;
  int	r;
  char	buffer[4096];
  char	**tab;

  r = read(0, buffer, 4095);
  if (r > 1)
    {
      buffer[r - 1] = '\0';
      if (strncmp(buffer, "/server", 7) == 0)
	{
	  tab = my_strd_to_wordtab(buffer, " ");
	  if (!tab[1])
	    {
	      printf("461 /server :%s\n", ERR_NEEDMOREPARAMS);
	      return (-1);
	    }
	  connect_server(tab[1], client);
	}
      else
	printf("USAGE: /server $host[:$port]\n");
    }
  fd = client->fd;
  return (fd);
}
