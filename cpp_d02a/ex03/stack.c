/*
** stack.c for stack in /home/guillaume2.roux/rendu/cpp_d02a/ex03
** 
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.net>
** 
** Started on  Thu Jan  5 18:11:14 2017 Guillaume Roux
** Last update Thu Jan  5 18:11:34 2017 Guillaume Roux
*/

#include "stack.h"
#include "generic_list.h"
#include <stdlib.h>

unsigned int	stack_get_size(t_stack stack)
{
	return (list_get_size(stack));
}

t_bool	stack_is_empty(t_stack stack)
{
	return (list_is_empty(stack));
}

t_bool  stack_push(t_stack *stack_ptr, void *elem)
{
	return (list_add_elem_at_front(stack_ptr, elem));
}

t_bool  stack_pop(t_stack *stack_ptr)
{
	return (list_del_elem_at_front(stack_ptr));
}

void    *stack_top(t_stack stack)
{
	return (list_get_elem_at_front(stack));
}