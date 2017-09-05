/*
** err_manage.c for err_manege in /home/guillaume2.roux/rendu/PSU_2016_myirc/client_src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Fri Jun  2 12:51:28 2017 Guillaume Roux
** Last update Tue Jun  6 11:37:38 2017 Guillaume Roux
*/

#include "../include/client.h"

void	need_more_param(t_client *client, char *cmd)
{
  char	*msg;

  msg = malloc(sizeof(char) * 512);
  sprintf(msg, "461 %s :%s\n", cmd, ERR_NEEDMOREPARAMS);
  make_msg(client, msg, 0);
}

void	too_many_chan(t_client *client, char *channel)
{
  char *msg;

  msg = malloc(sizeof(char) * 512);
  sprintf(msg, "405 %s :%s\n", channel, ERR_TOOMANYCHANNELS);
  make_msg(client, msg, 0);
}

void	no_such_chan(t_client *client, char *channel)
{
  char *msg;

  msg = malloc(sizeof(char) * 512);
  sprintf(msg, "403 %s :%s\n", channel, ERR_NOSUCHCHANNEL);
  make_msg(client, msg, 0);
}

void	no_nickname_given(t_client *client)
{
  char	*msg;

  msg = malloc(sizeof(char) * 512);
  sprintf(msg, "431 %s\n", ERR_NONICKNAMEGIVEN);
  make_msg(client, msg, 0);
}

void	not_on_channel(t_client *client, char *channel)
{
  char *msg;

  msg = malloc(sizeof(char) * 512);
  sprintf(msg, "442 %s :%s\n", channel, ERR_NOTONCHANNEL);
  make_msg(client, msg, 0);
}
