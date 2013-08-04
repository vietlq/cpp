CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(JourneyToTheMoon)

include_directories("/usr/local/include")
link_directories("/usr/local/lib")
set(CMAKE_INCLUDE_CURRENT_DIR ON)

SET(SOURCE_FILES
	02-a-journey-to-the-moon.cpp
)

SET(HEADER_FILES
)

# http://stackoverflow.com/questions/1167154/listing-header-files-in-visual-studio-c-project-generated-by-cmake
source_group("Headers Files" FILES ${HEADER_FILES})

add_executable(journey_to_the_moon ${SOURCE_FILES} ${HEADER_FILES})

#target_link_libraries(journey_to_the_moon gtest)

