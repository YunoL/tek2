//
// Plazza.hh for plazza in /home/guillaume2.roux/rendu/cpp_plazza/include/
//
// Made by guillaume2.roux
// Login   <guillaume2.roux@epitech.eu>
//
// Started on  Tue Apr 25 11:36:48 2017 guillaume2.roux
// Last update Tue Apr 25 11:53:32 2017 guillaume2.roux
//

#ifndef PLAZZA_HH
# define PLAZZA_HH

# include <iostream>
# include <sstream>
# include <string>
# include "my.hh"

class Plazza
{
private:
  int _nbThread;
public:
  Plazza(char const *nbThread);
  virtual ~Plazza();
  void  run();
};

#endif
