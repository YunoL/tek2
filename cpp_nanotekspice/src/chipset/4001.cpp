//
// 4001.hpp for 4001 in /home/guillaume2.roux/rendu/cpp_nanotekspice/include/
//
// Made by guillaume2.roux
// Login   <guillaume2.roux@epitech.eu>
//
// Started on  Mon Feb  6 14:18:15 2017 guillaume2.roux
// Last update Fri Feb 10 09:58:17 2017 guillaume2.roux
//

#include "../../include/4001.hpp"

nts::C4001::C4001(std::string const &value)
{
  (void)value;
}

nts::C4001::~C4001()
{}

nts::Tristate nts::C4001::Compute(size_t pin_num_this)
{
  (void)pin_num_this;
  return (nts::Tristate::UNDEFINED);
}

void nts::C4001::SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target)
{
  (void)pin_num_this;
  (void)component;
  (void)pin_num_target;
}

void nts::C4001::Dump(void) const
{}
