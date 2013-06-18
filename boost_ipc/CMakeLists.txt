cmake_minimum_required(VERSION 2.8)
project(BoostIPC)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
include_directories("/usr/local/include")
include_directories("/Users/vietlq/Downloads/boost_1_51_0")
link_directories("/usr/local/lib")

SET(SOURCE_FILES
	main.cpp
)

add_executable(boost_ipc ${SOURCE_FILES})

