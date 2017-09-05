#ifndef CESAR_H_
#define CESAR_H_

#include <iostream>
#include <cstdio>
#include "IEncryptionMethod.h"

class Cesar : public IEncryptionMethod {
public:
  Cesar();
  virtual ~Cesar();
  void encryptChar(char plainchar);
  void decryptChar(char cipherchar);
  void reset();
protected:
  int _dec;
};

#endif
