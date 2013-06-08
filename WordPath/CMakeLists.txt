CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(WordPath)

include_directories("/usr/local/include")
link_directories("/usr/local/lib")
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# http://stackoverflow.com/questions/1167154/listing-header-files-in-visual-studio-c-project-generated-by-cmake
source_group("Headers" Dictionary.h)

SET(SOURCE_FILES
	main.cpp
	Dictionary.cpp
)

SET(HEADER_FILES
	Dictionary.h
)

add_executable(word_path ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(word_path gtest)

