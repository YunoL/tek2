//
// Processes.cpp for processes in /home/guillaume2.roux/rendu/cpp_plazza/src/
//
// Made by guillaume2.roux
// Login   <guillaume2.roux@epitech.eu>
//
// Started on  Tue Apr 25 13:38:59 2017 guillaume2.roux
// Last update Tue Apr 25 14:00:13 2017 guillaume2.roux
//

#include "../include/Processes.hh"

Processes::Processes(ITask &task) : _rout(task), _state(PROC_DEAD)
{
  this->_pid = fork();
  if (this->_pid == -1)
  {
    std::cerr << "Error : fork !" << '\n';
    exit(-1);
  }
  if (this->_pid > 0)
    this->_state = PROC_ALIVE;
  else
    task.run();
}

Processes::~Processes()
{
  this->wait();
}

void  Processes::wait()
{
  int tmp;

  if (this->_state != PROC_ALIVE)
    return;
  if (waitpid(this->_pid, &tmp, 0) < 0)
  {
    std::cerr << "Error : getpid !" << '\n';
    exit(-1);
  }
  this->_state = PROC_DEAD;
}

IProcess::State Processes::getState() const
{
  return this->_state;
}
