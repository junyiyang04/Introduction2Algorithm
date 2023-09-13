cmake_minimum_required(VERSION 3.5.1)


configure_file(config.h.in ${CMAKE_CURRENT_SOURCE_DIR}/include/config.h)


file(GLOB_RECURSE source ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
add_library(Introdunction SHARED ${source})

target_include_directories(Introdunction 
                            PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
                            )

install(TARGETS Introdunction RUNTIME DESTINATION ${CMAKE_BINARY_DIR})                           