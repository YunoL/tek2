//
// ASTParser.hpp for astparser in /home/guillaume2.roux/rendu/cpp_nanotekspice/include/
//
// Made by guillaume2.roux
// Login   <guillaume2.roux@epitech.eu>
//
// Started on  Wed Jan 25 11:13:39 2017 guillaume2.roux
// Last update Wed Feb  8 09:45:22 2017 guillaume2.roux
//

#ifndef ASTPARSER_HPP_
#define ASTPARSER_HPP_

#include "IParser.hpp"
#include <iostream>

namespace nts
{
  class ASTParser : public IParser
  {
  public:
    ASTParser();
    virtual ~ASTParser();
    virtual void feed(std::string const& input);
    virtual void parseTree(nts::t_ast_node& root);
    virtual nts::t_ast_node  *createTree();
  private:
    std::vector<std::string> _input;
  };
}

#endif
