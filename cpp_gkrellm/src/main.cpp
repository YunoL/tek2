#include "Monitor.hpp"
#include "ModRam.hpp"
#include "ScreenNCurse.hpp"
#include "Module.hpp"
#include <iostream>
#include <cstring>
#include <ncurses/curses.h>

void launch()
{
  ScreenNCurse  disp;
  Monitor& monitor = *(Monitor::getInstance());
  monitor.setDisplay(new ScreenNCurse());
  monitor.run(disp);
}

int main(int ac, char **av)
{
  if (ac != 2)
  {
    std::cerr << "Usage: ./mygkrellm -display_type (-text, -graphic)" << '\n';
    return -1;
  }
  Monitor  screen;
  if (strcmp(av[1], "-text") == 0)
    launch();
  else if (strcmp(av[1], "-graphic") == 0)
    std::cout << "affichage graphic" << '\n';
  return 0;
}
