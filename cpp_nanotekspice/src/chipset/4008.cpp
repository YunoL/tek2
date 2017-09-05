//
// 4008.hpp for 4008 in /home/guillaume2.roux/rendu/cpp_nanotekspice/include/
//
// Made by guillaume2.roux
// Login   <guillaume2.roux@epitech.eu>
//
// Started on  Mon Feb  6 14:18:58 2017 guillaume2.roux
// Last update Fri Feb 10 09:57:47 2017 guillaume2.roux
//

#include "../../include/4008.hpp"

nts::C4008::C4008(std::string const &value)
{
  (void)value;
}

nts::C4008::~C4008()
{}

nts::Tristate nts::C4008::Compute(size_t pin_num_this)
{
  (void)pin_num_this;
  return (nts::Tristate::UNDEFINED);
}

void nts::C4008::SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target)
{
  (void)pin_num_this;
  (void)component;
  (void)pin_num_target;
}

void nts::C4008::Dump(void) const
{}
