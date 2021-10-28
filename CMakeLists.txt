cmake_minimum_required(VERSION 3.20)
project(untitled5)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled5 main.cpp Database/MySqlDatabase.cpp Database/MySqlDatabase.h Tasks/Task11.cpp Tasks/Task11.h Utils/RandomGenerator.h Database/DataTask.cpp Database/DataTask.h Tasks/Task7.cpp Tasks/Task7.h Tasks/ITask.cpp Tasks/ITask.h Utils/AlgorithmDijkstra.cpp Utils/AlgorithmDijkstra.h Utils/GenerateMatrix.h)

include_directories(/usr/local/mysql/include)
target_link_libraries(untitled5 /usr/local/mysql/lib/libmysqlclient.21.dylib)


