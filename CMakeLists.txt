cmake_minimum_required(VERSION 3.10)
project(TestProgram)

set(CMAKE_CXX_STANDARD 11)

find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

SET(CMAKE_BUILD_TYPE "Debug")

# 遍历source目录下的所有.cpp文件
file(GLOB SOURCE_FILES "*.cpp")

# 为每个.cpp文件生成一个可执行目标
foreach(SOURCE_FILE ${SOURCE_FILES})
    # 获取.cpp文件名（不包括路径和扩展名）
    get_filename_component(EXEC_NAME ${SOURCE_FILE} NAME_WE)
    # 生成可执行目标
    add_executable(${EXEC_NAME} ${SOURCE_FILE})
    target_link_libraries(${EXEC_NAME} ${Boost_LIBRARIES})
endforeach()