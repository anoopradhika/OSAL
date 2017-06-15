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

#ifndef PROCESS_TEST_INCULDE_H
#define PROCESS_TEST_INCULDE_H

#include"../Process.h"

#include"../../osal_test_base/osal_test_base.h"

/**
 Test class to test Class Process
*/
class Process_test: public:: osal_test_base
{

private:

  Process process;


public:

  Process_test();


  virtual ~Process_test();


  void run_ls();

  /** Setup needed for the Class process is adeded here */
  virtual void SetUp();

  /** Do the clean operation called after the test */
  virtual void TearDown();
  
  void process_exit(uint64_t exit_code, uint32_t exit_signal);


};

#endif //PROCESS_TEST_INCULDE_H
