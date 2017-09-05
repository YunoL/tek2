//
// err_client.cpp for zappy in /home/lurivar/rendu/PSU_2016_zappy/ai_src/
//
// Made by Luc Normandon
// Login   <luc.normandon@epitech.eu@epitech.eu>
//
// Started on  Mon Jun 19 17:28:08 2017 Luc Normandon
// Last update Wed Jun 21 13:54:03 2017 Luc Normandon
//

#include "../include/client.hpp"
#include "../include/err_client.hpp"

int error(std::string	msg)
{
	std::cout << msg;
	return 1;
}
