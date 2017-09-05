//
// ASTParser.cpp for astparser in /home/guillaume2.roux/rendu/cpp_nanotekspice/src/
//
// Made by guillaume2.roux
// Login   <guillaume2.roux@epitech.eu>
//
// Started on  Wed Jan 25 11:12:16 2017 guillaume2.roux
// Last update Thu Mar  2 15:45:00 2017 Guillaume Roux
//

#include "../include/ASTParser.hpp"

nts::ASTParser::ASTParser()
{}

nts::ASTParser::~ASTParser()
{}

void  nts::ASTParser::feed(std::string const& input)
{
  std::string tmp = input;
  size_t  pos = input.find_first_of("#");
  if (pos != std::string::npos)
    tmp = input.substr(0, pos);
  if (tmp.find_first_not_of(" \t") != std::string::npos)
    this->_input.push_back(tmp);
}

void nts::ASTParser::parseTree(t_ast_node& root)
{
  (void)root;
}

nts::t_ast_node* nts::ASTParser::createTree()
{
  t_ast_node *tmp = NULL;
  return tmp;
}
