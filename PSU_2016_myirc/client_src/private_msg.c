/*
** private_msg.c for private_msg in /home/guillaume2.roux/rendu/PSU_2016_myirc/client_src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Tue Jun  6 12:49:21 2017 Guillaume Roux
** Last update Tue Jun  6 14:39:17 2017 Guillaume Roux
*/

#include "../include/client.h"

void	no_recipient(t_client *client, char *cmd)
{
  char	*msg;

  msg = malloc(sizeof(char) * 512);
  sprintf(msg, "%s (%s)\n", ERR_NORECIPIENT, cmd);
  make_msg(client, msg, 0);
}

void	no_text_to_send(t_client *client)
{
  char	*msg;

  msg = malloc(sizeof(char) * 512);
  sprintf(msg, "412 :%s\n", ERR_NOTEXTTOSEND);
  make_msg(client, msg, 0);
}

void	private_msg(char *nickname, char *msg, t_client *client, char *buffer)
{
  if (!nickname)
    no_recipient(client, "/msg");
  else if (!msg)
    no_text_to_send(client);
  else
    make_msg(client, buffer, 1);
}
