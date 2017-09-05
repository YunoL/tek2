//
// 4011.hpp for 4011 in /home/guillaume2.roux/rendu/cpp_nanotekspice/include/
//
// Made by guillaume2.roux
// Login   <guillaume2.roux@epitech.eu>
//
// Started on  Mon Feb  6 14:19:14 2017 guillaume2.roux
// Last update Tue Feb  7 09:41:16 2017 guillaume2.roux
//

#ifndef C4011_HPP_
#define C4011_HPP_

#include "IComponent.hpp"
#include <iostream>

namespace nts
{
  class C4011 : public IComponent
  {
  public:
    C4011(std::string const &value);
    virtual ~C4011();
    virtual nts::Tristate Compute(size_t pin_num_this = 1);
    virtual void SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target);
    virtual void Dump(void) const;
  };
}

#endif
