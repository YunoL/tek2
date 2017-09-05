#include "Buzz.h"

Buzz::Buzz(std::string const &name, std::string const &filename) : Toy(BUZZ, name, filename)
{

}

Buzz::~Buzz()
{

}

bool Buzz::speak(std::string const & message)
{
  std::cout << "BUZZ: " << this->_name << " \"" << message << "\"" << std::endl;
  return true;
}

bool Buzz::speak_es(std::string const & message)
{
  std::cout << "BUZZ: " << this->_name << " senorita \"" << message << "\" senorita" << std::endl;
  return true;
}
