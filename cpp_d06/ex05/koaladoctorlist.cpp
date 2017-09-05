//
// koaladoctorlist.cpp for koaladoctorlist in /home/guillaume2.roux/rendu/cpp_d06/ex05
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Mon Jan  9 17:47:16 2017 Guillaume Roux
// Last update Mon Jan  9 17:47:17 2017 Guillaume Roux
//

#include "koaladoctorlist.h"

KoalaDoctorList::KoalaDoctorList(KoalaDoctor* name)
{
	this->name = name;
	this->next = NULL;
}

KoalaDoctorList::~KoalaDoctorList()
{

}

bool	KoalaDoctorList::isEnd()
{
	if (this->next == NULL)
		return(true);
	return (false);
}

void	KoalaDoctorList::append(KoalaDoctorList* list)
{
	if (this->isEnd() == true)
		this->next = list;
	else
		this->next->append(list);
}

KoalaDoctor*	KoalaDoctorList::getFromName(std::string name)
{
	if (this->name && this->name->getName() == name)
		return (this->name);
	else if (this->next)
		return (this->next->getFromName(name));
	return (NULL);
}

KoalaDoctorList*	KoalaDoctorList::remove(KoalaDoctorList* list)
{
	KoalaDoctorList *cur = this;
	KoalaDoctorList *prev = NULL;

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

KoalaDoctorList*	KoalaDoctorList::removeFromName(std::string name)
{
	KoalaDoctorList *tmp = this;
	KoalaDoctorList *prev = NULL;

	while (tmp)
	{
		if (tmp && tmp->name && tmp->name->getName() == name)
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

void	KoalaDoctorList::dump()
{
	KoalaDoctorList 	*tmp = this;

	std::cout << "Liste des medecins: ";
	while (tmp)
	{
		if (tmp->name)
			std::cout << tmp->name->getName();
		else
			std::cout << "NULL";
		if (tmp->next)
			std::cout << ", ";
		else
			std::cout << "." << std::endl;
		tmp = tmp->next;
	}
}