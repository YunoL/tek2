//
// 2716.cpp for 2716 in /home/guillaume2.roux/rendu/cpp_nanotekspice/src/chipset/
//
// Made by guillaume2.roux
// Login   <guillaume2.roux@epitech.eu>
//
// Started on  Mon Feb  6 14:28:54 2017 guillaume2.roux
// Last update Thu Feb  9 10:26:19 2017 guillaume2.roux
//

#include "../../include/2716.hpp"

nts::C2716::C2716(std::string const &value)
{
  (void)value;
}

nts::C2716::~C2716()
{}

nts::Tristate nts::C2716::Compute(size_t pin_num_this)
{
  (void)pin_num_this;
  return (nts::Tristate::UNDEFINED);
}

void nts::C2716::SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target)
{
  (void)pin_num_this;
  (void)component;
  (void)pin_num_target;
}

void nts::C2716::Dump(void) const
{}
