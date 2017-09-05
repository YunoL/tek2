//
// ITask.hh for itask in /home/guillaume2.roux/rendu/cpp_plazza/include/
//
// Made by guillaume2.roux
// Login   <guillaume2.roux@epitech.eu>
//
// Started on  Tue Apr 25 13:32:22 2017 guillaume2.roux
// Last update Tue Apr 25 13:34:02 2017 guillaume2.roux
//

#ifndef ITASK_HH_
# define ITASK_HH_

# include <iostream>

class ITask
{
public:
  virtual ~ITask() {};
  virtual void  run() = 0;
};

#endif
