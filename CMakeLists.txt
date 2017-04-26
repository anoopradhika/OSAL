
cmake_minimum_required (VERSION 2.6)
# The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

project (osal_lib)
add_subdirectory(communicator)

add_executable(osal_lib main.cpp)
target_link_libraries(communicator)
#add_executable(osal_lib ${Communicator_Sources} ${Controller_Sources} ${Transporter_Sources} )


