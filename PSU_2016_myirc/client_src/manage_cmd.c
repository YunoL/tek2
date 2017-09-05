/*
** manage_cmd.c for manage_cmd in /home/guillaume2.roux/bootstrap/PSU_2016_myirc/client_src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Thu Jun  1 11:23:41 2017 Guillaume Roux
** Last update Mon Jun 19 10:27:08 2017 Guillaume Roux
*/

#include "../include/client.h"

void	join_channel(char *channel, t_client *client, char *buffer)
{
  if (!channel)
    need_more_param(client, "/join");
  else
    {
      if (get_channel(client, channel) != 0)
	{
	  add_channel(client, channel);
	  make_msg(client, buffer, 1);
	}
    }
}

void	change_nick(char *nickname, t_client *client, char *buffer)
{
  if (!nickname)
    {
      no_nickname_given(client);
      return;
    }
  if (client->nickname)
    free(client->nickname);
  client->nickname = strdup(nickname);
  make_msg(client, buffer, 1);
}

void	server_cmd(char *buffer, t_client *client)
{
  char	**tab;

  tab = my_strd_to_wordtab(buffer, " ");
  if (strncmp(tab[0], "/join", 5) == 0)
    join_channel(tab[1], client, buffer);
  else if (strncmp(tab[0], "/nick", 5) == 0)
    change_nick(tab[1], client, buffer);
  else if (tab[0] && strncmp(tab[0], "/part", 5) == 0)
    part_channel(tab[1], client, buffer);
  else if (tab[0] && strncmp(tab[0], "/users", 6) == 0)
    list_users(client, buffer);
  else if (tab[0] && strncmp(tab[0], "/names", 6) == 0)
    list_names(tab[1], client, buffer);
  else if (tab[0] && strncmp(tab[0], "/server", 7) == 0)
    connect_server(tab[1], client);
  else if (tab[0] && strncmp(tab[0], "/list", 5) == 0)
    disp_list(client, buffer);
  else if (tab[0] && strncmp(tab[0], "/msg", 4) == 0)
    private_msg(tab[1], tab[2], client, buffer);
  else if (tab[0] && strncmp(tab[0], "/quit", 5) == 0)
    my_exit(NULL, 0);
  else if (tab[0] && strncmp(tab[0], "/user", 5) == 0)
    disp_user(client, buffer);
  else
    make_msg(client, "421 <commande> :Unknown command\n", 0);
}

void	check_cmd(char *buffer, t_client *client)
{
  char	*msg;

  if (buffer[0] == '\0' || buffer[0] == '\n')
    return;
  if (buffer[0] == '/')
    server_cmd(buffer, client);
  else
    {
      if (buffer && strncmp(buffer, "NICK", 4) == 0
	  || strncmp(buffer, "QUIT", 4) == 0)
	make_msg(client, buffer, 1);
      else if (client->channel == NULL)
	make_msg(client, "You didn't enter a channel yet\n", 0);
      else
	make_msg(client, buffer, 1);
    }
}
