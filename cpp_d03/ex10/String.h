/*
** String.h for String in /home/guillaume2.roux/rendu/cpp_d03/ex00
** 
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.net>
** 
** Started on  Fri Jan  6 08:01:42 2017 Guillaume Roux
** Last update Fri Jan  6 08:02:07 2017 Guillaume Roux
*/

#ifndef STRING_H_
# define STRING_H_

#include <stdlib.h>

typedef struct s_string String;

struct 		s_string
{
	char	*str;
	void	(*assign_s)(String *this, String const *str);
	void	(*assign_c)(String *this, char const *s);
	void	(*append_s)(String *this, String const *ap);
	void	(*append_c)(String *this, char const *aps);
	char	(*at)(String *this, size_t pos);
	void	(*clear)(String *this);
	int 	(*size)(String *this);
	int 	(*compare_s)(String *this, const String *str);
	int 	(*compare_c)(String *this, char const *str);
	size_t	(*copy)(String *this, char *s, size_t n, size_t pos);
	char const	*(*c_str)(String *this);
	int 	(*empty)(String *this);
	int 	(*find_s)(String *this, const String *str, size_t pos);
	int 	(*find_c)(String *this, char const *str, size_t pos);
};

void	StringInit(String *this, char const *s);
void	StringDestroy(String *this);
void	assign_s(String *this, String const *str);
void	assign_c(String *this, char const *s);
void	append_s(String *this, String const *ap);
void	append_c(String *this, char const *aps);
char	at(String *this, size_t pos);
void	clear(String *this);
int 	size(String *this);
int 	compare_s(String *this, const String *str);
int 	compare_c(String *this, char const *str);
size_t	copy(String *this, char *s, size_t n, size_t pos);
char const	*c_str(String *this);
int 	empty(String *this);
int 	find_s(String *this, const String *str, size_t pos);
int 	find_c(String *this, char const *str, size_t pos);

#endif	/* !STRING_H_ */