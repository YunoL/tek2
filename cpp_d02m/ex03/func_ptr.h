/*
** func_ptr.h for func_ptr in /home/guillaume2.roux/rendu/cpp_d02m/ex03
** 
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.net>
** 
** Started on  Thu Jan  5 09:26:14 2017 Guillaume Roux
** Last update Thu Jan  5 09:26:27 2017 Guillaume Roux
*/

#ifndef FUNC_H_
# define FUNC_H_

# include "func_ptr_enum.h"

void	print_normal(char *str);
void	print_reverse(char *str);
void	print_upper(char *str);
void	print_42(char *str);
void	do_action(t_action action, char *str);

#endif /* !FUNC_H_ */