#include "ModRam.hpp"

ModRam::ModRam() : _refreshRate(200), _title("ram")
{}

ModRam::~ModRam()
{}

int ModRam::getRefreshRate() const
{
  return this->_refreshRate;
}

int ModRam::getLastRefresh() const
{
  return this->_lastRefresh;
}

void ModRam::setLastRefresh(int value)
{
  this->_lastRefresh = value;
}
