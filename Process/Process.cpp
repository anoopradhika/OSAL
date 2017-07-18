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
  const uint32_t std_in = 0;
  const uint32_t std_out = 1;
  const uint32_t std_err = 2;
  //TODO othere option not set yet. if need add it latter
  options = new uv_process_options_t;
  memset(options,0,sizeof(uv_process_options_t));
  stdio[std_in].flags = UV_INHERIT_FD;
  stdio[std_in].data.fd = std_in;
  stdio[std_out].flags = UV_INHERIT_FD;
  stdio[std_out].data.fd = std_out;
  stdio[std_err].flags = UV_INHERIT_FD;
  stdio[std_err].data.fd = std_err;
  options->stdio = stdio;
  options->stdio_count = 3;
  options->exit_cb = &Process::termination_notification;
  options->file = process_file_path;
  options->args = args;
  options->flags = UV_PROCESS_DETACHED;
  notification = NULL;
  engine = Engine::get_engine();
}


void Process::set_termination_notification(Termination_notification_t _notification)
{
  notification = _notification;
}



void Process::termination_notification(uv_process_t* _handle, long int exit_status, int term_signal)
{

  std::unordered_map<uint32_t, Process* >::iterator process_iterator = process_map.find(_handle->pid);
  if(process_iterator != process_map.end())
  {
    Process* local_process = process_iterator->second;
    local_process->requester(exit_status,term_signal);
  }
  
}



void Process::run()
{
  Process* local_process = this;
  Engine_controller& engine_controller = engine->get_engine_controller();

 fprintf(stderr,"engine_controller.handle %d uv_default_loop is %d\n",engine_controller.handle,uv_default_loop());
  int32_t error = uv_spawn(engine_controller.handle,&handle,options);
  if(error)
  {
    fprintf(stderr, "Error = %s!\n",uv_err_name(error));
  }
  else
  {
    process_map.insert(std::pair<uint32_t, Process* >(handle.pid, this));
  }
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

