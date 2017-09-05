#ifndef TOYSTORY_H_
#define TOYSTORY_H_

#include <string>
#include <iostream>
#include <fstream>
#include "Toy.h"

class ToyStory {
public:
  ToyStory() {}
  ~ToyStory() {}
  static void tellMeAStory(std::string const &filename,
		    Toy &toy1,
		    bool (Toy::*func1)(std::string const &str1),
		    Toy &toy2,
		    bool (Toy::*func2)(std::string const &str2));
};

#endif
