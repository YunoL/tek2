#ifndef MONITOR_HPP_
#define MONITOR_HPP_

#include "IMonitorModule.hpp"
#include "IMonitorDisplay.hpp"
#include <iostream>
#include <list>
#include <unistd.h>

class IMonitorModule;

class Monitor {
public:
  Monitor();
  virtual ~Monitor();
  void  run(ScreenNCurse disp);
  void  stop();
  void setDisplay(IMonitorDisplay* module);
  void addModule(IMonitorModule* module);
  void removeModule(IMonitorModule*);
  void refresh();
  void dump();
  std::list<IMonitorModule*>& getModules();
  static Monitor* getInstance();
protected:
  IMonitorDisplay*  _display;
  std::list<IMonitorModule*> _modules;
  int _elapsedTime;
  bool  _isRunning;
};

#endif
