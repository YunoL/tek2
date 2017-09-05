//
// 4094.hpp for 4094 in /home/guillaume2.roux/rendu/cpp_nanotekspice/include/
//
// Made by guillaume2.roux
// Login   <guillaume2.roux@epitech.eu>
//
// Started on  Mon Feb  6 14:22:53 2017 guillaume2.roux
// Last update Fri Feb 10 09:52:13 2017 guillaume2.roux
//

#include "../../include/4094.hpp"

nts::C4094::C4094(std::string const &value)
{
  (void)value;
}

nts::C4094::~C4094()
{}

nts::Tristate nts::C4094::Compute(size_t pin_num_this)
{
  (void)pin_num_this;
  return (nts::Tristate::UNDEFINED);
}

void nts::C4094::SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target)
{
  (void)pin_num_this;
  (void)component;
  (void)pin_num_target;
}

void nts::C4094::Dump(void) const
{}
