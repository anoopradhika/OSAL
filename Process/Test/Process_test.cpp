
#include"Process_test.h"

Process_test::Process_test()
{}


Process_test::~Process_test()
{}


void Process_test::run_ls()
{
  printf("run_ls test");
  char* args[] = {"/bin/sleep", "5", NULL};
//  process.create("/bin/sleep",args,NULL);  
  process.run();
}


void Process_test::SetUp()
{
  osal_test_base::SetUp();
}


void Process_test::TearDown()
{
  osal_test_base::TearDown();
}


TEST_F(Process_test, run_ls_test)
{
  printf("start test");
  run_ls();
  run();
}
