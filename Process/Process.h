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

#include"../Engine/Engine.h"
#include <unordered_map>
//#include"Callback_manager.h"

//TODO usage of uv_disable_stdio_inheritance need to be identified

/**
  Class Process is wrapper use OS process functionality
*/
class Process
{

public:
  /**
    Notification invoked on the termination of a process
    @param exit_status: exit status of a terminated process
    @param term_signal: Process is terminated because of this signal
  */
  typedef void (Process::*Termination_notification_t)( int64_t exit_status, int term_signal);

  /** Create a Procecss entity. Does nothing*/
  Process();

  /** Destory a procecss entity. Does nothing*/
  ~Process();

  /**
    Set the arguments for process
    @param process_file_path: give the process file path
    @param args: arguments for the process
    @param env: enviorment for the process
  */
  void create(const char* process_file_path, char** args, char** env );

  /**
    Termination callback used for connecting to UVlib process termination callback
    @param handle: handle hold process ID
    @param exit_status: exit status of a terminated process
    @param term_signal: Process is terminated because of this signal
 */  
  static void termination_notification(uv_process_t* handle, long int exit_status, int term_signal);

  /** 
    map used for connecting process id to Process. It is used for accessing
    Process address from termination_notification.
  */
  static std::unordered_map<uint32_t, Process* > process_map;
  
  
  /**
    called from termination_notification and used for accessing notification
    @param exit_status: exit status of a terminated process
    @param term_signal: Process is terminated because of this signal
  */
  void tereminated(long int exit_status, int term_signal);

  /**
    Set a functon to be called on the termination of process
    @param  _notification: pointer to function
 	*/
  void set_termination_notification(Termination_notification_t _notification);
  
  /** After set_arguments(), run a prosees */
  void run();
  
  /**
     get process id of a process created by class Process
     @return return the process id
  */
  int get_pid();
  
  /**
    send to signal to a process with process id
    @param pid: process id
    @param signal: signal to send
  */
  void kill(int pid, int signal);
  
  /**
    check this process is running
    @return return true, if process is running, esle fasle
  */
  bool is_running();
  
  /**
    run the stoped process
  */
  void resume();
  
  /**
    stop the running process
  */
  void stop();
  
  /** called after stop. Cleanup the process before new start */
  void destroy();

private:
  /** handle provide by unlib after process run */
  uv_process_t handle;
  
  /** option need to start a process, this is specific to uvlib */
  uv_process_options_t options;
  
  /** Engine need for run a process class */
  Engine* engine;

  /** stores the callback to be called on process terminate */  
  Termination_notification_t notification;
  
};
