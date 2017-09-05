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
	if (!this || !aps)
		return;
	if (!this->str)
		this->str = strdup(aps);
	else
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