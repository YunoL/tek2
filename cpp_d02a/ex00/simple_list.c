/*
** simple_list.c for simple_list in /home/guillaume2.roux/rendu/cpp_d02a/ex00
** 
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.net>
** 
** Started on  Thu Jan  5 14:02:01 2017 Guillaume Roux
** Last update Thu Jan  5 14:02:02 2017 Guillaume Roux
*/

#include <stdio.h>
#include "simple_list.h"
#include <stdlib.h>

unsigned int	list_get_size(t_list list)
{
	unsigned int	i;

	i = 0;
	while (list != NULL)
	{
		list = list->next;
		i++;
	}
	return (i);
}

t_bool	list_is_empty(t_list list)
{
	if (list == NULL)
		return (TRUE);
	return (FALSE);
}

void	list_dump(t_list list)
{
	while (list != '\0')
	{
		printf("%f\n", list->value);
		list = list->next;
	}
}

t_bool	list_add_elem_at_front(t_list *front_ptr, double elem)
{
	t_list	new_elem;

	if ((new_elem = malloc(sizeof(t_list))) == NULL)
		return (FALSE);
	new_elem->value = elem;
	new_elem->next = *front_ptr;
	*front_ptr = new_elem;
	return (TRUE);
}

t_bool	list_add_elem_at_back(t_list *front_ptr, double elem)
{
	t_list	last_elem;
	t_list	new_elem;

	if ((last_elem = malloc(sizeof(t_list))) == NULL)
		return (FALSE);
	last_elem->next = NULL;
	last_elem->value = elem;
	if (*front_ptr == NULL)
		return (list_add_elem_at_front(front_ptr, elem));
	new_elem = *front_ptr;
	while (new_elem->next != NULL)
		new_elem = new_elem->next;
	new_elem->next = last_elem;
	return (TRUE);
}

t_bool	list_add_elem_at_position(t_list *front_ptr, double elem, unsigned int position)
{
	t_list	new_elem;
	t_list	add_elm;
	unsigned int	i;

	i = 0;
	if (position == 0)
		return (list_add_elem_at_front(front_ptr, elem));
	if (*front_ptr == NULL)
		return (FALSE);
	new_elem = malloc(sizeof(t_list));
	if (new_elem == NULL)
		return (FALSE);
	new_elem->value = elem;
	add_elm = *front_ptr;
	while (add_elm->next != NULL && i != position)
	{
		add_elm = add_elm->next;
		i++;
	}
	add_elm->next = new_elem;
	return (TRUE);
}

t_bool	list_del_elem_at_front(t_list *front_ptr)
{
	if (*front_ptr == NULL)
		return (FALSE);
	*front_ptr = (*front_ptr)->next;
	if (*front_ptr == NULL)
		return (FALSE);
	return (TRUE);
}

t_bool	list_del_elem_at_back(t_list *front_ptr)
{
	t_list	last_elm;

	if (*front_ptr == NULL)
		return (FALSE);
	if ((*front_ptr)->next == NULL)
	{
		*front_ptr = NULL;
		return (FALSE);
	}
	last_elm = *front_ptr;
	while (last_elm->next->next != NULL)
		last_elm = last_elm->next;
	last_elm->next = NULL;
	return (TRUE);
}

t_bool	list_del_elem_at_position(t_list *front_ptr, unsigned int position)
{
	t_list			elem_ptr;
	t_list			prev_elem;
	unsigned int	i;

	i = 0;
	if (position == 0)
		return(list_del_elem_at_front(front_ptr));
	else if (position + 1 == list_get_size(*front_ptr))
		return (list_del_elem_at_back(front_ptr));
	if (*front_ptr == NULL)
		return (FALSE);
	elem_ptr = *front_ptr;
	prev_elem = elem_ptr;
	while (elem_ptr->next != NULL && i != position)
	{
		prev_elem = elem_ptr;
		elem_ptr = elem_ptr->next;
		i++;
	}
	if (i != position || elem_ptr->next == NULL)
		return (FALSE);
	prev_elem->next = elem_ptr->next;
	free(elem_ptr);
	return (TRUE);
}

double	list_get_elem_at_front(t_list list)
{
	if (list == NULL)
		return (0.0);
	return (list->value);
}

double	list_get_elem_at_back(t_list list)
{
	if (list == NULL)
		return (0.0);
	while (list->next != NULL)
		list = list->next;
	return (list->value);
}

double	list_get_elem_at_position(t_list list, unsigned int position)
{
	unsigned int	i;

	i = 0;
	if (list == NULL)
		return (0.0);
	if (position == 0)
		return(list_get_elem_at_front(list));
	while (list->next != NULL && i < position)
	{
		list = list->next;
		i++;
	}
	if (i != position || list == NULL)
		return (0.0);
	return (list->value);
}

t_node	*list_get_first_list_with_value(t_list list, double value)
{
	while (list != NULL)
	{
		if  (list->value == value)
			return (list);
		list = list->next;
	}
	return (NULL);
}