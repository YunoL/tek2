//
// sickkoalalist.cpp for sickkoalalist in /home/guillaume2.roux/rendu/cpp_d06/ex05
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Mon Jan  9 17:46:43 2017 Guillaume Roux
// Last update Mon Jan  9 17:46:44 2017 Guillaume Roux
//

#include "sickkoalalist.h"

SickKoalaList::SickKoalaList(SickKoala* koala)
{
	this->koala = koala;
	this->next = NULL;
}

SickKoalaList::~SickKoalaList()
{

}

bool	SickKoalaList::isEnd()
{
	if (this->next == NULL)
		return(true);
	return (false);
}

void	SickKoalaList::append(SickKoalaList* list)
{
	if (this->isEnd() == true)
		this->next = list;
	else
		this->next->append(list);
}

SickKoala*	SickKoalaList::getFromName(std::string name)
{
	if (this->koala && this->koala->getName() == name)
		return (this->koala);
	else if (this->next)
		return (this->next->getFromName(name));
	return (NULL);
}

SickKoalaList*	SickKoalaList::remove(SickKoalaList* list)
{
	SickKoalaList *cur = this;
	SickKoalaList *prev = NULL;

	while (cur)
	{
		if (cur == list)
		{
			if (prev)
			{
				prev->next = cur->next;
				cur->next = NULL;
				return (this);
			}
			else
			{
				prev = cur->next;
				cur->next = NULL;
				return (prev);
			}
		}
		prev = cur;
		cur = cur->next;
	}
	return (NULL);
}

SickKoalaList*	SickKoalaList::removeFromName(std::string name)
{
	SickKoalaList *tmp = this;
	SickKoalaList *prev = NULL;

	while (tmp)
	{
		if (tmp && tmp->koala && tmp->koala->getName() == name)
		{
			if (prev)
			{
				prev->next = tmp->next;
				tmp->next = NULL;
				return (this);
			}
			else
			{
				prev = tmp->next;
				tmp->next = NULL;
				return (prev);
			}
		}
		prev = tmp;
		tmp = tmp->next;
	}
return (NULL);
}

void	SickKoalaList::dump()
{
	SickKoalaList 	*tmp = this;

	std::cout << "Liste des patients: ";
	while (tmp)
	{
		if (tmp->koala)
			std::cout << tmp->koala->getName();
		else
			std::cout << "NULL";
		if (tmp->next)
			std::cout << ", ";
		else
			std::cout << "." << std::endl;
		tmp = tmp->next;
	}
}

SickKoala*	SickKoalaList::getContent()
{
	return (this->koala);
}

SickKoala*	SickKoalaList::getNext()
{
	SickKoalaList*	tmp = this;

	if (tmp->next)
		return(tmp->next->koala);
	return (NULL);
}