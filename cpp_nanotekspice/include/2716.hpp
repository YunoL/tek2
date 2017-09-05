//
// 2716.hpp for 2716 in /home/guillaume2.roux/rendu/cpp_nanotekspice/include/
//
// Made by guillaume2.roux
// Login   <guillaume2.roux@epitech.eu>
//
// Started on  Mon Feb  6 14:23:55 2017 guillaume2.roux
// Last update Tue Feb  7 09:41:35 2017 guillaume2.roux
//

#ifndef C2716_HPP_
#define C2716_HPP_

#include "IComponent.hpp"
#include <iostream>

namespace nts
{
  class C2716 : public IComponent
  {
  public:
    C2716(std::string const &value);
    virtual ~C2716();
    virtual nts::Tristate Compute(size_t pin_num_this = 1);
    virtual void SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target);
    virtual void Dump(void) const;
  };
}

#endif
