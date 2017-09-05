//
// Processes.hh for processes in /home/guillaume2.roux/rendu/cpp_plazza/include/
//
// Made by guillaume2.roux
// Login   <guillaume2.roux@epitech.eu>
//
// Started on  Tue Apr 25 13:30:47 2017 guillaume2.roux
// Last update Tue Apr 25 13:57:03 2017 guillaume2.roux
//

#ifndef PROCESSES_HH_
# define PROCESSES_HH_

# include <iostream>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include "IProcess.hh"
# include "ITask.hh"

class Processes : public IProcess
{
public:
  Processes(ITask &task);
  virtual ~Processes();
  virtual void  wait();
  virtual State getState() const;
private:
  ITask&  _rout;
  pid_t _pid;
  State _state;
};

#endif
