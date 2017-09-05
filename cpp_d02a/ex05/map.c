/*
** map.c for map in /home/guillaume2.roux/rendu/cpp_d02a/ex05
** 
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.net>
** 
** Started on  Thu Jan  5 20:10:50 2017 Guillaume Roux
** Last update Thu Jan  5 20:10:51 2017 Guillaume Roux
*/

#include "map.h"
#include "generic_list.h"
#include <stdlib.h>

unsigned int    map_get_size(t_map map)
{
	return (list_get_size(map));
}

t_bool          map_is_empty(t_map map)
{
	return (list_is_empty(map));
}

t_key_comparator    key_cmp_container(t_bool store, t_key_comparator new_key_cmp)
{
	static t_key_comparator	key_cmp;
	if (store == TRUE)
		key_cmp = new_key_cmp;
	return (key_cmp);	
}

int     pair_comparator(void *first, void *second)
{
	t_key_comparator	key_cmp;

	key_cmp = key_cmp_container(FALSE, NULL);
	return ((key_cmp)(((t_pair*)first)->first, second));
}