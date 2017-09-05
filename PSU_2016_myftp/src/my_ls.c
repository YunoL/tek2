/*
** my_ls.c for my_list in /home/guillaume2.roux/rendu/PSU_2016_myftp/src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Tue May 16 14:11:49 2017 Guillaume Roux
** Last update Fri May 19 09:58:33 2017 Guillaume Roux
*/


#include "../include/my.h"

void	my_list(char *pathname, client_s *my_client)
{
  FILE	*fp;
  char	path[PATH_MAX];

  if (my_client->transf_mode == 0)
    {
      my_write(my_client->client_fd, Msg425);
      return;
    }
  if (!pathname)
    sprintf(path, "ls -l .");
  else
    sprintf(path, "ls -l %.4096s", pathname);
  fp = popen(path, "r");
  while (fgets(path, PATH_MAX, fp) != NULL)
    my_write(my_client->client_fd, path);
  pclose(fp);
  my_write(my_client->client_fd, Msg250);
}
