# Set the minimum required version of cmake for this project
# this probably could be lower, but I dont have cmake 2.anything to test with
project(raytracer)
cmake_minimum_required (VERSION 2.8)

# Create a project called 'raytracer'
project(raytracer)

# Define in the C++ code what the variable "SRC_DIR" should be equal to the current_path/src
add_definitions( -DSRC_DIR="${CMAKE_CURRENT_SOURCE_DIR}/src" )


file(GLOB SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c
)



# Actually define what we are trying to produce here (an executable), as
# well as what items are needed to create it (the header and source files)
add_executable(${PROJECT_NAME} ${SRC})
target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)
# Tell cmake which directories to look in when you #include a file
# Equivalent to the "-I" option for g++
include_directories(${INCLUDE_DIRS})

# Tell cmake which libraries to link to
# Equivalent to the "-l" option for g++
target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBS})

