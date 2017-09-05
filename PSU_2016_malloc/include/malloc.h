/*
** malloc.h for malloc in /home/guillaume2.roux/rendu/PSU_2016_malloc/include/
**
** Made by guillaume2.roux
** Login   <guillaume2.roux@epitech.eu>
**
** Started on  Mon Jan 23 10:45:57 2017 guillaume2.roux
** Last update Fri Feb 10 14:19:39 2017 guillaume2.roux
*/

#ifndef MALLOC_H_
# define MALLOC_H_

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdint.h>

typedef enum	Using
{
  UNUSED,
  USED
}							Using;

typedef struct		s_malloc
{
  struct s_malloc	*next;
  struct s_malloc	*prev;
  size_t					size;
  Using						_free;
  void*						adr;
  int 						pos_h;
}									t_malloc;

extern t_malloc	*memory_map;

void*	malloc(size_t size);
void*	realloc(void* ptr, size_t size);
void	free(void* ptr);
void*	calloc(size_t nmemb, size_t size);
void	put_in_list(t_malloc **list, size_t size, void* adr);
void	reinit_list();
void	link_list(t_malloc **list);
int already_in_list(void* ptr);
size_t	ptr_len(void* ptr);

#endif
