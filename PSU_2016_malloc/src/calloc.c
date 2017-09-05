/*
** calloc.c for calloc in /home/guillaume2.roux/rendu/PSU_2016_malloc/
**
** Made by guillaume2.roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Wed Feb  1 10:27:32 2017 guillaume2.roux
** Last update Wed Feb  1 10:34:21 2017 guillaume2.roux
*/

#include "../include/malloc.h"

void	*calloc(size_t nmemb, size_t size)
{
  void*	elm;
  size_t	total;

  total = nmemb + size;
  if (!total)
    return (malloc(size));
  if (size && (total / size != nmemb))
    return (NULL);
  elm = malloc(total);
  if (elm == NULL)
    return (NULL);
  return (memset(elm, 0, total));
}
