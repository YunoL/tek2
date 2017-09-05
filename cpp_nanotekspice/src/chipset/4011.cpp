//
// 4011.hpp for 4011 in /home/guillaume2.roux/rendu/cpp_nanotekspice/include/
//
// Made by guillaume2.roux
// Login   <guillaume2.roux@epitech.eu>
//
// Started on  Mon Feb  6 14:19:14 2017 guillaume2.roux
// Last update Fri Feb 10 09:57:20 2017 guillaume2.roux
//

#include "../../include/4011.hpp"

nts::C4011::C4011(std::string const &value)
{
  (void)value;
}

nts::C4011::~C4011()
{}

nts::Tristate nts::C4011::Compute(size_t pin_num_this)
{
  (void)pin_num_this;
  return (nts::Tristate::UNDEFINED);
}

void nts::C4011::SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target)
{
  (void)pin_num_this;
  (void)component;
  (void)pin_num_target;
}

void nts::C4011::Dump(void) const
{}
