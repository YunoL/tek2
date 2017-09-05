//
// Mutexes.cpp for mutexes in /home/guillaume2.roux/rendu/cpp_plazza/src/
//
// Made by guillaume2.roux
// Login   <guillaume2.roux@epitech.eu>
//
// Started on  Tue Apr 25 15:29:07 2017 guillaume2.roux
// Last update Tue Apr 25 15:35:18 2017 guillaume2.roux
//

#include "../include/Mutexes.hh"

Mutexes::Mutexes(const pthread_mutexattr_t *attribute)
{
  if (pthread_mutex_init(&(this->_mutex), attribute) != 0)
  {
    std::cerr << "Error : pthread_mutex_init !" << '\n';
    exit(-1);
  }
}

Mutexes::~Mutexes()
{
  if (pthread_mutex_destroy(&(this->_mutex)) != 0)
  {
    std::cerr << "Error : pthread_mutex_destroy !" << '\n';
    exit(-1);
  }
}

void  Mutexes::lock()
{
  if (pthread_mutex_lock(&(this->_mutex)) != 0)
  {
    std::cerr << "Error : pthread_mutex_lock !" << '\n';
    exit(-1);
  }
}

void  Mutexes::unlock()
{
  if (pthread_mutex_unlock(&(this->_mutex)) != 0)
  {
    std::cerr << "Error : pthread_mutex_unlock !" << '\n';
    exit(-1);
  }
}

void  Mutexes::trylock()
{
  if (pthread_mutex_trylock(&(this->_mutex)) != 0)
  {
    std::cerr << "Error : pthread_mutex_trylock" << '\n';
    exit(-1);
  }
}
