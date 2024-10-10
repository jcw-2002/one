cmake_minimum_required(VERSION 3.5)
project(SmartCarProject)

# 指定C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加可执行文件
add_executable(SmartCar main.cpp SmartCar.cpp)

# 如果你有任何头文件目录，可以添加以下行
# include_directories(${CMAKE_SOURCE_DIR})
