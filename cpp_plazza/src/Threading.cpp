//
// Threading.cpp for threading in /home/guillaume2.roux/rendu/cpp_plazza/src/
//
// Made by guillaume2.roux
// Login   <guillaume2.roux@epitech.eu>
//
// Started on  Tue Apr 25 14:55:15 2017 guillaume2.roux
// Last update Tue Apr 25 15:16:45 2017 guillaume2.roux
//

#include "../include/Threading.hh"

Threading::Threading() : _task(NULL), _cv(_mutex), _state(THREAD_WAIT)
{
  if (pthread_create(&(this->_thread), NULL, &Threading::handleThr, this) != 0)
  {
    std::cerr << "Error : pthread_create !" << '\n';
    exit(-1);
  }
}

Threading::~Threading()
{
  this->_state = THREAD_DEAD;
  this->_cv.notify();
  this->cancel();
  this->join(NULL);
}

ITask*  Threading::getTask() const
{
  return this->_task;
}

void  Threading::setTask(ITask* task)
{
  this->_task = task;
}

IThreads::State Threading::getState() const
{
  return this->_state;
}

void  Threading::setState(State state)
{
  this->_state = state;
}

int Threading::cancel() const
{
  int  status;

  status = pthread_cancel(this->_thread);
  return status;
}

void Threading::join(void **ret)
{
  if (pthread_join(this->_thread, ret) != 0)
  {
    std::cerr << "Error : pthread_join !" << '\n';
    exit(-1);
    this->_state = THREAD_DEAD;
  }
}
