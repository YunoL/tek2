//
// 4030.hpp for 4030 in /home/guillaume2.roux/rendu/cpp_nanotekspice/include/
//
// Made by guillaume2.roux
// Login   <guillaume2.roux@epitech.eu>
//
// Started on  Mon Feb  6 14:21:16 2017 guillaume2.roux
// Last update Fri Feb 10 09:55:27 2017 guillaume2.roux
//

#include "../../include/4030.hpp"

nts::C4030::C4030(std::string const &value)
{
  (void)value;
}

nts::C4030::~C4030()
{}

nts::Tristate nts::C4030::Compute(size_t pin_num_this)
{
  (void)pin_num_this;
  return (nts::Tristate::UNDEFINED);
}

void nts::C4030::SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target)
{
  (void)pin_num_this;
  (void)component;
  (void)pin_num_target;
}

void nts::C4030::Dump(void) const
{}
