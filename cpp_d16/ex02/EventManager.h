#ifndef EVENTMANAGER_H_
#define EVENTMANAGER_H_

#include <iostream>
#include <list>
#include "Event.h"

class EventManager {
public:
  EventManager();
  ~EventManager();
  EventManager(EventManager const& copy);
  EventManager& operator=(EventManager const& copy);
  void addEvent(const Event& event);
  void removeEventsAt(unsigned int time);
  void dumpEvents(void) const;
  void dumpEventAt(unsigned int time) const;
  void addTime(unsigned int time);
  void addEventList(std::list<Event>& list);
  static bool _listSort(Event const& e1, Event const& e2);
private:
  std::list<Event> _list;
  unsigned int _time;
};

#endif
