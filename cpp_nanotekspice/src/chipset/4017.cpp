//
// 4017.hpp for 4017 in /home/guillaume2.roux/rendu/cpp_nanotekspice/include/
//
// Made by guillaume2.roux
// Login   <guillaume2.roux@epitech.eu>
//
// Started on  Mon Feb  6 14:20:58 2017 guillaume2.roux
// Last update Fri Feb 10 09:55:55 2017 guillaume2.roux
//

#include "../../include/4017.hpp"

nts::C4017::C4017(std::string const &value)
{
  (void)value;
}

nts::C4017::~C4017()
{}

nts::Tristate nts::C4017::Compute(size_t pin_num_this)
{
  (void)pin_num_this;
  return (nts::Tristate::UNDEFINED);
}

void nts::C4017::SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target)
{
  (void)pin_num_this;
  (void)component;
  (void)pin_num_target;
}

void nts::C4017::Dump(void) const
{}
