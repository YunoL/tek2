//
// 4081.cpp for 4091 in /home/guillaume2.roux/rendu/cpp_nanotekspice/src/chipset/
//
// Made by guillaume2.roux
// Login   <guillaume2.roux@epitech.eu>
//
// Started on  Mon Feb  6 12:22:52 2017 guillaume2.roux
// Last update Fri Feb 10 09:53:00 2017 guillaume2.roux
//

#include "../../include/4081.hpp"

nts::C4081::C4081(std::string const &value)
{
  (void)value;
}

nts::C4081::~C4081()
{}

nts::Tristate nts::C4081::Compute(size_t pin_num_this)
{
  (void)pin_num_this;
  return (nts::Tristate::UNDEFINED);
}

void nts::C4081::SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target)
{
  (void)pin_num_this;
  (void)component;
  (void)pin_num_target;
}

void nts::C4081::Dump(void) const
{}
