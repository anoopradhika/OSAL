
/*
 *  Copyright (C) 2017  Anoop Chandran
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *  or see <http://www.gnu.org/licenses/>
*/

#include"Process_test.h"

Process_test::Process_test()
{}


Process_test::~Process_test()
{}


void Process_test::run_ls()
{
  printf("run_ls test");
  char* args[] = {"/bin/sleep", "2", NULL};
  process.create("/bin/sleep",args,NULL);  
  process.requester.Connect(this,&Process_test::process_exit);
  process.run();
}

void Process_test::process_exit(uint64_t exit_code, uint32_t exit_signal)
{
  printf("Process_test::process_exit exit_code = %d exit_signal = %d", exit_code, exit_signal);
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



#if 0

void on_exit(uv_process_t *req, int exit_status, int term_signal) {
  fprintf(stderr, "Process exited with status %d, signal %d\n", exit_status, term_signal);
  uv_close((uv_handle_t*)req, NULL);
}

uv_process_options_t options;
TEST_F(Process_test, run_ls_test)
{
  uv_loop_t *loop;
  loop = uv_default_loop();
uv_process_t child_req;

  char *args[] = { "/bin/sleep", "2", NULL };

  options.exit_cb = NULL;
  options.file = "/bin/sleep";
  options.args = args;
  options.flags = UV_PROCESS_DETACHED;
  fprintf(stderr,"loop %d\n",loop);
  int error = uv_spawn(loop, &child_req, &options);
  if (error) {
    fprintf(stderr, "Error = %s!\n",uv_err_name(error));
  }
  fprintf(stderr, "Launched sleep with PID %d\n", child_req.pid);
//  uv_unref((uv_handle_t*) &child_req);

  uv_run(loop, UV_RUN_DEFAULT);
}

#endif
