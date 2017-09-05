
#ifndef MODULE_HPP_
#define MODULE_HPP_

#include <iostream>
#include <string>

class Module
{
public:
  Module(const pid_t& _pid);
  virtual ~Module();
  void print_process(WINDOW *win);
  void	create();
private:
  pid_t		_pid;
};

#endif
