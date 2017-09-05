#include "trade.hpp"

int main()
{
  int money;
  int totalDays;
  std::string currentCours;
  std::cin >> money;
  std::cin >> totalDays;

  Trade  retard(money, totalDays);

  std::cin >> currentCours;
  while (currentCours != "--END--")
  {
    retard.trading(atoi(currentCours.c_str()));
    std::cin >> currentCours;
  }
}
