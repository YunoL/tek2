/*
** err_server.c for PSU_2016_zappy in /home/turba_d/projets/PSU_2016_zappy/server_src
** 
** Made by dorian turba
** Login   <turba_d@epitech.net>
** 
** Started on  Mon Jun 19 09:44:21 2017 dorian turba
** Last update Mon Jun 19 11:27:25 2017 dorian turba
*/

#include "../include/server.h"
#include "../include/err_server.h"

int	error(char *msg)
{
  dprintf(1, "%s", msg);
  return (1);
}
