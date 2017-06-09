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

#ifndef CALLBACK_NOTIFIER_UTEST_INCULDE_H
#define CALLBACK_NOTIFIER_UTEST_INCULDE_H

#include"../callback_notifier.h"

#include"../../osal_test_base/osal_test_base.h"


/**
 Test class to test callback notification
*/
class Callback_notifier_utest: public:: osal_test_base
{

private:




public:

  Callback_notifier_utest();


  virtual ~Callback_notifier_utest();


  void test_notification();

  /** Setup needed for the Class process is adeded here */
  virtual void SetUp();

  /** Do the clean operation called after the test */
  virtual void TearDown();

  Osal_Callback_notifier osal_Callback_notifier;
};



class callback_requester
{
public:
  callback_requester()
  {}
  
  ~callback_requester()
  {}
  
  void test_notification();

};

#endif //PROCESS_TEST_INCULDE_H
