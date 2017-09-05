/*
** free.c for realloc in /home/guillaume2.roux/rendu/PSU_2016_malloc/src/
**
** Made by guillaume2.roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Mon Jan 23 10:39:47 2017 guillaume2.roux
** Last update Tue Jan 31 10:13:09 2017 guillaume2.roux
*/

#include "../include/malloc.h"

void free(void* ptr)
{
  if (!ptr)
    return;
  if (already_in_list(ptr) == 1)
    return;
  while (ptr != memory_map->adr && memory_map->pos_h != 1)
    memory_map = memory_map->next;
  if (memory_map->_free == UNUSED)
    return;
  memory_map->_free = UNUSED;
  if (memory_map->pos_h != 1)
    {
      if (memory_map->adr > memory_map->next->adr && memory_map->adr != memory_map->next->adr)
	{
	  memory_map->pos_h = memory_map->next->pos_h;
    memory_map->size = memory_map->next->size;
    memory_map->next = memory_map->next->next;
	}
  }
  reinit_list();
}
