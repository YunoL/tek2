#include "Parser.h"
#include <sstream>

std::string getCalc(std::string content, const int start, const int end_pos)
{
  int tmp = start;
  tmp++;
  return content.substr(tmp, (end_pos - tmp));
}

Parser::Parser()
{
  this->_result = 0;
  this->_cResult = 0;
}

Parser::~Parser()
{}

int isChiffre(char c)
{
  if (c >= 48 && c <= 57)
    return 1;
  return 0;
}

int nbCalc(const std::string &zizi)
{
  int i = 0;
  int nbChiffres = 0;
  while (zizi[i])
  {
    if (isChiffre(zizi[i]) == 1 && isChiffre(zizi[i + 1]) == 0)
      nbChiffres++;
    i++;
  }
  return nbChiffres;
}

void Parser::feed(const std::string& content)
{
  int i = 0;
  int start_pos = 0;
  int end_pos = 0;
  std::string calc = content;
  calc.erase(std::remove_if(calc.begin(), calc.end(), ::isspace), calc.end());
  int is_calc = nbCalc(calc);
  if (calc[0] != '(')
    calc = "(" + calc + ")";
  while (calc[i]) {
    if (calc[i] == '(') {
      start_pos = i;
    }
    if (calc[i] == ')') {
      end_pos = i;
      break;
    }
    i++;
  }
  if (is_calc > 1) {
    this->parseCalc(getCalc(calc, start_pos, end_pos));
    calc.erase(start_pos, (end_pos - start_pos + 1));
    std::stringstream os;
  	os << this->_cResult;
    calc.insert(start_pos, os.str());
    this->feed(calc);
    return;
  }
  this->_result += this->_cResult;

}

void  Parser::parseCalc(std::string calc)
{
  int i = 0;
  while (calc[i])
  {
    if (calc[i] == '*' || calc[i] == '+' || calc[i] == '-' || calc[i] == '%' || calc[i] == '/')
    {
      std::string op(1, calc[i]);
      this->operators.push(op);
      this->operands.push(calc.substr(0, i));
      i++;
      this->operands.push(calc.substr(i, strlen(calc.c_str())));
      break;
    }
    i++;
  }
  this->makeCalc();
}

void Parser::makeCalc()
{
  int nb1 = atoi(this->operands.top().c_str());
  this->operands.pop();
  int nb2 = atoi(this->operands.top().c_str());
  if (this->operators.top() == "+")
    this->_cResult = nb2 + nb1;
  if (this->operators.top() == "-")
    this->_cResult = nb2 - nb1;
  if (this->operators.top() == "/")
    this->_cResult = nb2 / nb1;
  if (this->operators.top() == "%")
    this->_cResult = nb2 % nb1;
  if (this->operators.top() == "*")
    this->_cResult = nb2 * nb1;
  this->operators.pop();
}

void Parser::reset()
{
    std::stack<std::string> clear;
    this->operators = clear;
    this->operands = clear;
    this->_result = 0;
    this->_cResult = 0;
}

int Parser::result() const
{
  return this->_result;
}
