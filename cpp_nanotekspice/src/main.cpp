//
// main.cpp for main in /home/guillaume2.roux/rendu/cpp_nanotekspice/src/
//
// Made by guillaume2.roux
// Login   <guillaume2.roux@epitech.eu>
//
// Started on  Fri Feb 10 09:59:42 2017 guillaume2.roux
// Last update Thu Mar  2 15:58:22 2017 Guillaume Roux
//

#include "../include/Shell.hpp"

bool check_file(char *s)
{
  std::string file(s);
  if (file.substr(file.find_last_of(".") + 1) != "nts")
    return false;
  std::ifstream infile(s);
  return infile.good();
}

bool  get_input(char **av)
{
  for (int i = 2; av[i]; i++)
  {
      std::string tmp(av[i]);
      std::cout << tmp.substr(0, tmp.find_first_of("=")) << "\n";
  }
  return true;
}

int main(int ac, char **av)
{
  if (ac < 2)
  {
    std::cerr << "Usage : ./nanotekspice file.nts [input_value] [...]" << '\n';
    return 0;
  }
  if (check_file(av[1]) == false)
  {
    std::cerr << "Error : bad file !" << '\n';
    return 0;
  }
  nts::Shell *core = new nts::Shell(av[1], ac, av);
  core->nanoshell();
  delete(core);
  return 0;
}
