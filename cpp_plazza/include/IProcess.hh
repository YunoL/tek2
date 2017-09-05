//
// IProcess.hh for iprocess in /home/guillaume2.roux/rendu/cpp_plazza/include/
//
// Made by guillaume2.roux
// Login   <guillaume2.roux@epitech.eu>
//
// Started on  Tue Apr 25 13:16:13 2017 guillaume2.roux
// Last update Tue Apr 25 13:35:12 2017 guillaume2.roux
//

#ifndef IPROCESS_HH_
# define IPROCESS_HH_

# include <iostream>

class IProcess
{
public:
  enum State
  {
    PROC_ALIVE,
    PROC_DEAD
  };
  virtual ~IProcess() {};
  virtual void  wait() = 0;
  virtual State getState() const = 0;
};

#endif
