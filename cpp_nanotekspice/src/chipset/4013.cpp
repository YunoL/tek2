//
// 4013.hpp for 4013 in /home/guillaume2.roux/rendu/cpp_nanotekspice/include/
//
// Made by guillaume2.roux
// Login   <guillaume2.roux@epitech.eu>
//
// Started on  Mon Feb  6 14:19:35 2017 guillaume2.roux
// Last update Fri Feb 10 09:56:30 2017 guillaume2.roux
//

#include "../../include/4013.hpp"

nts::C4013::C4013(std::string const &value)
{
  (void)value;
}

nts::C4013::~C4013()
{}

nts::Tristate nts::C4013::Compute(size_t pin_num_this)
{
  (void)pin_num_this;
  return (nts::Tristate::UNDEFINED);
}

void nts::C4013::SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target)
{
  (void)pin_num_this;
  (void)component;
  (void)pin_num_target;
}

void nts::C4013::Dump(void) const
{}
