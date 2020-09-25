# 设置cmake最低的版本号
cmake_minimum_required(VERSION 3.10)

# 设置项目名和版本号
project(Tutorial VERSION 1.0) 

# 指定C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(USE_MYMATH "Use tutorial provided math implementation" ON)

# 配置头文件以传递某些CMake设置到源代码
configure_file(tutorial.h.in tutorial.h)

# 添加可执行的文件
add_executable(Tutorial tutorial.cc)


# 添加MathFunctions库
add_subdirectory(MathFunctions)

if(USE_MYMATH)
    add_subdirectory(MathFunctions)
    list(APPEND EXTRA_LIBS MathFunctions)
    list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MathFunctions")
endif()
    


# 添加可执行程序
add_executable(Tutorial tutorial.cc)

target_link_libraries(Tutorial PUBLIC ${EXTRA_LIBS})

# 将二叉树添加到包含文件的搜索路径以便让我们能够找到tutorial.h
target_include_directories(Tutorial PUBLIC
             "${PROJECT_BINARY_DIR}"
             ${EXTRA_INCLUDES}
             )


