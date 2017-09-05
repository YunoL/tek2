#include "Woody.h"

Woody::Woody (std::string const & name, std::string const & filename) : Toy(WOODY, name, filename)
{

}

Woody::~Woody ()
{

}

bool Woody::speak(std::string const & message)
{
  std::cout << "WOODY: " << this->_name << " \"" << message << "\"" << std::endl;
  return true;
}
