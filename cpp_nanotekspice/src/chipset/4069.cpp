//
// 4069.hpp for 4069 in /home/guillaume2.roux/rendu/cpp_nanotekspice/include/
//
// Made by guillaume2.roux
// Login   <guillaume2.roux@epitech.eu>
//
// Started on  Mon Feb  6 14:21:59 2017 guillaume2.roux
// Last update Fri Feb 10 09:54:20 2017 guillaume2.roux
//

#include "../../include/4069.hpp"

nts::C4069::C4069(std::string const &value)
{
  (void)value;
}

nts::C4069::~C4069()
{}

nts::Tristate nts::C4069::Compute(size_t pin_num_this)
{
  (void)pin_num_this;
  return (nts::Tristate::UNDEFINED);
}

void nts::C4069::SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target)
{
  (void)pin_num_this;
  (void)component;
  (void)pin_num_target;
}

void nts::C4069::Dump(void) const
{}
