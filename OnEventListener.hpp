#ifndef _ON_EVE_H
#define _ON_EVE_H "OnEventListener"

template <class T>
class OnEventListener;

#include <UI/View.hpp>

template <class T>
class OnEventListener
{
public:
  OnEventListener()
  {
  }
  virtual void onEvent(View<T> *) = 0;
};

#endif