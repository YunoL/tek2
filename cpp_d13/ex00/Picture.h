#ifndef PICTURE_H_
#define PICTURE_H_

#include <fstream>
#include <iostream>

class Picture {
public:
  Picture();
  Picture (const std::string& file);
  virtual ~Picture ();
  std::string data;
  bool  getPictureFromFile(const std::string& file);
};

#endif
