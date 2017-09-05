#include "Buzz.h"

Buzz::Buzz(std::string const &name, std::string const &filename) : Toy(BUZZ, name, filename)
{

}

Buzz::~Buzz()
{

}

void Buzz::speak(std::string const & message)
{
  std::cout << "BUZZ: " << this->_name << " \"" << message << "\"" << std::endl;
}

bool Buzz::speak_es(std::string const & message)
{
  std::cout << "BUZZ: " << this->_name << " senorita \"" << message << "\" senorita" << std::endl;
  return true;
}
