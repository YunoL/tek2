//
// Shell.cpp for shell in /home/guillaume2.roux/rendu/cpp_nanotekspice/src/
//
// Made by guillaume2.roux
// Login   <guillaume2.roux@epitech.eu>
//
// Started on  Mon Feb 13 09:56:34 2017 guillaume2.roux
// Last update Thu Mar  2 15:13:24 2017 Guillaume Roux
//

#include "../include/Shell.hpp"

nts::Shell::Shell(std::string const &file, int ac, char **av) : _ac(ac), _av(av)
{
  size_t pos = 0;
  this->_run = true;
}

nts::Shell::~Shell()
{}

void  nts::Shell::nanoshell()
{
  std::cout << "> ";
  std::string buffer = "";
  this->simulate();
  this->display();
  while (this->_run && std::getline(std::cin, buffer))
  {
    buffer = this->parse_cmd(buffer);
    this->exec_cmd(buffer);
  }
}

void nts::Shell::my_exit()
{
  this->_run = false;
}

void nts::Shell::display()
{}

void nts::Shell::InputValue(std::string const &str, size_t const pos)
{}

void nts::Shell::simulate()
{}

void nts::Shell::loop()
{}

void nts::Shell::dump()
{}

std::string nts::Shell::parse_cmd(std::string buffer)
{
  return buffer;
}

void nts::Shell::exec_cmd(std::string const &cmd)
{
  if (cmd == "exit")
    this->my_exit();
  else if (cmd == "display")
    this->display();
  else if (cmd == "simulate")
    this->simulate();
  else if (cmd == "loop")
    this->loop();
  else if (cmd == "dump")
    this->dump();
}
