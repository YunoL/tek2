#include "ScreenNCurse.hpp"

ScreenNCurse::ScreenNCurse()
{
  WINDOW  *win = NULL;
  this->_win = win;
  initscr();
  keypad(stdscr, TRUE);
  nodelay(stdscr, TRUE);
  curs_set(0);
  noecho();
}

ScreenNCurse::~ScreenNCurse()
{
  endwin();
}

void ScreenNCurse::refresh()
{
  this->_getKey();
}

void  ScreenNCurse::_getKey()
{
  int key = getch();
  switch (key)
  {
    case 27:
      Monitor::getInstance()->stop();
      break;
  }
}

void ScreenNCurse::dump()
{
  erase();
  std::list<IMonitorModule*>& modules = Monitor::getInstance()->getModules();
  int posY = this->_scrollY;
  std::list<IMonitorModule*>::iterator module;
  for (module = modules.begin(); module != modules.end(); module++) {
    int height = 20;
    (*module)->dump(*this, 1, posY);
    posY += height + 1;
  }
  refresh();
}
