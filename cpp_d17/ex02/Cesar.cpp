#include "Cesar.h"

Cesar::Cesar() : _dec(3)
{}

Cesar::~Cesar()
{}

void Cesar::encryptChar(char plainchar)
{
    if (isalpha(plainchar))
    {
      int base = plainchar > 96 ? 97 : 65;
      plainchar = (plainchar - base + this->_dec) % 26 + base;
    }
    this->_dec = (this->_dec + 1) % 26;
    std::cout << plainchar;
}

void Cesar::decryptChar(char cipherchar)
{
  if (isalpha(cipherchar))
  {
    int base = cipherchar > 96 ? 122 : 90;
    cipherchar = (cipherchar - base - this->_dec) % 26 + base;
  }
  this->_dec = (this->_dec + 1) % 26;
  std::cout << cipherchar;
}

void Cesar::reset()
{
  this->_dec = 3;
}
