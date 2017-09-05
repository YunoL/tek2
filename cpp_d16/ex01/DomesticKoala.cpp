#include "DomesticKoala.h"

DomesticKoala::DomesticKoala(KoalaAction& action) : _action(action), _theAct(256)
{}

DomesticKoala::~DomesticKoala()
{}

DomesticKoala::DomesticKoala(DomesticKoala const& koala) : _action(koala._action), _theAct(koala._theAct)
{}

DomesticKoala& DomesticKoala::operator=(DomesticKoala const& koala)
{
    this->_action = koala._action;
    this->_theAct = koala._theAct;
    return *this;
}

std::vector<DomesticKoala::methodPointer_t> const*  DomesticKoala::getActions() const
{
    return &this->_theAct;
}

void DomesticKoala::learnAction(unsigned char c, methodPointer_t ptr)
{
    this->_theAct[c] = ptr;
}

void DomesticKoala::unlearnAction(unsigned char c)
{
    this->_theAct[c] = NULL;
}

void DomesticKoala::doAction(unsigned char c, std::string const& str)
{
    methodPointer_t func = this->_theAct[c];
    if (func)
        (this->_action.*func)(str);
}

void DomesticKoala::setKoalaAction(KoalaAction& action)
{
    this->_action = action;
}
