//
// Plazza.cpp for plazza in /home/guillaume2.roux/rendu/cpp_plazza/src/
//
// Made by guillaume2.roux
// Login   <guillaume2.roux@epitech.eu>
//
// Started on  Tue Apr 25 11:36:13 2017 guillaume2.roux
// Last update Tue Apr 25 13:12:05 2017 guillaume2.roux
//

#include "../include/Plazza.hh"

Plazza::Plazza(char const *nbThread)
{
  std::stringstream tmp;
  tmp << nbThread;
  this->_nbThread = std::stoi(tmp.str());

}
Plazza::~Plazza()
{}

void  Plazza::run()
{
  std::string cmd;

  while (std::getline(std::cin, cmd))
  {
    if (cmd.size() == 0)
    {
      continue;
    }
  }
}
