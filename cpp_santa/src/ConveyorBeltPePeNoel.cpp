//
// ConveyorBeltPePeNoel.cpp for in .../rush_cpp_2
//
// Made by  syp_s
// Login    <steven.syp@epitech.eu@epitech.eu>
//
// Started on  14/01/2017 Steven Syp
//

#include "ConveyorBeltPePeNoel.hh"

IConveyorBelt::~IConveyorBelt() {}

ConveyorBeltPePeNoel::ConveyorBeltPePeNoel() {
  this->_actWrap = NULL;
}

ConveyorBeltPePeNoel::~ConveyorBeltPePeNoel() {}

Wrap *ConveyorBeltPePeNoel::IN() {
  if (this->_actWrap) {
    std::cerr << "There's already something on the ConveyorBelt." << '\n';
    return NULL;
  }

  srand (time(NULL));
  bool isGiftPaper = rand() % 2;

  if (isGiftPaper)
    this->_actWrap = new GiftPaper("papier");
  else
    this->_actWrap = new Box("boite");
  return this->_actWrap;
}

bool ConveyorBeltPePeNoel::OUT(Object *obj) {
  if (!this->_actWrap) {
    std::cerr << "Need to put something on the ConveyorBelt to send it to Santa Calus." << '\n';
    return false;
  }
  std::cout << "One new " << obj->getName() << " sent to Santa !"<< '\n';
  delete this->_actWrap;
  this->_actWrap = NULL;
  return true;
}

std::string const ConveyorBeltPePeNoel::look() {
  if (!this->_actWrap)
    return NULL;
  return this->_actWrap->getName();
}

IConveyorBelt*  createConveyorBelt() {
  return new ConveyorBeltPePeNoel;
}
