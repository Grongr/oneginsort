cmake_minimum_required(VERSION 3.16)
project(onegin_sort)

set(LANGUAGE CXX)
set(MYCOMPILE_FLAGS "-Wall -Wfloat-equal -Wsign-conversion")
set(MYCOMPILE_FLAGS "${MYCOMPILE_FLAGS} -Warray-bounds -Wdiv-by-zero -Wdouble-promotion")

#set(MYCOMPILE_FLAGS "${MYCOMPILE_FLAGS} -DNDEBUG")

add_executable(main main.c
                    textio.c)

add_definitions(${MYCOMPILE_FLAGS})
target_link_libraries(main m)
