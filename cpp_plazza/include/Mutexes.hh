//
// Mutexes.hh for mutexes in /home/guillaume2.roux/rendu/cpp_plazza/include/
//
// Made by guillaume2.roux
// Login   <guillaume2.roux@epitech.eu>
//
// Started on  Tue Apr 25 14:47:10 2017 guillaume2.roux
// Last update Tue Apr 25 15:35:48 2017 guillaume2.roux
//

#ifndef MUTEXES_HH_
# define MUTEXES_HH_

# include <iostream>
# include <pthread.h>
# include "IMutex.hh"

class Mutexes : public IMutex
{
public:
  Mutexes(const pthread_mutexattr_t *attribute = NULL);
  virtual ~Mutexes();
  virtual void  lock();
  virtual void  unlock();
  virtual void  trylock();

  pthread_mutex_t _mutex;
};

#endif
