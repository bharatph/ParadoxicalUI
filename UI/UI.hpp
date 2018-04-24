#ifndef _UI_H
#define _UI_H "UI"
#include <IUI.hpp>
#include <UI/View.hpp>

template <class T>
class UI : public IUI, public View<T>
{
private:
  IUI *ui;

public:
  UI()
  {
    ui = new T();
  }
  void fun1()
  {
    ui->fun1();
    View<T>::children.at(0)->click();
  }
  void fun2()
  {
    ui->fun2();
  }
};

#endif