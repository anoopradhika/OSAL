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

#ifndef ENGINE_INCLUDE_H
#define ENGINE_INCLUDE_H

#include"Engine_controller.h"

class Engine
{

private:
  Engine_controller engine_controller;

protected:
  Engine();
  
  static Engine* engine;

  static bool engine_created;

public:
  ~Engine();

  static Engine* get_engine();

  void start();

  void run();

  bool is_running();

  Engine_controller& get_engine_controller();

  void stop();

  void off();
};

#endif //ENGINE_INCULDE_H

