file(GLOB_RECURSE source ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
add_library(Introdunction SHARED ${source})

target_include_directories(Introdunction 
                            PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
                            )