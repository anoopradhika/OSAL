#ifndef CALLBACK_NOTIFIER_INCULDE_H
#define CALLBACK_NOTIFIER_INCULDE_H

#include<memory>

//https://stackoverflow.com/questions/6849287/c-callback-how-to-decouple-the-call-back-type
//http://partow.net/programming/templatecallback/index.html
class callback_notifier_Base
{
  public:
    callback_notifier_Base() {}
    virtual ~callback_notifier_Base() {}
    virtual void operator()(...) const = 0;
};

template<class requester_t, class callback_t>
class callback_notifier : public callback_notifier_Base
{
  public:
    callback_notifier(requester_t& _requester, callback_t _callback) : requester(_requester), callback(_callback) {}
/*line 18*/    void operator()(...) const { (&requester->*callback)(); } // how to pass "..." into method(...)
  virtual ~callback_notifier() {}
  private:
    requester_t& requester;
    callback_t callback;
};

// PUBLIC API

class Osal_Callback_notifier
{
  public:
    Osal_Callback_notifier() {}

    void operator()() { (*notifier)(); }

    template<class requester_t, class callback_t>
      void set(requester_t& requester, callback_t callback) { notifier.reset(new callback_notifier<requester_t, callback_t>(requester, callback)); }

  private:
    std::auto_ptr<callback_notifier_Base> notifier;
};

#endif //CALLBACK_NOTIFIER_INCULDE_H

