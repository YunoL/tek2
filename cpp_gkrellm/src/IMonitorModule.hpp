#ifndef IMONITORMODULE_HPP_
#define IMONITORMODULE_HPP_

#include <iostream>
#include "ScreenNCurse.hpp"
#include "AModule.hpp"

class ScreenNCurse;
class IMonitorModule;

class IMonitorModule {
public:
  IMonitorModule() {};
  virtual ~IMonitorModule() {};
  virtual void refresh();
  virtual int getRefreshRate() const = 0;
  virtual int getLastRefresh() const = 0;
  virtual void setLastRefresh(int value);
  virtual void dump(ScreenNCurse&, int x, int y) const = 0;
};

#endif
