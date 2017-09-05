/*
** realloc.c for realloc in /home/guillaume2.roux/rendu/PSU_2016_malloc/src/
**
** Made by guillaume2.roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Mon Jan 23 10:39:43 2017 guillaume2.roux
** Last update Wed Feb  1 10:23:14 2017 guillaume2.roux
*/

#include "../include/malloc.h"

size_t	ptr_len(void* ptr)
{
  t_malloc	*tmp;

  tmp = memory_map;
  while (tmp->adr != ptr)
    tmp = tmp->next;
  return (tmp->size);
}

void        *realloc(void *ptr, size_t size)
{
  void      *new_elm;
  size_t    ptr_size;

  if (size == 0 && ptr != NULL)
    {
      free(ptr);
      return (ptr);
    }
  else if (ptr == NULL || already_in_list(ptr) == 1)
    ptr = malloc(size);
  else
    {
      ptr_size = ptr_len(ptr);
      if (ptr_size == size)
        return (ptr);
      new_elm = malloc(size);
      if (size < ptr_size)
        memcpy(new_elm, ptr, size);
      else
        memcpy(new_elm, ptr, ptr_size);
      free(ptr);
      return (new_elm);
    }
  return (ptr);
}
