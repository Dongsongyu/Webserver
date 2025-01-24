cmake_minimum_required(VERSION 3.0)
project(database_connect_pool)

# 指定 C++20 标准
set(CMAKE_CXX_STANDARD 20)

# 生成 ycm 可识别的 JSON 文件，让源文件找到头文件
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 源文件、头文件、输出路径
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC)
include_directories(${PROJECT_SOURCE_DIR}/include)
set(EXECUTABLE_OUTPUT_PATH ../bin)

# 调试设置
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

# 添加测试主程序
set(SRC ${SRC} ${PROJECT_SOURCE_DIR}/main.cpp)  # 添加 main.cpp 文件

# 输出可执行文件
add_executable(database_connect_pool ${SRC})

# 链接动态库，使用 jsoncpp
target_link_libraries(database_connect_pool jsoncpp)

# 链接动态库，使用 mysqlclient
target_link_libraries(database_connect_pool mysqlclient)

# 链接线程库（解决 pthread_create 链接问题）
find_package(Threads REQUIRED)
target_link_libraries(database_connect_pool Threads::Threads)
