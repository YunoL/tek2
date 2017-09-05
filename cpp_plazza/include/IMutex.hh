//
// IMutex.hh for imutex in /home/guillaume2.roux/rendu/cpp_plazza/include/
//
// Made by guillaume2.roux
// Login   <guillaume2.roux@epitech.eu>
//
// Started on  Tue Apr 25 13:20:58 2017 guillaume2.roux
// Last update Tue Apr 25 13:34:54 2017 guillaume2.roux
//

#ifndef IMUTEX_HH_
# define IMUTEX_HH_

# include <iostream>

class IMutex
{
public:
  virtual ~IMutex() {};
  virtual void  lock() = 0;
  virtual void  unlock() = 0;
  virtual void  trylock() = 0;
};

#endif
