# 设置cmake最低的版本号
cmake_minimum_required(VERSION 3.10)

# 设置项目名和版本号
project(Tutorial VERSION 1.0) 

# 指定C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(tutorial.h.in tutorial.h)

# 添加可执行的文件
add_executable(Tutorial tutorial.cc)

target_include_directories(Tutorial PUBLIC
             "${PROJECT_BINARY_DIR}"
             )
    