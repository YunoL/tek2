#include "Event.h"

Event::Event(void) : _time(0), _event("")
{}

Event::Event(unsigned int time, const std::string& event) : _time(time), _event(event)
{}

Event::Event(Event const& copy) : _time(copy._time), _event(copy._event)
{}

Event::~Event()
{}

Event& Event::operator=(Event const& copy)
{
  this->_time = copy._time;
  this->_event = copy._event;
  return *this;
}

unsigned int Event::getTime(void) const
{
  return this->_time;
}

const std::string& Event::getEvent(void) const
{
  return this->_event;
}

void Event::setTime(unsigned int time)
{
  this->_time = time;
}

void Event::setEvent(std::string const& event)
{
  this->_event = event;
}
