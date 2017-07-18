
#include"callback_notifier_utest.h"

Callback_notifier_utest::Callback_notifier_utest()
{}


Callback_notifier_utest::~Callback_notifier_utest()
{}



void Callback_notifier_utest::SetUp()
{
  osal_test_base::SetUp();
}


void Callback_notifier_utest::TearDown()
{
  osal_test_base::TearDown();
}


void callback_requester::test_notification()
{
  printf("callback_requester:test_notification callback\n");
}


TEST_F(Callback_notifier_utest, notifier)
{
  callback_requester cr;
  osal_Callback_notifier.set(cr,&callback_requester::test_notification);
  osal_Callback_notifier();
}

