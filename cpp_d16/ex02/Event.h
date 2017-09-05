#ifndef EVENT_H_
#define EVENT_H_

#include <iostream>

class Event {
public:
  Event(void);
  Event(unsigned int time, const std::string& event);
  Event(Event const& copy);
  virtual ~Event();
  Event& operator=(Event const& copy);
  unsigned int getTime(void) const;
  const std::string& getEvent(void) const;
  void setTime(unsigned int time);
  void setEvent(std::string const& event);
private:
  unsigned int _time;
  std::string _event;
};

#endif
