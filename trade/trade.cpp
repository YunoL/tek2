#include "trade.hpp"

Trade::Trade(int money, int totalDay) : _money(money), _totalDay(totalDay), _nbActions(0), _currentDay(0)
{}

Trade::~Trade()
{}

void Trade::wait()
{
  std::cout << "wait" << '\n';
}

void Trade::sell(int currentCours, int nbActions)
{
  if (nbActions > this->_nbActions)
    nbActions = this->_nbActions;
  if (nbActions > 0)
  {
    this->_nbActions -= nbActions;
    this->_money += ((nbActions * currentCours) - (0.0015 * nbActions * currentCours));
    std::cout << "sell " << nbActions << '\n';
  }
  else
    this->wait();
}

void Trade::buy(int currentCours, int nbActions)
{
  while ((nbActions * currentCours) + (0.0015 * nbActions * currentCours) > this->_money)
		nbActions--;
	if (nbActions != 0)
	{
		this->_nbActions += nbActions;
		this->_money -= ((nbActions * currentCours) + (0.0015 * nbActions * currentCours));
		std::cout << "buy " << nbActions << std::endl;
	}
	else
		this->wait();
}

void Trade::addValue(int currentCours)
{
  this->_oldValues.push_front(currentCours);
}

void Trade::init(int &moy, int &var, int &currentCours)
{
  int i = 0;
  std::list<int>::iterator it = this->_oldValues.begin();
  moy = 0;
  while (it != this->_oldValues.end())
  {
    if (i < NB_WAIT)
      moy += (*it);
    else
      break;
    i++;
    ++it;
  }
  moy /= i;
  i = 0;
  var = 0;
  it = this->_oldValues.begin();
  while (it != this->_oldValues.end())
  {
    if (i < NB_WAIT)
      var += pow(((*it) - moy), 2);
    else
      break;
    i++;
    ++it;
  }
  var /= i;
  currentCours = sqrt(var);
}

int Trade::checkValue(int currentCours)
{
  int i = 0, moy = 0, var = 0, ecartType = 0;
  this->init(moy, var, ecartType);
  if (currentCours > moy + ecartType)
    return 1;
  else if (currentCours < moy - ecartType)
    return -1;
  else
    return 0;
}

void Trade::trading(int currentCours)
{
  int nb;
  if (this->_currentDay == this->_totalDay)
    this->sell(currentCours, this->_nbActions);
  else if (this->_oldValues.size() < NB_WAIT)
    this->wait();
  else
  {
    nb = this->checkValue(currentCours);
    if (nb > 0)
      this->buy(currentCours, nb);
    else if (nb < 0)
      this->sell(currentCours, 0 - nb);
    else
      this->wait();
  }
  this->addValue(currentCours);
  this->_currentDay+=1;
}
