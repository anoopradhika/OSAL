
cmake_minimum_required (VERSION 2.8)
# The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)
#set (FARM_LIB "/home/neo/build/farm/ubantu/lib")
message("CMAKE_CXX_FLAGSE is ${CMAKE_CXX_FLAGS}")
project (osal_lib)
add_subdirectory(communicator)
add_subdirectory(Engine)
add_subdirectory(Process)
add_subdirectory(osal_test_base)
add_subdirectory(lib/gtest)
include_directories(${gtest_SOURCE_DIR}/inculde ${gtest_SOURCE_DIR})

LINK_DIRECTORIES(${FARM_LIB})
add_executable(osal_lib main.cpp)
target_link_libraries(osal_lib communicator engine process)
#add_executable(osal_lib ${Communicator_Sources} ${Controller_Sources} ${Transporter_Sources} )


