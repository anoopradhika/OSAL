
#include "gtest/gtest.h"
#include"../Engine/Engine.h"


class osal_test_base : testing::Test
{
 
 private:
 Engine* engine;
 
 public:

  /** osal_test_base construct */ 
  osal_test_base();
  
  /** destory osal_test_base*/
  ~osal_test_base();

 void setup_test_base();
 
 /** add test Setup here */
 virtual void SetUp();
 
 /** add test cleanup here */
 virtual void TearDown();

};
