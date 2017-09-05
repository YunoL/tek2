/*
** part_channel.c for part_channel in /home/guillaume2.roux/bootstrap/PSU_2016_myirc/client_src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Thu Jun  1 13:59:36 2017 Guillaume Roux
** Last update Tue Jun  6 11:38:17 2017 Guillaume Roux
*/

#include "../include/client.h"

void	part_channel(char *channel, t_client *client, char *buffer)
{
  if (!channel)
    need_more_param(client, "/part");
  else if (get_channel(client, channel) != 0)
    not_on_channel(client, channel);
  else
    {
      remove_channel(client, channel);
      make_msg(client, buffer, 1);
    }
}
