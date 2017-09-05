/*
** add_client.c for add_client in /home/guillaume2.roux/rendu/PSU_2016_myirc/server_src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Fri May 26 11:36:28 2017 Guillaume Roux
** Last update Fri Jun  9 14:05:28 2017 Guillaume Roux
*/

#include "../include/my.h"

char	*make_name(int fd)
{
  char	*tmp;
  char	*buffer;

  buffer = malloc(sizeof(char) * 5);
  sprintf(buffer, "%ld", fd);
  tmp = malloc(sizeof(char) * 512);
  strcpy(tmp, "Anonymous-");
  strcat(tmp, buffer);
  return (tmp);
}

void add_client(t_env *e, int s)
{
  int cs;
  struct sockaddr_in client_sin;
  int client_sin_len;

  client_sin_len = sizeof(client_sin);
  if ((cs = accept(s, (struct sockaddr *)&client_sin, &client_sin_len)) == -1)
    closing("Error : can't accept !", cs, EXIT_FAILURE);
  e->fd_type[cs] = FD_CLIENT;
  e->fct_read[cs] = client_read;
  e->fct_write[cs] = client_write;
  e->fds[cs] = cs;
  e->clients[cs].nickname = make_name(cs);
  e->clients[cs].host = inet_ntoa(client_sin.sin_addr);
  printf("Client : %s\n", e->clients[cs].nickname);
}
