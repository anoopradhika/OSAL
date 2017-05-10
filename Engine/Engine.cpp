#include"Engine.h"

Engine::Engine()
{

}

Engine::~Engine()
{

}

void Engine::start()
{
  loop = uv_default_loop();
}

void Engine::run()
{
  uv_run(loop,UV_RUN_DEFAULT);
}


void Engine::stop()
{
  uv_stop(loop);
}


bool Engine::is_running()
{

}


void Engine::off()
{
  uv_loop_close(loop);
}
