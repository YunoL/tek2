/*
** String.c for String in /home/guillaume2.roux/rendu/cpp_d03/ex00
** 
** Made by Guillaume Roux
** Login   <guillaume2.roux@epitech.net>
** 
** Started on  Fri Jan  6 08:03:36 2017 Guillaume Roux
** Last update Fri Jan  6 08:03:38 2017 Guillaume Roux
*/

#include "String.h"
#include <string.h>

void	StringInit(String *this, char const *s)
{
	if (!this)
		return;
	this->str = NULL;
	if (s)
		this->str = strdup(s);
	this->assign_s = &assign_s;
	this->assign_c = &assign_c;
	this->append_s = &append_s;
	this->append_c = &append_c;
	this->at = &at;
	this->clear = &clear;
	this->size = &size;
	this->compare_s = &compare_s;
	this->compare_c = &compare_c;
	this->copy = &copy;
	this->c_str = &c_str;
	this->empty = &empty;
}

void	StringDestroy(String *this)
{
	if (this && this->str)
	{
		free(this->str);
		this->str = NULL;
	}
}

void	assign_s(String *this, String const *str)
{
	if (this && str)
		assign_c(this, str->str);
}

void	assign_c(String *this, char const *s)
{
	if (!this || !s)
		return;
	if (this->str)
		free(this->str);
	this->str = strdup(s);
}

void	append_s(String *this, String const *ap)
{
	if (this && ap)
		append_c(this, ap->str);
}

void	append_c(String *this, char const *aps)
{
	size_t	len;
	size_t	len_ap;

	len = 0;
	if (!this || !aps)
		return;
	if (this->str)
		len = strlen(this->str);
	len_ap = strlen(aps); 
	this->str = realloc(this->str, len + len_ap + 1);
	memset(this->str + len, 0, len_ap + 1);
	if (!this->str)
		free(this->str);
	this->str = strcat(this->str, aps);
}

char	at(String *this, size_t pos)
{
	if (!this || !this->str || pos > strlen(this->str) - 1)
		return (-1);
	return (this->str[pos]);
}

void	clear(String *this)
{
	int 	i;

	i = 0;
	if (!this || !this->str)
		return;
	while (this->str[i] != '\0')
	{
		this->str[i] = '\0';
		i++;
	}
}

int 	size(String *this)
{
	if (!this || !this->str)
		return (-1);
	return (strlen(this->str));
}

int 	compare_s(String *this, const String *str)
{
	if (!this && !str)
		return (0);
	if (str)
		return (compare_c(this, str->str));
	return (compare_c(this, NULL));
}

int 	compare_c(String *this, char const *str)
{
	if (!this)
		return (-1);
	if (this->str && !str)
		return (1);
	if (!this->str && str)
		return (-1);
	if (!this->str && !str)
		return (0);
	return (strcmp(this->str, str));
}

size_t	copy(String *this, char *s, size_t n, size_t pos)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (!this || !s || !this->str)
		return (0);
	len = strlen(this->str);
	while (i + pos < len && i < n)
	{
		s[i] = this->str[i + pos];
		i++;
	}
	if (strlen(s) < n)
		s[i++] = 0;
	return (i);
}

char const	*c_str(String *this)
{
	if (!this)
		return (NULL);
	return (this->str);
}

int 	empty(String *this)
{
	if (!this || !this->str)
		return (1);
	if (strlen(this->str) == 0)
		return (1);
	return (-1);
}