CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(TDD_Dictionary)

include_directories("/usr/local/include")
link_directories("/usr/local/lib")
set(CMAKE_INCLUDE_CURRENT_DIR ON)

SET(SOURCE_FILES
	main.cpp
	Dictionary.cpp
	TestDictionary.cpp
)

SET(HEADER_FILES
	Dictionary.h
	TestDictionary.h
)

# http://stackoverflow.com/questions/1167154/listing-header-files-in-visual-studio-c-project-generated-by-cmake
source_group("Headers Files" FILES ${HEADER_FILES})

add_executable(tdd_dictionary ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(tdd_dictionary gtest)

