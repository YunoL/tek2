/*
** identification.c for identifiaction in /home/guillaume2.roux/rendu/PSU_2016_myftp/src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Mon May 15 14:44:31 2017 Guillaume Roux
** Last update Fri May 19 09:31:30 2017 Guillaume Roux
*/

#include "../include/my.h"

bool	user_value;
bool	pass_value;

int	strcicmp(char const *s1, char const *s2, int n)
{
  int i;

	i = 0;
	while (tolower(s1[i]) == tolower(s2[i]) && s1[i] && s2[i] && i < n)
		i++;
	if ((s1[i] == '\0' && s2[i] == '\0') || i == n)
		return (0);
	return (1);
}

void	check_user(char *buffer, int client_fd)
{
  if (!buffer)
    return;
  if (strcicmp(buffer, "anonymous", 9) == 0)
    user_value = true;
  my_write(client_fd, Msg331);
}

void	check_pass(char *buffer, int client_fd)
{
  if (user_value == false)
    {
      my_write(client_fd, Msg530);
      return;
    }
  if (!buffer || strncmp(buffer, "", 0) == 0)
    {
      pass_value = true;
      my_write(client_fd, Msg230);
    }
  else
    user_value = false;
}

void	identification(client_s *my_client)
{
  char	*buff;
  char	**tab;

  buff = get_next_line(my_client->client_fd);
  tab = my_strd_to_wordtab(buff, " ");
  if (tab[0] && strcicmp(tab[0], "user", 4) == 0)
    check_user(tab[1], my_client->client_fd);
  else if (tab[0] && strcicmp(tab[0], "pass", 4) == 0)
    check_pass(tab[1], my_client->client_fd);
  else if (tab[0] && strcicmp(tab[0], "quit", 4) == 0)
    my_quit(my_client);
  else if (tab[0])
    my_write(my_client->client_fd, Msg530);
}
