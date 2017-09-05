/*
** my_port.c for my_port in /home/guillaume2.roux/rendu/PSU_2016_myftp/src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Thu May 18 18:21:38 2017 Guillaume Roux
** Last update Fri May 19 10:35:23 2017 Guillaume Roux
*/

#include "../include/my.h"

int	addr_port[6];

int	my_tablen(char **tab)
{
  int	i;

  for (i = 0; tab[i]; i++);
  return (i);
}

void	my_port(client_s *my_client, char *cmd)
{
  int	i;
  char	**tab;

  tab = my_strd_to_wordtab(cmd, ",");
  if (my_tablen(tab) < 6)
    {
      my_write(my_client->client_fd, Msg500);
      return;
    }
  for (i = 0; i < 6; i++)
    addr_port[i] = atoi(tab[i]);
  my_client->transf_mode = 2;
  my_write(my_client->client_fd, Msg200);
}
