//
// IThreads.hh for ithreads in /home/guillaume2.roux/rendu/cpp_plazza/include/
//
// Made by guillaume2.roux
// Login   <guillaume2.roux@epitech.eu>
//
// Started on  Tue Apr 25 13:19:46 2017 guillaume2.roux
// Last update Tue Apr 25 15:06:41 2017 guillaume2.roux
//

#ifndef ITHREADS_HH
# define ITHREADS_HH

# include <iostream>
# include "ITask.hh"

class IThreads
{
public:
  enum State
  {
    THREAD_ALIVE,
    THREAD_WAIT,
    THREAD_DEAD
  };
  virtual ~IThreads() {};
  virtual ITask*  getTask() const = 0;
  virtual void  setTask(ITask* task) = 0;
  virtual State getState() const = 0;
  virtual void  setState(State state) = 0;
  virtual int cancel() const = 0;
  virtual void join(void **ret) = 0;
};

#endif
