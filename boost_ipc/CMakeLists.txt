cmake_minimum_required(VERSION 2.8)
project(BoostIPC)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
include_directories("/usr/local/include")
include_directories("/Users/vietlq/Downloads/boost_1_51_0")
link_directories("/usr/local/lib")

SET(MOD_SRC_FILES
	modifier.cpp
)

SET(INSPECT_SRC_FILES
	inspector.cpp
)

add_executable(boost_ipc_modifier ${MOD_SRC_FILES})
add_executable(boost_ipc_inspector ${INSPECT_SRC_FILES})
