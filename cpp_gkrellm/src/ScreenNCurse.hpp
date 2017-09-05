#ifndef SCREENNCURSE_HPP_
#define SCREENNCURSE_HPP_

#include "IMonitorDisplay.hpp"
#include "Monitor.hpp"
#include "ModRam.hpp"
#include <ncurses/curses.h>

class ScreenNCurse : public IMonitorDisplay {
public:
  ScreenNCurse();
  virtual ~ScreenNCurse();
  void refresh();
  void dump();
  WINDOW* _win;
private:
  void _getKey();
  int _scrollY;
};

#endif
