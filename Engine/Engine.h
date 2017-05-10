#include <uv.h>

class Engine
{

private:
  uv_loop_t* loop;

public:
  Engine();
  ~Engine();

  void start();
  void run();
  bool is_running();
  void stop();
  void off();
};
