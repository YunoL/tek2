#include "EventManager.h"

EventManager::EventManager() : _list(), _time(0)
{}

EventManager::~EventManager()
{}

EventManager::EventManager(EventManager const& copy) : _list(copy._list), _time(copy._time)
{}

EventManager& EventManager::operator=(EventManager const& copy)
{
  this->_list = copy._list;
  this->_time = copy._time;
  return *this;
}

void EventManager::addEvent(const Event& event)
{
  if (event.getTime() < this->_time)
    return;
  this->_list.push_back(event);
  this->_list.sort(EventManager::_listSort);
}

void EventManager::removeEventsAt(unsigned int time)
{
  std::list<Event>::iterator itr = this->_list.begin();
  while (itr != this->_list.end())
  {
    if ((*itr).getTime() == time)
      this->_list.erase(++itr);
    else
      ++itr;
  }
}

void EventManager::dumpEvents(void) const
{
  std::list<Event>::const_iterator  itr = this->_list.begin();
  while (itr != this->_list.end())
  {
    std::cout << (*itr).getTime() << ": " << (*itr).getEvent() << '\n';
    ++itr;
  }
}

void EventManager::dumpEventAt(unsigned int time) const
{
  std::list<Event>::const_iterator  itr = this->_list.begin();
  while (itr != this->_list.end())
  {
    if ((*itr).getTime() == time)
      std::cout << (*itr).getTime() << ": " << (*itr).getEvent() << '\n';
    ++itr;
  }
}

void EventManager::addTime(unsigned int time)
{
  this->_time += time;
  std::list<Event>::const_iterator  itr = this->_list.begin();
  while (itr != this->_list.end())
  {
    if ((*itr).getTime() <= this->_time)
    {
      std::cout << (*itr).getEvent() << '\n';
      this->_list.erase(++itr);
    }
    else
      ++itr;
  }
}

void EventManager::addEventList(std::list<Event>& list)
{
  std::list<Event>::const_iterator  itr = list.begin();
  while (itr != list.end())
  {
    if ((*itr).getTime() > this->_time)
      this->_list.push_back(*itr);
    this->_list.sort(EventManager::_listSort);
    ++itr;
  }
}

bool EventManager::_listSort(Event const& e1, Event const& e2)
{
  if (e1.getTime() > e2.getTime())
    return false;
  return true;
}
