
cmake_minimum_required (VERSION 2.6)
# The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)
set(CMAKE_CXX_FLAGS "-std=c++0x -Wall")
message("CMAKE_CXX_FLAGS is ${CMAKE_CXX_FLAGS}")
message("CMAKE_CXX_FLAGS_DEBUG is ${CMAKE_CXX_FLAGS_DEBUG}")
message("CMAKE_CXX_FLAGS_RELEASE is ${CMAKE_CXX_FLAGS_RELEASE}")
project (osal_lib)
add_subdirectory(communicator)
add_subdirectory(Engine)
add_subdirectory(Process)

add_executable(osal_lib main.cpp)
target_link_libraries(osal_lib communicator engine process)
#add_executable(osal_lib ${Communicator_Sources} ${Controller_Sources} ${Transporter_Sources} )


