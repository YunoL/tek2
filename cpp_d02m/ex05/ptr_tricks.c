/*
** ptr_tricks.c for ptr_tricks in /home/guillaume2.roux/rendu/cpp_d02m/ex05
** 
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.net>
** 
** Started on  Thu Jan  5 12:45:52 2017 Guillaume Roux
** Last update Thu Jan  5 12:45:53 2017 Guillaume Roux
*/

#include <stdio.h>
#include <stdlib.h>
#include "ptr_tricks.h"

int	get_array_nb_elem(int *ptr1, int *ptr2)
{
	return (ptr2 - ptr1);	
}

t_whatever	*get_struct_ptr(int *member_ptr)
{
	t_whatever	*tmp;

	return ((t_whatever*)((member_ptr - (&tmp->member - (int*)tmp))));
}