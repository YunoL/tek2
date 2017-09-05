/*
** xfunction.c for xfunction in /home/guillaume2.roux/rendu/PSU_2016_zappy/server_src/
**
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Mon Jun 19 14:16:23 2017 Guillaume Roux
** Last update Mon Jun 19 15:25:17 2017 Guillaume Roux
*/

#include "../include/server.h"

void	*xmalloc(int size)
{
  void	*ptr;

  if ((ptr = malloc(size)) == NULL)
    {
      fprintf(stderr, "Error : malloc, impossible to allocate memory\n");
      exit(0);
    }
  return (ptr);
}

int	xstrcmp(const char *s1, const char *s2)
{
  if (!s1 || !s2)
    return (1);
  return (strcmp(s1, s2));
}

int	xatoi(char *s)
{
  if (!s)
    return (0);
  return (atoi(s));
}
