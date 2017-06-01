
#include"Process_test.h"

Process_test::Process_test()
{}


Process_test::~Process_test()
{}


void Process_test::run_ls()
{
  process.create("/bin/ls",NULL,NULL);  
  process.run();
}


