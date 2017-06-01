

#ifndef PROCESS_TEST_INCULDE_H
#define PROCESS_TEST_INCULDE_H

#include"../Process.h"

#include"../../osal_test_base/osal_test_base.h"

/**
 Test class to test Class Process
*/
class Process_test: osal_test_base
{

private:

  Process process;


public:

  Process_test();


  virtual ~Process_test();


  void run_ls();

/** Setup needed for the Class process is adeded here */
//virtual SetUp();

/** Do the clean operation called after the test */
//virtual TearDown();


};

#endif //PROCESS_TEST_INCULDE_H
