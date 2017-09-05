//
// 4801.hpp for 4801 in /home/guillaume2.roux/rendu/cpp_nanotekspice/include/
//
// Made by guillaume2.roux
// Login   <guillaume2.roux@epitech.eu>
//
// Started on  Mon Feb  6 14:23:39 2017 guillaume2.roux
// Last update Fri Feb 10 09:50:49 2017 guillaume2.roux
//

#include "../../include/4801.hpp"

nts::C4801::C4801(std::string const &value)
{
  (void)value;
}

nts::C4801::~C4801()
{}

  nts::Tristate nts::C4801::Compute(size_t pin_num_this)
  {
    (void)pin_num_this;
    return (nts::Tristate::UNDEFINED);
  }

  void nts::C4801::SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target)
  {
    (void)pin_num_this;
    (void)component;
    (void)pin_num_target;
  }

  void nts::C4801::Dump(void) const
  {}
