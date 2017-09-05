/*
** execute_cmd.c for execute_cmd in /home/guillaume2.roux/rendu/PSU_2016_myftp/src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Mon May 15 19:18:06 2017 Guillaume Roux
** Last update Sun May 21 21:42:23 2017 Guillaume Roux
*/

#include "../include/my.h"

char	*home_dir;
bool	user_value;
bool	pass_value;

void	my_cwd(char *new_path, int client_fd)
{
  char	path[PATH_MAX];

  sprintf(path, "%.4096s", new_path);
  if (!new_path || chdir(path) == -1)
    {
      my_write(client_fd, Msg550);
      return;
    }
  my_write(client_fd, Msg250);
}

void	my_cdup(int client_fd)
{
  my_cwd("..", client_fd);
}

void	my_noop(int client_fd)
{
  my_write(client_fd, Msg200);
}

void	execute2(char **tab, client_s *my_client)
{
  if (tab[0] && strcicmp(tab[0], "port", 4) == 0)
    my_port(my_client, tab[1]);
  else if (tab[0] && strcicmp(tab[0], "dele", 4) == 0)
    my_dele(my_client, tab[1]);
  else if (tab[0] && strcicmp(tab[0], "help", 4) == 0)
    my_help(my_client);
  else if (tab[0] && strcicmp(tab[0], "retr", 4) == 0)
    my_retr(my_client, tab[1]);
  else if (tab[0] && strcicmp(tab[0], "stor", 4) == 0)
    my_stor(my_client, tab[1]);
  else if (tab[0])
    my_write(my_client->client_fd, Msg500);
}

int	execute(client_s *my_client)
{
  char	*buff;
  char	**tab;

  buff = get_next_line(my_client->client_fd);
  tab = my_strd_to_wordtab(buff, " ");
  if (buff && strcicmp(buff, "quit", 4) == 0)
    return (0);
  else if (tab[0] && strcicmp(tab[0], "cwd", 3) == 0)
    my_cwd(tab[1], my_client->client_fd);
  else if (tab[0] && strcicmp(tab[0], "cdup", 4) == 0)
    my_cdup(my_client->client_fd);
  else if (tab[0] && strcicmp(tab[0], "noop", 4) == 0)
    my_noop(my_client->client_fd);
  else if (tab[0] && strcicmp(tab[0], "pwd", 3) == 0)
    my_pwd(my_client->client_fd);
  else if (tab[0] && strcicmp(tab[0], "list", 4) == 0)
    my_list(tab[1], my_client);
  else if (tab[0] && strcicmp(tab[0], "pasv", 4) == 0)
    my_pasv(my_client);
  else if (tab[0] && strcicmp(tab[0], "type", 4) == 0)
    my_type(tab[1], my_client);
  else
    execute2(tab, my_client);
  return (1);
}
