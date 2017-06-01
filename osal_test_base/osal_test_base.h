
#include "gtest/gtest.h"
#include"../Engine/Engine.h"

#ifndef OSAL_TEST_BASE_INCLUDE_H
#define OSAL_TEST_BASE_INCLUDE_H

class osal_test_base : testing::Test
{
 
 private:
 Engine* engine;
 
 public:

  /** osal_test_base construct */ 
  osal_test_base();
  
  /** destory osal_test_base*/
  virtual ~osal_test_base();

 void setup_test_base();
 
 /** add test Setup here */
 virtual void SetUp();
 
 /** add test cleanup here */
 virtual void TearDown();

};

#endif //OSAL_TEST_BASE_INCLUDE_H

