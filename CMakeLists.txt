cmake_minimum_required(VERSION 3.5.1)

# add_definitions("-Wall -g")
project(I2A VERSION 1.0)


#specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/code/include)
add_subdirectory(code)
# list(APPEND EXTRA_LIBS lib)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC 
                    Introdunction
                    ) #the last argument is the name of library 

