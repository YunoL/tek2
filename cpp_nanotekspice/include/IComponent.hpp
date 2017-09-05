//
// IComponent.hpp for icomponent in /home/guillaume2.roux/rendu/cpp_nanotekspice/include/
//
// Made by guillaume2.roux
// Login   <guillaume2.roux@epitech.eu>
//
// Started on  Wed Jan 25 08:27:16 2017 guillaume2.roux
// Last update Thu Feb  9 10:14:32 2017 guillaume2.roux
//

#ifndef __ICOMPONENT_HPP__
#define __ICOMPONENT_HPP__

#include <iostream>

namespace nts
{
  enum Tristate
  {
    UNDEFINED = (-true),
    TRUE = true,
    FALSE = false
  };

  class IComponent
  {
  public:
    /// Compute value of the precised pin
    virtual nts::Tristate Compute(size_t pin_num_this = 1) = 0;

    /// Useful to link IComponent together
    virtual void SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target) = 0;

    ///// Print on terminal the name of the component and
    //// the state of every pin of the current component
    /// The output won't be tested, but it may help you
    // as a trace
    virtual void Dump(void) const = 0;

    virtual ~IComponent(void) {};
  };
}

#endif
