/*
** ex_6.h for ex_6 in /home/guillaume2.roux/rendu/cpp_d01/ex06
** 
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.net>
** 
** Started on  Wed Jan  4 15:37:06 2017 Guillaume Roux
** Last update Wed Jan  4 15:37:59 2017 Guillaume Roux
*/

#ifndef EX_6_H_
# define EX_6_H_

# include <stdint.h>

typedef union
{
	struct 
	{
		uint16_t		foo;
		union
		{
			uint16_t	bar;
			uint16_t	foo;
		}				bar;
	}					foo;
	uint32_t			bar;
}						t_foo;

#endif /* !EX_6_H_ */