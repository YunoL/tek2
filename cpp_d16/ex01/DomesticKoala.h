#ifndef DOMESTICKOALA_H_
#define DOMESTICKOALA_H_

#include <iostream>
#include <vector>
#include <string>
#include "KoalaAction.h"

class DomesticKoala {
public:
  DomesticKoala(KoalaAction& act);
  DomesticKoala(const DomesticKoala& koala);
  virtual ~DomesticKoala();
  DomesticKoala& operator=(const DomesticKoala& koala);
  typedef void (KoalaAction::*methodPointer_t)(std::string const&);
  std::vector<methodPointer_t> const *getActions(void) const;
  void learnAction(unsigned char, methodPointer_t);
  void unlearnAction(unsigned char);
  void doAction(unsigned char, const std::string&);
  void setKoalaAction(KoalaAction&);
private:
  KoalaAction _action;
  std::vector<methodPointer_t> _theAct;
};

#endif
