#include"uv.h"

class Process
{

private:
  uv_process_t handle;
  uv_process_options_t options;
public:
  Process();
  ~Process();
  void start();
  void run();
  bool is_running();
  void stop();
  void off();
};
