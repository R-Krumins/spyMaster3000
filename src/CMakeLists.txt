include_directories(${CMAKE_SOURCE_DIR}/src/algos)
include_directories(${CMAKE_SOURCE_DIR}/src/util)

add_library(core
  lib.cpp
  algos/aes.cpp
)

add_executable(spymaster
  main.cpp
)

target_link_libraries(spymaster core)
