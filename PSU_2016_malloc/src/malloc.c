/*
** malloc.c for malloc in /home/guillaume2.roux/rendu/PSU_2016_malloc/src/
**
** Made by guillaume2.roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Mon Jan 23 10:39:52 2017 guillaume2.roux
** Last update Fri Feb 10 15:23:46 2017 guillaume2.roux
*/

#include "../include/malloc.h"

t_malloc* memory_map;

void	*find_block(size_t size)
{
  if (memory_map == NULL)
    return (NULL);
  if (memory_map->_free == UNUSED && size <= memory_map->size)
    {
      memory_map->_free = USED;
      return (memory_map->adr);
    }
  while (memory_map->pos_h != 1)
    {
      if (memory_map->_free == UNUSED && size <= memory_map->size)
	{
    memory_map->_free = USED;
    return (memory_map->adr);
	}
      memory_map = memory_map->next;
    }
  reinit_list();
  return (NULL);
}

void *malloc(size_t size)
{
  static int	i = 0;
  void*				tmp;

  if (size > (SIZE_MAX - 1) - sizeof(t_malloc))
    return (NULL);
  if (size != 0)
    size = (size - 1) / 4 * 4 + 4;
  tmp = find_block(size);
  if (tmp != NULL)
    {
      reinit_list();
      return (tmp);
    }
  tmp = sbrk(size);
  if (tmp == (void*) -1)
    return (NULL);
  if (i == 0)
    memory_map = NULL;
  put_in_list(&memory_map, size, tmp);
  i = 1;
  return (tmp);
}

void		show_alloc_mem()
{
  size_t	chunk;
  t_malloc	*tmp;

  tmp = memory_map;
  printf("break : 0x%lX\n", (size_t)sbrk(0));
  while (tmp != NULL)
    {
      chunk = (size_t)tmp + (sizeof(struct s_malloc));
      if (!tmp->_free)
				printf("0x%lX - 0x%lX : %lu bytes\n", chunk, chunk + tmp->size, tmp->size);
      tmp = tmp->next;
    }
}
