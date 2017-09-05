/*
** disp_user.c for disp_user in /home/guillaume2.roux/rendu/PSU_2016_myirc/client_src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Fri Jun  9 12:10:24 2017 Guillaume Roux
** Last update Fri Jun  9 12:11:35 2017 Guillaume Roux
*/

#include "../include/client.h"

void	disp_user(t_client *client, char *buffer)
{
  make_msg(client, buffer, 1);
}
