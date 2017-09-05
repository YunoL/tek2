#ifndef BF_TRANSLATOR_H_
#define BF_TRANSLATOR_H_

#include <iostream>
#include <map>
#include <fstream>

class BF_Translator {
public:
  BF_Translator();
  int translate(std::string in, std::string out);
  std::map<unsigned char, std::string> _map;
};

#endif
