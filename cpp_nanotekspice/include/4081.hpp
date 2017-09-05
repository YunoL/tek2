//
// 4081.hpp for 4081 in /home/guillaume2.roux/rendu/cpp_nanotekspice/include/
//
// Made by guillaume2.roux
// Login   <guillaume2.roux@epitech.eu>
//
// Started on  Mon Feb  6 12:23:47 2017 guillaume2.roux
// Last update Tue Feb  7 09:40:32 2017 guillaume2.roux
//

#ifndef C4081_HPP_
#define C4081_HPP_

#include "IComponent.hpp"
#include <iostream>

namespace nts
{
  class C4081 : public IComponent
  {
  public:
    C4081(std::string const &value);
    virtual ~C4081();
    virtual nts::Tristate Compute(size_t pin_num_this = 1);
    virtual void SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target);
    virtual void Dump(void) const;
  };
}

#endif
