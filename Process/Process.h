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


class Process
{

public:
  typedef void (Process::*Termination_notification_t)( int64_t exit_status, int term_signal);
  Process();
  ~Process();


  /**
    Set the arguments for process
    @param process_file_path: give the process file path
    @param args: arguments for the process
    @param env: enviorment for the process
  */
  void set_arguments(const char* process_file_path, char** args, char** env );

  /** Method called on the exit of process terminate */  
  static void termination_notification(uv_process_t*, long int exit_status, int term_signal);

  static std::unordered_map<uint32_t, Process* > process_map;

  void tereminated(long int exit_status, int term_signal);

  /** Set user given callback 	*/
  void set_termination_notification(Termination_notification_t _notification);
  void start();
  void run();
  int get_pid();
  void kill(int pid, int signal);
  bool is_running();
  void stop();
  void off();

private:
  uv_process_t handle;
  uv_process_options_t options;
  Engine* engine;
  Termination_notification_t notification;
  //Callback_manager callback_manager;
};
