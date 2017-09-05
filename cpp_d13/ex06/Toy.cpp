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

bool Toy::setAscii(std::string const &picture)
{
  if (!this->_picture.getPictureFromFile(picture))
  {
    this->error.setType(Error::PICTURE);
    return false;
  }
  return true;
}

Toy&  Toy::operator=(Toy const &toy)
{
  this->_type = toy._type;
  this->_name = toy._name;
  this->_picture = toy._picture;
  return *this;
}

bool Toy::speak(std::string const & message)
{
  std::cout << this->_name << " \"" << message << "\"" << std::endl;
  return true;
}

bool Toy::speak_es(std::string const & message)
{
  (void)message;
  this->error.setType(Error::SPEAK);
  return false;
}

Toy& Toy::operator<<(std::string const & message)
{
  this->_picture.data = message;
  return *this;
}

Toy::Error const & Toy::getLastError() const
{
  return this->error;
}

Toy::Error::Error() : type(UNKNOWN)
{

}

void Toy::Error::setType(ErrorType type)
{
	this->type = type;
}

std::string Toy::Error::what() const
{
  if (this->type == PICTURE)
    return "bad new illustration";
  else if (this->type == SPEAK)
    return "wrong mode";
  else
    return "";
}

std::string Toy::Error::where() const
{
  if (this->type == PICTURE)
    return "setAscii";
  else if (this->type == SPEAK)
    return "speak_es";
  else
    return "";
}

std::ostream & operator<<(std::ostream & os, Toy const & obj)
{
  return (os << obj.getName() << std::endl << obj.getAscii() << std::endl);
}
