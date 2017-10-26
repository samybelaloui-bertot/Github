
cmake_minimum_required(VERSION 2.6)

project(projet_3eti)


file(
GLOB
source_files
*.c
*.h
)

SET(CMAKE_BUILD_TYPE Debug)
SET(CMAKE_C_FLAGS "-Wall -Wextra -Wno-unused-parameter -D_REENTRANT -fPIC" )


add_executable(	
   projet_3eti	
   ${source_files}
   )	

target_link_libraries(projet_3eti "-lm")


