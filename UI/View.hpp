#ifndef _VIEW_H
#define _VIEW_H "View"

#include <algorithm>
#include <vector>
#include <map>
#include <EventType.hpp>
#include <OnEventListener.hpp>

template <class T>
class View
{
private:
  void callEvents(EventType eventType)
  {
    std::vector<OnEventListener<T> *> *listeners = eventListeners[EventType::Click];
    if (listeners)
      for (auto listener : *listeners)
        listener->onEvent(nullptr);
  }

protected:
  std::map<EventType, std::vector<OnEventListener<T> *> *> eventListeners;
  std::vector<View<T> *> children;

  void click()
  {
    callEvents(EventType::Click);
  }
  void longClick()
  {
    callEvents(EventType::LongClick);
  }

public:
  View()
  {
  }
  void setOnEventListener(enum EventType eventType, OnEventListener<T> *eventListener)
  {
    if (!eventListener)
      return;
    std::vector<OnEventListener<T> *> *listeners = eventListeners[eventType];
    if (!listeners)
      listeners = new std::vector<OnEventListener<T> *>();
    listeners->push_back(eventListener);
  }
  void addChildren(View<T> *view)
  {
    if (view)
      children.push_back(view);
  }
};
#endif