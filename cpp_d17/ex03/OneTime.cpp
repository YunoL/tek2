#include "OneTime.h"

OneTime::OneTime(std::string key) : _key(key), _index(0)
{}

OneTime::~OneTime()
{}

void OneTime::encryptChar(char plainchar)
{
  if (isalpha(plainchar))
  {
    int base = plainchar > 96 ? 97 : 65;
    int mask_base = this->_key[this->_index] > 96 ? 97 : 65;
    plainchar = (plainchar - base + (this->_key[this->_index] - mask_base)) % 26 + base;
  }
  std::cout << plainchar;
  this->_index = (this->_index + 1) % this->_key.size();
}

void OneTime::decryptChar(char cipherchar)
{
  if (isalpha(cipherchar))
  {
    int base = cipherchar > 96 ? 122 : 90;
    int mask_base = this->_key[this->_index] > 96 ? 97 : 65;
    cipherchar = (cipherchar - base - (this->_key[this->_index] - mask_base)) % 26 + base;
  }
  std::cout << cipherchar;
  this->_index = (this->_index + 1) % this->_key.size();
}

void OneTime::reset()
{
  this->_index = 0;
}
