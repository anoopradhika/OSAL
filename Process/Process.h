#include"uv.h"

class Process
{

private:
  uv_process_t handle;
  uv_process_options_t options;
public:
  Process();
  ~Process();
  start();
  run();
  is_running();
  stop();
  off();
};
