cmake_minimum_required(VERSION 3.20)
project(untitled5)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled5 main.cpp MySqlDatabase.cpp MySqlDatabase.h Task11.cpp Task11.h RandomGenerator.cpp RandomGenerator.h)

include_directories(/usr/local/mysql/include)
target_link_libraries(untitled5 /usr/local/mysql/lib/libmysqlclient.21.dylib)




