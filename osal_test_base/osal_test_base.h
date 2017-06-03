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

#include "gtest/gtest.h"
#include"../Engine/Engine.h"

#ifndef OSAL_TEST_BASE_INCLUDE_H
#define OSAL_TEST_BASE_INCLUDE_H

class osal_test_base : public:: testing::Test
{
 
 private:
 Engine* engine;
 
 public:

  /** osal_test_base construct */ 
  osal_test_base();
  
  /** destory osal_test_base*/
  virtual ~osal_test_base();

 /** add test Setup here */
 virtual void SetUp();
 
 /** run the test case */
 
 void run();
 
 /** add test cleanup here */
 virtual void TearDown();

};

#endif //OSAL_TEST_BASE_INCLUDE_H

