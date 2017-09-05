//
// utility.cpp for zappy in /home/lurivar/rendu/PSU_2016_zappy/ai_src/
//
// Made by Luc Normandon
// Login   <luc.normandon@epitech.eu@epitech.eu>
//
// Started on  Thu Jun 22 15:24:18 2017 Luc Normandon
// Last update Thu Jun 22 16:19:36 2017 Luc Normandon
//

#include "../include/client.hpp"

void my_exit(std::string str, int val)
{
  if (str.empty())
    std::cerr << str << std::endl;
  std::exit(val);
}

void closing(std::string str, int fd, int val)
{
  if (close(fd) == -1)
    my_exit(str, val);
  my_exit(str, val);
}

int xatoi(const std::string str)
{
  if (str.empty())
    return 0;
  return std::stoi(str);
}
