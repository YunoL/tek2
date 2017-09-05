//
// CondVar.cpp for condvar in /home/guillaume2.roux/rendu/cpp_plazza/src/
//
// Made by guillaume2.roux
// Login   <guillaume2.roux@epitech.eu>
//
// Started on  Tue Apr 25 15:17:31 2017 guillaume2.roux
// Last update Tue Apr 25 15:28:33 2017 guillaume2.roux
//

#include "../include/CondVar.hh"

CondVar::CondVar(IMutex& mutex) : _mutex(dynamic_cast<Mutexes&>(mutex))
{
  pthread_cond_init(&(this->_cv), NULL);
}

CondVar::~CondVar()
{
  pthread_cond_destroy(&(this->_cv));
}

void  CondVar::wait()
{
  wait(kInfinite);
}

void  CondVar::wait(long timing)
{
  if (timing == kInfinite)
    pthread_cond_wait(&(this->_cv), &(this->_mutex._mutex));
}

void  CondVar::notify()
{
  pthread_cond_signal(&(this->_cv));
}
