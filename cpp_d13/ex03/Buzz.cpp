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
