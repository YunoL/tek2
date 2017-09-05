//
// Components.hpp for components in /home/guillaume2.roux/rendu/cpp_nanotekspice/include/
//
// Made by guillaume2.roux
// Login   <guillaume2.roux@epitech.eu>
//
// Started on  Wed Feb  8 09:46:01 2017 guillaume2.roux
// Last update Thu Feb  9 10:12:02 2017 guillaume2.roux
//

#ifndef COMPONENTS_HPP_
#define COMPONENTS_HPP_

#include <iostream>
#include <map>
#include "IComponent.hpp"
#include "2716.hpp"
#include "4001.hpp"
#include "4008.hpp"
#include "4011.hpp"
#include "4013.hpp"
#include "4017.hpp"
#include "4030.hpp"
#include "4040.hpp"
#include "4069.hpp"
#include "4071.hpp"
#include "4081.hpp"
#include "4094.hpp"
#include "4514.hpp"
#include "4801.hpp"

namespace nts
{
  class Components
  {
  public:
    Components();
    virtual ~Components();
    IComponent *createComponent(const std::string &type, const std::string &value);
  private:
    nts::IComponent* create2716(const std::string &value) const;
    nts::IComponent* create4001(const std::string &value) const;
    nts::IComponent* create4008(const std::string &value) const;
    nts::IComponent* create4011(const std::string &value) const;
    nts::IComponent* create4013(const std::string &value) const;
    nts::IComponent* create4017(const std::string &value) const;
    nts::IComponent* create4030(const std::string &value) const;
    nts::IComponent* create4040(const std::string &value) const;
    nts::IComponent* create4069(const std::string &value) const;
    nts::IComponent* create4071(const std::string &value) const;
    nts::IComponent* create4081(const std::string &value) const;
    nts::IComponent* create4094(const std::string &value) const;
    nts::IComponent* create4514(const std::string &value) const;
    nts::IComponent* create4801(const std::string &value) const;
  };
}

#endif
