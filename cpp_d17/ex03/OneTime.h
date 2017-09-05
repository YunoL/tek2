#ifndef ONETIME_H_
#define ONETIME_H_

#include <iostream>
#include <cstdlib>
#include "IEncryptionMethod.h"

class OneTime : public IEncryptionMethod {
public:
  OneTime(std::string key);
  virtual ~OneTime();
  void encryptChar(char plainchar);
  void decryptChar(char cipherchar);
  void reset();
protected:
  std::string _key;
  int _index;
};

#endif
