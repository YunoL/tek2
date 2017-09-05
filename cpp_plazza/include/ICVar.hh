//
// ICVar.hh for icvar in /home/guillaume2.roux/rendu/cpp_plazza/include/
//
// Made by guillaume2.roux
// Login   <guillaume2.roux@epitech.eu>
//
// Started on  Tue Apr 25 13:22:16 2017 guillaume2.roux
// Last update Tue Apr 25 15:26:55 2017 guillaume2.roux
//

#ifndef ICVAR_HH_
# define ICVAR_HH_

# include <iostream>

class ICVar
{
public:
  virtual ~ICVar() {};
  virtual void  wait() = 0;
  virtual void  wait(long timing) = 0;
  virtual void  notify() = 0;
};

#endif
