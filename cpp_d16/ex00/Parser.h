#ifndef PARSER_H_
#define PARSER_H_

#include <iostream>
#include <algorithm>
#include <stack>
#include <cstring>

class Parser {
public:
  Parser();
  virtual ~Parser();
  void feed(const std::string& content);
  void reset();
  int result() const;
  void  parseCalc(std::string calc);
  void makeCalc();
protected:
  int _result;
  int _cResult;
  std::stack<std::string> operators;
  std::stack<std::string> operands;
};

#endif
