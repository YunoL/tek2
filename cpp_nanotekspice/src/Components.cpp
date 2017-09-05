//
// Components.cpp for Components.cpp in /home/guillaume2.roux/rendu/cpp_nanotekspice/src/
//
// Made by guillaume2.roux
// Login   <guillaume2.roux@epitech.eu>
//
// Started on  Wed Feb  8 11:22:08 2017 guillaume2.roux
// Last update Thu Feb  9 10:13:46 2017 guillaume2.roux
//

#include "../include/Components.hpp"

nts::Components::Components()
{}

nts::Components::~Components()
{}

nts::IComponent* nts::Components::create2716(const std::string &value) const
{
  return (new C2716(value));
}

nts::IComponent* nts::Components::create4001(const std::string &value) const
{
  return (new C4001(value));
}

nts::IComponent* nts::Components::create4008(const std::string &value) const
{
  return (new C4008(value));
}

nts::IComponent* nts::Components::create4011(const std::string &value) const
{
  return (new C4011(value));
}

nts::IComponent* nts::Components::create4013(const std::string &value) const
{
  return (new C4013(value));
}

nts::IComponent* nts::Components::create4017(const std::string &value) const
{
  return (new C4017(value));
}

nts::IComponent* nts::Components::create4030(const std::string &value) const
{
  return (new C4030(value));
}

nts::IComponent* nts::Components::create4040(const std::string &value) const
{
  return (new C4040(value));
}

nts::IComponent* nts::Components::create4069(const std::string &value) const
{
  return (new C4069(value));
}

nts::IComponent* nts::Components::create4071(const std::string &value) const
{
  return (new C4071(value));
}

nts::IComponent* nts::Components::create4081(const std::string &value) const
{
  return (new C4081(value));
}

nts::IComponent* nts::Components::create4094(const std::string &value) const
{
  return (new C4094(value));
}

nts::IComponent* nts::Components::create4514(const std::string &value) const
{
  return (new C4514(value));
}

nts::IComponent* nts::Components::create4801(const std::string &value) const
{
  return (new C4801(value));
}
