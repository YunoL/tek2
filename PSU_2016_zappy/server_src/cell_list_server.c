/*
** cell_list_server.c for cell_list_server in /home/guillaume2.roux/rendu/PSU_2016_zappy/server_src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Tue Jun 20 13:04:54 2017 Guillaume Roux
** Last update Wed Jun 28 15:29:37 2017 Guillaume Roux
*/

#include "../include/cell_server.h"
#include "../include/server.h"

void	init_cell(t_cell_server *cell)
{
  cell->client_list = NULL;
  cell->linemate_nbr = 0;
  cell->deraumere_nbr = 0;
  cell->sibur_nbr = 0;
  cell->mendiane_nbr = 0;
  cell->phiras_nbr = 0;
  cell->thystame_nbr = 0;
  cell->life_units = 0;
}

void	client_add(t_client	*client, t_cell_server *cells)
{
  t_client_list	*tmp;
  t_client_list	*new;

  tmp = cells->client_list;
  while (tmp && tmp->next)
    tmp = tmp->next;
  new = xmalloc(sizeof(t_client_list));
  new->client = client;
  new->next = NULL;
  if (tmp)
    tmp->next = new;
  else
    cells->client_list = new;
}

void	remove_client(int fd, t_cell_server *cells)
{
  t_client_list	*tmp;
  t_client_list	*old;

  tmp = cells->client_list;
  old = NULL;
  while (tmp)
    {
      if (tmp->client->fd == fd)
	{
	  if (old)
	    old->next = tmp->next;
	  else
	    cells->client_list = tmp->next;
	  return;
	}
      old = tmp;
      tmp = tmp->next;
    }
}
