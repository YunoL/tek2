/*
** list_users.c for list_users in /home/guillaume2.roux/bootstrap/PSU_2016_myirc/client_src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Thu Jun  1 14:20:58 2017 Guillaume Roux
** Last update Tue Jun  6 14:56:39 2017 Guillaume Roux
*/

#include "../include/client.h"

void	list_users(t_client *client, char *buffer)
{
  make_msg(client, buffer, 1);
}

void	list_names(char *channel, t_client *client, char *buffer)
{
  if (!channel)
    need_more_param(client, "/names");
  else
    make_msg(client, buffer, 1);
}
