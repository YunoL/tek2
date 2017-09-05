#ifndef MODRAM_HPP_
#define MODRAM_HPP_

#include "AModule.hpp"
#include "IMonitorModule.hpp"

class ModRam
{
public:
  ModRam();
  virtual ~ModRam();
  int getRefreshRate() const;
  int getLastRefresh() const;
  void setLastRefresh(int value);
private:
  int _lastRefresh;
  int _refreshRate;
  std::string _title;
};

#endif
