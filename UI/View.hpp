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
    if (eventListeners[eventType])
      for (auto listener : *eventListeners[eventType])
        listener->onEvent(nullptr);
  }

protected:
  std::map<EventType, std::vector<OnEventListener<T> *> *> eventListeners;
  std::vector<View<T> *> children;

public:
  View()
  {
  }
  void setOnEventListener(enum EventType eventType, OnEventListener<T> *eventListener)
  {
    if (!eventListener)
      return;
    if (!eventListeners[eventType])
      eventListeners[eventType] = new std::vector<OnEventListener<T> *>();
    eventListeners[eventType]->push_back(eventListener);
  }
  void addChildren(View<T> *view)
  {
    if (view)
      children.push_back(view);
  }
  std::vector<View<T> *> getChildren()
  {
    return children;
  }

  void click()
  {
    callEvents(EventType::Click);
  }
  void longClick()
  {
    callEvents(EventType::LongClick);
  }
};
#endif