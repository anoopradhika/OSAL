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

#include"Engine.h"

Engine::Engine()
{

}

Engine::~Engine()
{

}


static Engine& Engine::get_engine()
{
  static Engine engine;
  return engine;
}


void Engine::start()
{
   engine_controller.handle = uv_default_loop();
}

void Engine::run()
{
  uv_run(engine_controller.handle,engine_controller.run_option);
}


void Engine::stop()
{
  uv_stop(engine_controller.handle);
}


bool Engine::is_running()
{

}


void Engine::off()
{
  uv_loop_close(engine_controller.handle);
}
