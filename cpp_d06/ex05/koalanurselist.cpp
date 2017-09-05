//
// koalanurselist.cpp for koalanurselist in /home/guillaume2.roux/rendu/cpp_d06/ex05
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Mon Jan  9 17:38:11 2017 Guillaume Roux
// Last update Mon Jan  9 17:38:12 2017 Guillaume Roux
//

#include "koalanurselist.h"

KoalaNurseList::KoalaNurseList(KoalaNurse *nurse)
{
	this->nurse = nurse;
	this->next = NULL;
}

KoalaNurseList::~KoalaNurseList()
{

}

bool	KoalaNurseList::isEnd()
{
	if (this->next == NULL)
		return(true);
	return (false);
}

void	KoalaNurseList::append(KoalaNurseList* list)
{
	if (this->isEnd() == true)
		this->next = list;
	else
		this->next->append(list);
}

KoalaNurse*	KoalaNurseList::getFromID(int id)
{
	if (this->nurse && this->nurse->getID() == id)
		return (this->nurse);
	else if (this->next)
		return (this->next->getFromID(id));
	return (NULL);
}

KoalaNurseList*	KoalaNurseList::remove(KoalaNurseList* list)
{
	KoalaNurseList *cur = this;
	KoalaNurseList *prev = NULL;

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

KoalaNurseList*	KoalaNurseList::removeFromID(int id)
{
	KoalaNurseList *tmp = this;
	KoalaNurseList *prev = NULL;

	while (tmp)
	{
		if (tmp && tmp->nurse && tmp->nurse->getID() == id)
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

void	KoalaNurseList::dump()
{
	KoalaNurseList 	*tmp = this;

	std::cout << "Liste des infirmieres: ";
	while (tmp)
	{
		if (tmp->nurse)
			std::cout << tmp->nurse->getID();
		else
			std::cout << "NULL";
		if (tmp->next)
			std::cout << ", ";
		else
			std::cout << "." << std::endl;
		tmp = tmp->next;
	}
}