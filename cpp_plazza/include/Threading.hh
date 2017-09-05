//
// Threading.hh for threading in /home/guillaume2.roux/rendu/cpp_plazza/include/
//
// Made by guillaume2.roux
// Login   <guillaume2.roux@epitech.eu>
//
// Started on  Tue Apr 25 14:36:47 2017 guillaume2.roux
// Last update Tue Apr 25 15:15:27 2017 guillaume2.roux
//

#ifndef THREADING_HH
# define THREADING_HH

# include <iostream>
# include <pthread.h>
# include "IThreads.hh"
# include "ITask.hh"
# include "Mutexes.hh"
# include "CondVar.hh"

class Threading : public IThreads
{
public:
  Threading();
  virtual ~Threading();
  virtual ITask*  getTask() const;
  virtual void  setTask(ITask* task);
  virtual State getState() const;
  virtual void  setState(State state);
  virtual int cancel() const;
  virtual void join(void **ret);
private:
  ITask*  _task;
  Mutexes _mutex;
  CondVar _cv;
  pthread_t _thread;
  State _state;

  static void *handleThr(void *arg)
  {
    return NULL;
  }
};

#endif
