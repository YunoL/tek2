//
// IParser.hpp for iparser in /home/guillaume2.roux/rendu/cpp_nanotekspice/include/
//
// Made by guillaume2.roux
// Login   <guillaume2.roux@epitech.eu>
//
// Started on  Wed Jan 25 08:50:08 2017 guillaume2.roux
// Last update Fri Feb 10 09:48:53 2017 guillaume2.roux
//

#ifndef CPP_NANOTEKSPICE_PARSER_HPP
#define CPP_NANOTEKSPICE_PARSER_HPP

#include <string>
#include <vector>

namespace nts
{
  // The type of a node in the tree
  enum class ASTNodeType : int
  {
    DEFAULT = -1,
    NEWLINE = 0,
    SECTION,
    COMPONENT,
    LINK,
    LINK_END,
    STRING
  };

  // A node of the output tree
  typedef struct s_ast_node
  {
    s_ast_node(std::vector<struct s_ast_node*> *children) : children(children) {}
    std::string lexeme;
    ASTNodeType type;
    std::string value;
    std::vector<struct s_ast_node*> *children;
  } t_ast_node;

  // The actual interface
  class IParser
  {
  public:
    // Appends the string to the current input
    virtual void feed(std::string const& input) = 0;

    // Takes the AST root and goes through the whole tree
    virtual void parseTree(t_ast_node& root) = 0;

    // Parses the input string to produce the output tree
    virtual t_ast_node  *createTree() = 0;

    virtual ~IParser(void) {};
  };
}

#endif
