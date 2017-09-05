#include "BF_Translator.h"

BF_Translator::BF_Translator()
{
  this->_map['+'] = "++t[i];";
  this->_map['-'] = "--t[i];";
  this->_map['>'] = "++i;";
  this->_map['<'] = "--i;";
  this->_map['.'] = "write(1, &t[i], 1);";
  this->_map[','] = "read(0, &t[i], 1);";
  this->_map['['] = "while (t[i]) {";
  this->_map[']'] = "}";
}

int BF_Translator::translate(std::string in, std::string out)
{
  std::ofstream output;
  output.open(out.c_str());
  if (!output.is_open())
    return -1;
  std::ifstream input;
  input.open(in.c_str());
  if (!input.is_open())
    return -1;
  output << "#include <stdio.h>" << std::endl;
  output << "#include <stdlib.h>" << std::endl;
  output << "#include <string.h>" << std::endl;
  output << "int main() {";
  output << "char t[60*1024];";
  output << "memset(t, 0, 60*1024);";
  output << "int i = 0;";
  char  c;
  while (input.good())
  {
    input.get(c);
    output << this->_map[c] << std::endl;
  }
  output << "return 0; }" << std::endl;
  output.close();
  input.close();
  return 0;
}
