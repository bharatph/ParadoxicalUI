#ifndef _VIEW_H
#define _VIEW_H "View"

#include <algorithm>
#include <vector>
#include <map>
#include <Event.hpp>
#include <OnEventListener.hpp>
#include <crossguid/guid.hpp>

template <class T>
class View
{
private:
  xg::Guid *id = nullptr;
  void callEvents(enum Event event)
  {
    if (eventListeners[event])
      for (auto listener : *eventListeners[event])
        listener->onEvent(this);
  }

protected:
  std::map<Event, std::vector<OnEventListener<T> *> *> eventListeners;
  std::vector<View<T> *> children;

public:
  View()
  {
    id = new xg::Guid(xg::newGuid());
  }
  void setOnEventListener(enum Event event, OnEventListener<T> *eventListener)
  {
    if (!eventListener)
      return;
    if (!eventListeners[event])
      eventListeners[event] = new std::vector<OnEventListener<T> *>();
    eventListeners[event]->push_back(eventListener);
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
    callEvents(Event::Click);
  }
  void longClick()
  {
    callEvents(Event::LongClick);
  }
  std::string getId(){
    return id->str();
  }
};
#endif
