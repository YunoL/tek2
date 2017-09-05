//
// Shell.hpp for shell in /home/guillaume2.roux/rendu/cpp_nanotekspice/include/
//
// Made by guillaume2.roux
// Login   <guillaume2.roux@epitech.eu>
//
// Started on  Mon Feb 13 09:48:27 2017 guillaume2.roux
// Last update Thu Mar  2 15:28:12 2017 Guillaume Roux
//

#ifndef SHELL_HPP_
#define SHELL_HPP_

#include <iostream>
#include <fstream>
#include <string>

namespace nts
{
    class Shell
    {
    public:
      Shell(std::string const &file, int ac, char **av);
      virtual ~Shell();
      void  nanoshell();
      static bool _continue;
    private:
      int _ac;
      char **_av;
      bool _run;
      std::string _cmd;
      void my_exit();
      void display();
      void InputValue(std::string const &str, size_t const pos);
      void simulate();
      void loop();
      void dump();
      std::string parse_cmd(std::string buffer);
      void exec_cmd(std::string const &cmd);
    };
}

#endif
