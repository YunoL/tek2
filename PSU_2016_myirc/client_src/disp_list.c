/*
** disp_list.c for disp_list in /home/guillaume2.roux/rendu/PSU_2016_myirc/client_src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Tue Jun  6 12:35:34 2017 Guillaume Roux
** Last update Tue Jun  6 12:37:08 2017 Guillaume Roux
*/

#include "../include/client.h"

void	disp_list(t_client *client, char *buffer)
{
  make_msg(client, buffer, 1);
}
