#include "Ratatouille.h"

Ratatouille::Ratatouille()
{
  this->os << "";
}

Ratatouille::Ratatouille(Ratatouille const& copy)
{
  this->os << copy.os.str();
}

Ratatouille::~Ratatouille()
{}

Ratatouille& Ratatouille::operator=(Ratatouille const& copy)
{
  this->os.str("");
  this->os << copy.os.str();
  return *this;
}

Ratatouille& Ratatouille::addVegetable(unsigned char c)
{
  this->os << c;
  return *this;
}

Ratatouille& Ratatouille::addCondiment(unsigned int i)
{
  this->os << i;
  return *this;
}

Ratatouille& Ratatouille::addSpice(double spice)
{
  this->os << spice;
  return *this;
}

Ratatouille& Ratatouille::addSauce(const std::string &sauce)
{
  this->os << sauce;
  return *this;
}

std::string Ratatouille::kooc(void)
{
  return this->os.str();
}
