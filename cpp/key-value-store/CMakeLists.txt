###############################################################################
# Key Value Store
###############################################################################
cmake_minimum_required(VERSION 3.3.0)
project("Key Value Store")

###############################################################################
# ZMQ LIB
###############################################################################
find_package(ZMQ MODULE 4.0.0)
include_directories(${ZMQ_INCLUDE_DIRS})
set(LIBS ${LIBS} ${ZMQ_LIBRARIES})

###############################################################################
# Targets
###############################################################################
file(GLOB SERVER src/server.cpp)
file(GLOB CLIENT src/client.cpp)
add_executable(server ${SERVER})
add_executable(client ${CLIENT})
target_link_libraries(server ${LIBS})
target_link_libraries(client ${LIBS})
