#include "Encryption.h"

Encryption::Encryption(IEncryptionMethod& encryptionMethod, IEMethod method) : _encrypt(&encryptionMethod), _method(method)
{}

Encryption::~Encryption()
{}

void Encryption::operator()(char c)
{
  (this->_encrypt->*this->_method)(c);
}

void Encryption::encryptString(IEncryptionMethod& methode, std::string const& str)
{
  methode.reset();
  std::for_each(str.begin(), str.end(), Encryption(methode, &IEncryptionMethod::encryptChar));
  std::cout << std::endl;
}

void Encryption::decryptString(IEncryptionMethod& methode, std::string const& str)
{
    methode.reset();
    std::for_each(str.begin(), str.end(), Encryption(methode, &IEncryptionMethod::decryptChar));
    std::cout << std::endl;
}
