//
// Squad.cpp for squad in /home/guillaume2.roux/rendu/cpp_d10/ex02
// 
// Made by Guillaume Roux
// Login   <guillaume2.roux@epitech.net>
// 
// Started on  Fri Jan 13 11:44:21 2017 Guillaume Roux
// Last update Fri Jan 13 11:44:22 2017 Guillaume Roux
//

#include "Squad.hh"

Squad::Squad() : _count(0), _size(10)
{
	int i = 0;
	this->_array = new ISpaceMarine*[this->_size];
	while (i < this->_size)
		this->_array[i++] = NULL;
}
	
Squad::Squad(Squad const & squad)
{
	int i = 0;
	this->_count = squad._count;
	this->_size = squad._size;
	this->_array = new ISpaceMarine*[this->_size];
	while (i < this->_size)
	{
		this->_array[i] = NULL;
		if (squad._array[i])
			this->_array[i] = squad._array[i]->clone();
		i++;
	}
}

Squad::~Squad()
{
	int i = 0;
	while (i < this->_count)
	{
		delete this->_array[i];
		i++;
	}
	delete[] this->_array;
}

int Squad::getCount() const
{
	return this->_count;
}

ISpaceMarine*	Squad::getUnit(int pos)
{
	if (pos > this->_size || pos < 0)
		return NULL;
	return this->_array[pos];
}

int Squad::push(ISpaceMarine* marine)
{
	if (marine)
	{
		if (this->_count >= this->_size)
			this->resize();
		int i = 0;
		while (i < (this->_count))
		{
			if (this->_array[i++] == marine)
				return this->_count;
		}
		this->_array[this->_count++] = marine;
	}
	return this->_count;
}

Squad & Squad::operator=(Squad const & squad)
{
	int i = 0;
	while (i < this->_count)
		delete this->_array[i];
	delete[] this->_array;
	this->_count = squad._count;
	this->_size = squad._size;
	this->_array = new ISpaceMarine*[this->_size];
	i = 0;
	while (i < this->_size)
	{
		this->_array[i] = NULL;
		if (squad._array[i])
			this->_array[i] = squad._array[i]->clone();
		i++;
	}
	return *this;
}

void Squad::resize()
{
	size_t new_size = this->_size * 1.5;
	ISpaceMarine **new_array = new ISpaceMarine *[new_size];
	int i = 0;
	while (i < (int) this->_size)
	{
		new_array[i] = this->_array[i];
		i++;
	}
	while (i < (int) new_size)
		new_array[i++] = NULL;
	delete[] this->_array;
	this->_array = new_array;
	this->_size = new_size;
}