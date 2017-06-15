##
 #  Copyright (C) 2017  Anoop Chandran
 #
 #  This library is free software; you can redistribute it and/or
 #
 #  modify it under the terms of the GNU Lesser General Public
 #  License as published by the Free Software Foundation; either
 #  version 2.1 of the License, or (at your option) any later version.
 #
 #  This library is distributed in the hope that it will be useful,
 #  but WITHOUT ANY WARRANTY; without even the implied warranty of
 #  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 #  Lesser General Public License for more details.
 #
 #  You should have received a copy of the GNU Lesser General Public
 #  License along with this library; if not, write to the Free Software
 #  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 #  or see <http://www.gnu.org/licenses/>
##

cmake_minimum_required (VERSION 2.6)
# The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

   


add_executable(process_test  Process_test.cpp)
target_link_libraries(process_test process osal_test_base)

