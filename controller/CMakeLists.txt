cmake_minimum_required (VERSION 2.6)
# The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

#file(GLOB Signal_Sources RELATIVE "Signal" "*.cpp") TODO find out how to use it.
#add_subdirectory(Event)
#add_subdirectory(Signal)

add_library(controller  Mutex/Mutex.cpp Semaphore/Semaphore.cpp  )


