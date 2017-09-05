//
// CondVar.hh for condvar in /home/guillaume2.roux/rendu/cpp_plazza/include/
//
// Made by guillaume2.roux
// Login   <guillaume2.roux@epitech.eu>
//
// Started on  Tue Apr 25 14:50:32 2017 guillaume2.roux
// Last update Tue Apr 25 15:26:49 2017 guillaume2.roux
//

#ifndef CONDVAR_HH
# define CONDVAR_HH

# include <iostream>
# include <pthread.h>
# include "ICVar.hh"
# include "Mutexes.hh"

class CondVar : public ICVar
{
public:
  static const long kInfinite = -1;
  explicit CondVar(IMutex& mutex);
  virtual ~CondVar();
  virtual void  wait();
  virtual void  wait(long timing);
  virtual void  notify();
private:
  pthread_cond_t  _cv;
  Mutexes&  _mutex;
};

#endif
