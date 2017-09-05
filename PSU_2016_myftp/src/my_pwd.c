/*
** my_pwd.c for my_pwd in /home/guillaume2.roux/rendu/PSU_2016_myftp/src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Tue May 16 12:56:58 2017 Guillaume Roux
** Last update Fri May 19 11:15:43 2017 Guillaume Roux
*/

#include "../include/my.h"

void	my_pwd(int client_fd)
{
  char	c;
  char	path_pwd[PATH_MAX];

  c = 34;
  if (getcwd(path_pwd, sizeof(path_pwd)) != NULL)
    {
      my_write(client_fd, "257 ");
      write(client_fd, &c, 1);
      my_write(client_fd, path_pwd);
      write(client_fd, &c, 1);
      my_write(client_fd, " created.\n");
    }
  else
    my_write(client_fd, Msg550);
}
