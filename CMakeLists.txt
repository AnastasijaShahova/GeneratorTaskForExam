cmake_minimum_required(VERSION 3.20)
#set(VCPKG_ROOT_DIR "$ENV{VCPKG_ROOT}" CACHE PATH "VCPKG_ROOT_DIR")
#if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
#    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT_DIR}/scripts/buildsystems/vcpkg.cmake"
#            CACHE STRING "")
#endif()

project(untitled5)

set(CMAKE_CXX_STANDARD 17)



find_path( restbed_SOURCE CMakeLists.txt HINTS "/Users/sahovaanastasia/CLionProjects/restbed" )
if ( restbed_SOURCE )
    set( restbed_FOUND TRUE )
    set( restbed_BUILD "${CMAKE_CURRENT_BINARY_DIR}/restbed_build" )
    set( restbed_DISTRIBUTION "${restbed_SOURCE}/distribution" )
    include( ExternalProject )
    ExternalProject_Add( restbed SOURCE_DIR ${restbed_SOURCE}
            PREFIX restbed_build
            INSTALL_DIR ${restbed_DISTRIBUTION}
            CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${restbed_DISTRIBUTION} -DBUILD_SSL=${BUILD_SSL} -DBUILD_SHARED=NO
            INSTALL_COMMAND make install)

    set( restbed_INCLUDE "${restbed_DISTRIBUTION}/include" )
    set( restbed_LIBRARY "${restbed_DISTRIBUTION}/library/${CMAKE_STATIC_LIBRARY_PREFIX}restbed${CMAKE_STATIC_LIBRARY_SUFFIX}" )

    message( STATUS "${Green}Found Restbed include at: ${restbed_SOURCE}${Reset}" )
else ( )
    message( FATAL_ERROR "${Red}Failed to locate Restbed dependency.${Reset}" )
endif ( )







add_executable(untitled5 main.cpp Database/MySqlDatabase.cpp Database/MySqlDatabase.h Tasks/Task11.cpp Tasks/Task11.h Utils/RandomGenerator.h Database/DataTask.cpp Database/DataTask.h Tasks/Task7.cpp Tasks/Task7.h Tasks/ITask.cpp Tasks/ITask.h Utils/AlgorithmDijkstra.cpp Utils/AlgorithmDijkstra.h Utils/GenerateMatrix.h Tasks/Task1.cpp Tasks/Task1.h Tasks/Task13.cpp Tasks/Task13.h Tasks/Task6.cpp Tasks/Task6.h Rest/IResourceFactory.h Rest/LoginResourceFactory.cpp Rest/LoginResourceFactory.h Rest/IService.h Rest/TaskService.cpp Rest/TaskService.h Rest/IServiceSetting.h Rest/ServiceSettingFactory.cpp Rest/ServiceSettingFactory.h Database/LogIn.cpp Database/LogIn.h Rest/TaskLabelResourceFactory.cpp Rest/TaskLabelResourceFactory.h Database/TaskLabel.cpp Database/TaskLabel.h Rest/TaskResourceFactory.cpp Rest/TaskResourceFactory.h Tasks/TaskFactory.cpp Tasks/TaskFactory.h Tasks/Task8.cpp Tasks/Task8.h Tasks/Task14.cpp Tasks/Task14.h Tasks/Task17.cpp Tasks/Task17.h Utils/StrFormat.h Tasks/Task16.cpp Tasks/Task16.h Tasks/Task22.cpp Tasks/Task22.h)

include_directories(/usr/local/mysql/include "${restbed_DISTRIBUTION}/include")
include_directories(/usr/local/mysql/include )

include_directories(/usr//local/Cellar/boost/1.78.0_1/include)

target_link_libraries(untitled5 /usr/local/mysql/lib/libmysqlclient.21.dylib )


target_link_libraries(untitled5 /Users/sahovaanastasia/CLionProjects/restbed/distribution/library/librestbed.dylib)

target_link_libraries(untitled5 /usr//local/Cellar/boost/1.78.0_1/lib)

