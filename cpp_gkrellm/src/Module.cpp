
#include <iostream>
#include <cstring>
#include <fstream>

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/syscall.h>

#include <ncurses/curses.h>
#include <ncurses.h>

#include "Module.hpp"

static int nb = 0;

Module::Module(const pid_t& pid)
{
  this->_pid = pid;
  nb++;
}

Module::~Module()
{
}

void	Module::print_process(WINDOW *win)
{
  int fd;
  char filename[24];
  char arg_list[1024];
  size_t length;
  char* next_arg;

  snprintf (filename, sizeof (filename), "/proc/%d/status", (int) this->_pid);
  fd = open (filename, O_RDONLY);
  length = read (fd, arg_list, sizeof (arg_list));
  close (fd);
  arg_list[length] = '\0';
  next_arg = arg_list;
  while (next_arg < arg_list + length) {
    mvwprintw(win, 1, 1, next_arg);
    next_arg += strlen (next_arg) + 1;
  }
}

void    begin()
{
  newterm(NULL, stderr, stdin);
  noecho();
  keypad(stdscr, TRUE);
  curs_set(FALSE);
  nodelay(stdscr, TRUE);
  keypad(stdscr, TRUE);
}

void    Module::create()
{
  WINDOW        *win;
  int   i;
  int   x;
  int   y;

  i = 0;
  x = 2;
  y = 4;

  while (i < nb)
    {
      if (y == 104)
	{
	  x = x + 32;
	  y = 4;
	}
      win = subwin(stdscr, 30, 23, x, y);
      box(win, ACS_VLINE, ACS_HLINE);

      this->print_process(win);

      scrollok(win, TRUE);
      wrefresh(win);
      refresh();

      i++;
      y = y + 25;
    }
}

/*int     main()
{

  WINDOW        *win;
  Module	mod1(1);
  Module	mod2(10);
  Module	mod3(11);
  Module	mod4(124);
  Module	mod5(2);
  Module	mod6(20);
  begin();
  while (getch() != 27)
    {
      win = subwin(stdscr, 0, 0, 1, 1);
      box(win, ACS_VLINE, ACS_HLINE);
      scrollok(win, TRUE);
      wmove(win, 0, 0);
      doupdate();
      mod1.create();
      mod2.create();
      mod3.create();
      mod4.create();
      mod5.create();
      mod6.create();
      wrefresh(win);
      refresh();
    }
  endwin();
  return (0);
}*/
