cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(MyProject C)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 包含头文件路径
include_directories(include)

# 指定要生成的源文件和可执行文件
add_executable(MyProject
    main.c
    src/Buffer.c
    src/Channel.c
    src/ChannelMap.c
    src/EpollDispatcher.c
    src/EventLoop.c
    src/HttpRequest.c
    src/Httpresponse.c
    src/PollDispatcher.c
    src/SelectDispatcher.c
    src/TcpConnection.c
    src/TcpServer.c
    src/ThreadPool.c
    src/WorkerThread.c
)

# 链接 pthread 库
target_link_libraries(MyProject PRIVATE pthread)