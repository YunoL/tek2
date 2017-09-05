#ifndef IMONITORDISPLAY_HPP_
#define IMONITORDISPLAY_HPP_

#include <iostream>

class IMonitorDisplay {
public:
  virtual ~IMonitorDisplay() {}
  virtual void refresh() = 0;
  virtual void dump() = 0;
};

#endif
