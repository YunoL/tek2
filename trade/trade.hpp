#ifndef TRADE_HPP_
#define TRADE_HPP_

#include <iostream>
#include <cstdlib>
#include <list>
#include <cmath>
#include <unistd.h>

#define NB_WAIT (7)
#define MIN_ACTION (10)

class Trade
{
private:
  int _money;
  int _totalDay;
  int _currentDay;
  int _nbActions;
  std::list<int> _oldValues;
public:
  Trade(int money, int totalDay);
  virtual ~Trade();
  void trading(int currentCours);
  void wait();
  void sell(int currentCours, int nbActions);
  void buy(int currentCours, int nb);
  void addValue(int currentCours);
  int checkValue(int currentCours);
  void init(int &moy, int &var, int &currentCours);
};

#endif
