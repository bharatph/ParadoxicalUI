#ifndef _CALL_TEST_H
#define _CALL_TEST_H

#include <OnEventListener.hpp>
#include <UI/UI.hpp>
#include <EventType.hpp>
#include <UI/View.hpp>
template <class T>
class CallbackTests
{
  private:
    UI<T> *ui;

  public:
    CallbackTests()
    {
        callBasedOnArgs();
    }

    void callBasedOnArgs()
    {
        ui = new UI<T>();
        class _ : public OnEventListener<T>
        {
          public:
            _() {}
            void onEvent(View<T> *sender) override
            {
                std::cout << "Hello" << std::endl;
                //ui->uiRelatedCall();
            }
        };
        View<T> *button = new View<T>();
        button->setOnEventListener(EventType::Click, new _());
        ui->addChildren(button);
        ui->fun1();
        //ui->someCall();
    }
};
#endif