//
// data_flags.cpp for zappy in /home/lurivar/rendu/PSU_2016_zappy/ai_src/
//
// Made by Luc Normandon
// Login   <luc.normandon@epitech.eu@epitech.eu>
//
// Started on  Mon Jun 19 17:28:58 2017 Luc Normandon
// Last update Sat Jul  1 16:48:10 2017 Luc Normandon
//

#include "../include/client.hpp"

data_flags::data_flags(int p, char *n)
{
	this->port = p;
	this->fd = 0;
	this->name = n;
	this->machine = "0";
	this->to_server = NULL;
	this->to_client = NULL;

	this->food = 10;
	this->foodprio = 1;

	this->linemate = 0;
	this->linemateprio = 3;

	this->deraumere = 0;
	this->deraumereprio = 0;

	this->sibur = 0;
	this->siburprio = 0;

	this->mendiane = 0;
	this->mendianeprio = 0;

	this->phiras = 0;
	this->phirasprio = 0;

	this->thystame = 0;
	this->thystameprio = 0;

	this->obj_to_take = "NULL";
	this->tile_to_go = -1;
}

data_flags::data_flags(int p, char *n, std::string m)
{
	this->port = p;
	this->fd = 0;
	this->name = n;
	this->machine = m;
	this->to_server = NULL;
	this->to_client = NULL;

	this->food = 10;
	this->foodprio = 1;

	this->linemate = 0;
	this->linemateprio = 3;

	this->deraumere = 0;
	this->deraumereprio = 0;

	this->sibur = 0;
	this->siburprio = 0;

	this->mendiane = 0;
	this->mendianeprio = 0;

	this->phiras = 0;
	this->phirasprio = 0;

	this->thystame = 0;
	this->thystameprio = 0;

	this->obj_to_take = "NULL";
	this->tile_to_go = -1;
}

data_flags::~data_flags()
{
}

int		data_flags::getPort()
{
	return (this->port);
}

int		data_flags::getfd()
{
	return (this->fd);
}

std::string		data_flags::getName()
{
	return (this->name);
}

std::string		data_flags::getMachine()
{
	return (this->machine);
}
