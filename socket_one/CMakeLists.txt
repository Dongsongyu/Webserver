cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(MyProject)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 包含头文件路径
include_directories(include)

# 添加源文件
add_executable(MyProject
    main.cpp
    src/server.cpp
)

# 链接 pthread 库
target_link_libraries(MyProject PRIVATE pthread)

