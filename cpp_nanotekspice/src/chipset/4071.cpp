//
// 4071.hpp for 4071 in /home/guillaume2.roux/rendu/cpp_nanotekspice/include/
//
// Made by guillaume2.roux
// Login   <guillaume2.roux@epitech.eu>
//
// Started on  Mon Feb  6 14:22:24 2017 guillaume2.roux
// Last update Fri Feb 10 09:53:37 2017 guillaume2.roux
//

#include "../../include/4071.hpp"

nts::C4071::C4071(std::string const &value)
{
  (void)value;
}

nts::C4071::~C4071()
{}

nts::Tristate nts::C4071::Compute(size_t pin_num_this)
{
  (void)pin_num_this;
  return (nts::Tristate::UNDEFINED);
}

void nts::C4071::SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target)
{
  (void)pin_num_this;
  (void)component;
  (void)pin_num_target;
}

void nts::C4071::Dump(void) const
{}
