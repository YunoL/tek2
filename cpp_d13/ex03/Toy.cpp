#include "Toy.h"

Toy::Toy() : _type(BASIC_TOY), _name("toy")
{
  this->_picture.data = "";
}

Toy::Toy(ToyType type, std::string const &name, std::string const &ascii) : _type(type), _name(name), _picture(ascii)
{

}

Toy::Toy(Toy const & copy) : _type(copy._type), _name(copy._name), _picture(copy._picture)
{

}

Toy::~Toy()
{

}

int  Toy::getType() const
{
  return this->_type;
}

std::string const &Toy::getName() const
{
  return this->_name;
}

std::string const &Toy::getAscii() const
{
  return this->_picture.data;
}

void Toy::setName(std::string const &name)
{
  this->_name = name;
}

void Toy::setAscii(std::string const &picture)
{
  this->_picture.getPictureFromFile(picture);
}

Toy&  Toy::operator=(Toy const &toy)
{
  this->_type = toy._type;
  this->_name = toy._name;
  this->_picture = toy._picture;
  return *this;
}

void Toy::speak(std::string const & message)
{
  std::cout << this->_name << " \"" << message << "\"" << std::endl;
}
