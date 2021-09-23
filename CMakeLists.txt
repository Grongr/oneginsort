cmake_minimum_required(VERSION 3.16)
project(onegin_sort)

#set(LANGUAGE CXX)
# set(MYCOMPILE_FLAGS "-Wall -Wfloat-equal -Wsign-conversion -O0")
#set(MYCOMPILE_FLAGS "${MYCOMPILE_FLAGS} -Warray-bounds -Wdiv-by-zero -Wdouble-promotion")
#set(MYCOMPILE_FLAGS "${MYCOMPILE_FLAGS} -fsanitize=address -static-libasan -g")

#set(MYCOMPILE_FLAGS "${MYCOMPILE_FLAGS} -DNDEBUG")
set (CMAKE_C_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")

add_executable(main main.c
                    textio.c
                    comparators.c
                    my_qsort.c)

                #add_definitions(${MYCOMPILE_FLAGS})
target_link_libraries(main m)
