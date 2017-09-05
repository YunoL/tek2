#ifndef ENCRYPTTION_H_
#define ENCRYPTTION_H_

#include <iostream>
#include <algorithm>
#include "IEncryptionMethod.h"

typedef void (IEncryptionMethod::*IEMethod)(char c);

class Encryption {
public:
  Encryption(IEncryptionMethod& encryptionMethod, IEMethod method);
  virtual ~Encryption();
  void operator()(char c);
  static void encryptString(IEncryptionMethod& methode, std::string const& str);
  static void decryptString(IEncryptionMethod& methode, std::string const& str);
private:
  IEncryptionMethod* _encrypt;
  IEMethod _method;
};

#endif
