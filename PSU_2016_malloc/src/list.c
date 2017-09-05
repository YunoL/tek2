/*
** list.c for list in /home/guillaume2.roux/rendu/PSU_2016_malloc/src/
**
** Made by guillaume2.roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Thu Jan 26 10:28:36 2017 guillaume2.roux
** Last update Tue Jan 31 10:20:04 2017 guillaume2.roux
*/

#include "../include/malloc.h"

void	put_in_list(t_malloc **list, size_t size, void* adr)
{
  t_malloc	*new_node;

  new_node = sbrk(sizeof(*new_node));
  if (new_node == (void*)-1)
    return;
  new_node->size = size;
  new_node->adr = adr;
  new_node->_free = USED;
  if (*list == NULL)
    new_node->pos_h = 1;
  else
    {
      new_node->pos_h = 0;
      new_node->next = *list;
      if (new_node->next)
	new_node->next->prev = new_node;
    }
  *list = new_node;
  link_list(list);
}

void	link_list(t_malloc **list)
{
  t_malloc	*tmp;

  tmp = *list;
  while ((*list)->pos_h != 1)
    (*list) = (*list)->next;
  (*list)->next = tmp;
  (*list)->next->prev = *list;
  while ((*list) != tmp)
    *list = (*list)->next;
}

void	reinit_list()
{
  while (memory_map->pos_h != 1)
    memory_map = memory_map->next;
  memory_map = memory_map->next;
}

int already_in_list(void* ptr)
{
  t_malloc	*tmp;

  tmp = memory_map;
  while (tmp->pos_h != 1)
    tmp = tmp->next;
  if (tmp->adr != ptr)
    return (1);
  return (0);
}
