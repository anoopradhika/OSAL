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

#include"Process.h"
#include <iostream>


std::unordered_map<uint32_t, Process* > Process::process_map;

Process::Process()
{

}


Process::~Process()
{


}


void Process::create(const char* process_file_path,char** args, char** env )
{
  options.file = process_file_path;
  options.args = args;
  options.env = env;
  options.exit_cb = &Process::termination_notification;
  options.flags = UV_PROCESS_SETUID|UV_PROCESS_SETGID;
  //TODO othere option not set yet. if need add it latter
  notification = NULL;
  engine = Engine::get_engine();
}


void Process::set_termination_notification(Termination_notification_t _notification)
{
  notification = _notification;
}


void Process::tereminated(long int exit_status, int term_signal)
{
  (this->*notification)(exit_status,term_signal);
}


void Process::termination_notification(uv_process_t* _handle, long int exit_status, int term_signal)
{
  std::unordered_map<uint32_t, Process* >::iterator process_iterator = process_map.find(_handle->pid);
  if(process_iterator != process_map.end())
  {
    Process* local_process = process_iterator->second;
    local_process->tereminated(exit_status,term_signal);
  }
  
}



void Process::run()
{
  Process* local_process = this;
  Engine_controller& engine_controller = engine->get_engine_controller();


  char *args[] = { "/bin/sleep", "1000", NULL };

  options.exit_cb = NULL;
  options.file = "sleep";
  options.args = args;
options.flags = UV_PROCESS_DETACHED;

  //uv_spawn(engine_controller.handle,&handle,&options);
if(uv_spawn(uv_default_loop(), &handle, &options))
{
    fprintf(stderr, "Error!\n");

}
  process_map.insert(std::pair<uint32_t, Process* >(handle.pid, this));
}


int Process::get_pid()
{
  return handle.pid;
}


void Process::kill(int pid, int signal)
{
  uv_kill(pid,signal);
}

bool Process::is_running()
{

}

void Process::resume()
{
  uv_kill(handle.pid,SIGCONT);
}


void Process::stop()
{
  uv_kill(handle.pid,SIGSTOP);
}


void Process::destroy()
{
  uv_kill(handle.pid,SIGKILL);
}

