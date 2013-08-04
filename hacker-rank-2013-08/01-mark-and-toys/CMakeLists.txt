CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(MarkAndToys)

include_directories("/usr/local/include")
link_directories("/usr/local/lib")
set(CMAKE_INCLUDE_CURRENT_DIR ON)

SET(SOURCE_FILES
	01-mark-and-toys.cpp
)

SET(HEADER_FILES
)

# http://stackoverflow.com/questions/1167154/listing-header-files-in-visual-studio-c-project-generated-by-cmake
source_group("Headers Files" FILES ${HEADER_FILES})

add_executable(mark_and_toys ${SOURCE_FILES} ${HEADER_FILES})

#target_link_libraries(mark_and_toys gtest)

