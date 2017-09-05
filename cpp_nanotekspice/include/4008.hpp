//
// 4008.hpp for 4008 in /home/guillaume2.roux/rendu/cpp_nanotekspice/include/
//
// Made by guillaume2.roux
// Login   <guillaume2.roux@epitech.eu>
//
// Started on  Mon Feb  6 14:18:58 2017 guillaume2.roux
// Last update Tue Feb  7 09:41:22 2017 guillaume2.roux
//

#ifndef C4008_HPP_
#define C4008_HPP_

#include "IComponent.hpp"
#include <iostream>

namespace nts
{
  class C4008 : public IComponent
  {
  public:
    C4008(std::string const &value);
    virtual ~C4008();
    virtual nts::Tristate Compute(size_t pin_num_this = 1);
    virtual void SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target);
    virtual void Dump(void) const;
  };
}

#endif