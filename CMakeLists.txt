set(VCPKG_ROOT_DIR "$ENV{VCPKG_ROOT}" CACHE PATH "VCPKG_ROOT_DIR")
if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT_DIR}/scripts/buildsystems/vcpkg.cmake"
            CACHE STRING "")
endif()

cmake_minimum_required(VERSION 3.20)
project(untitled5)

set(CMAKE_CXX_STANDARD 17)

message("Environment variable: VCPKG_ROOT = $ENV{VCPKG_ROOT}")


add_executable(untitled5 main.cpp Database/MySqlDatabase.cpp Database/MySqlDatabase.h Tasks/Task11.cpp Tasks/Task11.h Utils/RandomGenerator.h Database/DataTask.cpp Database/DataTask.h Tasks/Task7.cpp Tasks/Task7.h Tasks/ITask.cpp Tasks/ITask.h Utils/AlgorithmDijkstra.cpp Utils/AlgorithmDijkstra.h Utils/GenerateMatrix.h Tasks/Task1.cpp Tasks/Task1.h Tasks/Task13.cpp Tasks/Task13.h Tasks/Task6.cpp Tasks/Task6.h Rest/IResourceFactory.h Rest/TaskResourceFactory.cpp Rest/TaskResourceFactory.h Rest/IService.h Rest/TaskService.cpp Rest/TaskService.h Rest/IServiceSetting.h Rest/ServiceSettingFactory.cpp Rest/ServiceSettingFactory.h)

include_directories(/usr/local/mysql/include)
target_link_libraries(untitled5 /usr/local/mysql/lib/libmysqlclient.21.dylib restbed)


