# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/yds/webserver/ReactorHttp_cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yds/webserver/ReactorHttp_cpp/build

# Include any dependencies generated for this target.
include CMakeFiles/MyProject.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MyProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MyProject.dir/flags.make

CMakeFiles/MyProject.dir/main.cpp.o: CMakeFiles/MyProject.dir/flags.make
CMakeFiles/MyProject.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yds/webserver/ReactorHttp_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MyProject.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyProject.dir/main.cpp.o -c /home/yds/webserver/ReactorHttp_cpp/main.cpp

CMakeFiles/MyProject.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyProject.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yds/webserver/ReactorHttp_cpp/main.cpp > CMakeFiles/MyProject.dir/main.cpp.i

CMakeFiles/MyProject.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyProject.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yds/webserver/ReactorHttp_cpp/main.cpp -o CMakeFiles/MyProject.dir/main.cpp.s

CMakeFiles/MyProject.dir/src/Buffer.cpp.o: CMakeFiles/MyProject.dir/flags.make
CMakeFiles/MyProject.dir/src/Buffer.cpp.o: ../src/Buffer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yds/webserver/ReactorHttp_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/MyProject.dir/src/Buffer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyProject.dir/src/Buffer.cpp.o -c /home/yds/webserver/ReactorHttp_cpp/src/Buffer.cpp

CMakeFiles/MyProject.dir/src/Buffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyProject.dir/src/Buffer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yds/webserver/ReactorHttp_cpp/src/Buffer.cpp > CMakeFiles/MyProject.dir/src/Buffer.cpp.i

CMakeFiles/MyProject.dir/src/Buffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyProject.dir/src/Buffer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yds/webserver/ReactorHttp_cpp/src/Buffer.cpp -o CMakeFiles/MyProject.dir/src/Buffer.cpp.s

CMakeFiles/MyProject.dir/src/Channel.cpp.o: CMakeFiles/MyProject.dir/flags.make
CMakeFiles/MyProject.dir/src/Channel.cpp.o: ../src/Channel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yds/webserver/ReactorHttp_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/MyProject.dir/src/Channel.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyProject.dir/src/Channel.cpp.o -c /home/yds/webserver/ReactorHttp_cpp/src/Channel.cpp

CMakeFiles/MyProject.dir/src/Channel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyProject.dir/src/Channel.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yds/webserver/ReactorHttp_cpp/src/Channel.cpp > CMakeFiles/MyProject.dir/src/Channel.cpp.i

CMakeFiles/MyProject.dir/src/Channel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyProject.dir/src/Channel.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yds/webserver/ReactorHttp_cpp/src/Channel.cpp -o CMakeFiles/MyProject.dir/src/Channel.cpp.s

CMakeFiles/MyProject.dir/src/Dispatcher.cpp.o: CMakeFiles/MyProject.dir/flags.make
CMakeFiles/MyProject.dir/src/Dispatcher.cpp.o: ../src/Dispatcher.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yds/webserver/ReactorHttp_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/MyProject.dir/src/Dispatcher.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyProject.dir/src/Dispatcher.cpp.o -c /home/yds/webserver/ReactorHttp_cpp/src/Dispatcher.cpp

CMakeFiles/MyProject.dir/src/Dispatcher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyProject.dir/src/Dispatcher.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yds/webserver/ReactorHttp_cpp/src/Dispatcher.cpp > CMakeFiles/MyProject.dir/src/Dispatcher.cpp.i

CMakeFiles/MyProject.dir/src/Dispatcher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyProject.dir/src/Dispatcher.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yds/webserver/ReactorHttp_cpp/src/Dispatcher.cpp -o CMakeFiles/MyProject.dir/src/Dispatcher.cpp.s

CMakeFiles/MyProject.dir/src/EpollDispatcher.cpp.o: CMakeFiles/MyProject.dir/flags.make
CMakeFiles/MyProject.dir/src/EpollDispatcher.cpp.o: ../src/EpollDispatcher.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yds/webserver/ReactorHttp_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/MyProject.dir/src/EpollDispatcher.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyProject.dir/src/EpollDispatcher.cpp.o -c /home/yds/webserver/ReactorHttp_cpp/src/EpollDispatcher.cpp

CMakeFiles/MyProject.dir/src/EpollDispatcher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyProject.dir/src/EpollDispatcher.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yds/webserver/ReactorHttp_cpp/src/EpollDispatcher.cpp > CMakeFiles/MyProject.dir/src/EpollDispatcher.cpp.i

CMakeFiles/MyProject.dir/src/EpollDispatcher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyProject.dir/src/EpollDispatcher.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yds/webserver/ReactorHttp_cpp/src/EpollDispatcher.cpp -o CMakeFiles/MyProject.dir/src/EpollDispatcher.cpp.s

CMakeFiles/MyProject.dir/src/EventLoop.cpp.o: CMakeFiles/MyProject.dir/flags.make
CMakeFiles/MyProject.dir/src/EventLoop.cpp.o: ../src/EventLoop.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yds/webserver/ReactorHttp_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/MyProject.dir/src/EventLoop.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyProject.dir/src/EventLoop.cpp.o -c /home/yds/webserver/ReactorHttp_cpp/src/EventLoop.cpp

CMakeFiles/MyProject.dir/src/EventLoop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyProject.dir/src/EventLoop.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yds/webserver/ReactorHttp_cpp/src/EventLoop.cpp > CMakeFiles/MyProject.dir/src/EventLoop.cpp.i

CMakeFiles/MyProject.dir/src/EventLoop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyProject.dir/src/EventLoop.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yds/webserver/ReactorHttp_cpp/src/EventLoop.cpp -o CMakeFiles/MyProject.dir/src/EventLoop.cpp.s

CMakeFiles/MyProject.dir/src/HttpRequest.cpp.o: CMakeFiles/MyProject.dir/flags.make
CMakeFiles/MyProject.dir/src/HttpRequest.cpp.o: ../src/HttpRequest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yds/webserver/ReactorHttp_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/MyProject.dir/src/HttpRequest.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyProject.dir/src/HttpRequest.cpp.o -c /home/yds/webserver/ReactorHttp_cpp/src/HttpRequest.cpp

CMakeFiles/MyProject.dir/src/HttpRequest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyProject.dir/src/HttpRequest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yds/webserver/ReactorHttp_cpp/src/HttpRequest.cpp > CMakeFiles/MyProject.dir/src/HttpRequest.cpp.i

CMakeFiles/MyProject.dir/src/HttpRequest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyProject.dir/src/HttpRequest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yds/webserver/ReactorHttp_cpp/src/HttpRequest.cpp -o CMakeFiles/MyProject.dir/src/HttpRequest.cpp.s

CMakeFiles/MyProject.dir/src/HttpResponse.cpp.o: CMakeFiles/MyProject.dir/flags.make
CMakeFiles/MyProject.dir/src/HttpResponse.cpp.o: ../src/HttpResponse.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yds/webserver/ReactorHttp_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/MyProject.dir/src/HttpResponse.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyProject.dir/src/HttpResponse.cpp.o -c /home/yds/webserver/ReactorHttp_cpp/src/HttpResponse.cpp

CMakeFiles/MyProject.dir/src/HttpResponse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyProject.dir/src/HttpResponse.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yds/webserver/ReactorHttp_cpp/src/HttpResponse.cpp > CMakeFiles/MyProject.dir/src/HttpResponse.cpp.i

CMakeFiles/MyProject.dir/src/HttpResponse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyProject.dir/src/HttpResponse.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yds/webserver/ReactorHttp_cpp/src/HttpResponse.cpp -o CMakeFiles/MyProject.dir/src/HttpResponse.cpp.s

CMakeFiles/MyProject.dir/src/PollDispatcher.cpp.o: CMakeFiles/MyProject.dir/flags.make
CMakeFiles/MyProject.dir/src/PollDispatcher.cpp.o: ../src/PollDispatcher.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yds/webserver/ReactorHttp_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/MyProject.dir/src/PollDispatcher.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyProject.dir/src/PollDispatcher.cpp.o -c /home/yds/webserver/ReactorHttp_cpp/src/PollDispatcher.cpp

CMakeFiles/MyProject.dir/src/PollDispatcher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyProject.dir/src/PollDispatcher.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yds/webserver/ReactorHttp_cpp/src/PollDispatcher.cpp > CMakeFiles/MyProject.dir/src/PollDispatcher.cpp.i

CMakeFiles/MyProject.dir/src/PollDispatcher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyProject.dir/src/PollDispatcher.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yds/webserver/ReactorHttp_cpp/src/PollDispatcher.cpp -o CMakeFiles/MyProject.dir/src/PollDispatcher.cpp.s

CMakeFiles/MyProject.dir/src/SelectDispatcher.cpp.o: CMakeFiles/MyProject.dir/flags.make
CMakeFiles/MyProject.dir/src/SelectDispatcher.cpp.o: ../src/SelectDispatcher.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yds/webserver/ReactorHttp_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/MyProject.dir/src/SelectDispatcher.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyProject.dir/src/SelectDispatcher.cpp.o -c /home/yds/webserver/ReactorHttp_cpp/src/SelectDispatcher.cpp

CMakeFiles/MyProject.dir/src/SelectDispatcher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyProject.dir/src/SelectDispatcher.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yds/webserver/ReactorHttp_cpp/src/SelectDispatcher.cpp > CMakeFiles/MyProject.dir/src/SelectDispatcher.cpp.i

CMakeFiles/MyProject.dir/src/SelectDispatcher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyProject.dir/src/SelectDispatcher.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yds/webserver/ReactorHttp_cpp/src/SelectDispatcher.cpp -o CMakeFiles/MyProject.dir/src/SelectDispatcher.cpp.s

CMakeFiles/MyProject.dir/src/TcpConnection.cpp.o: CMakeFiles/MyProject.dir/flags.make
CMakeFiles/MyProject.dir/src/TcpConnection.cpp.o: ../src/TcpConnection.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yds/webserver/ReactorHttp_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/MyProject.dir/src/TcpConnection.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyProject.dir/src/TcpConnection.cpp.o -c /home/yds/webserver/ReactorHttp_cpp/src/TcpConnection.cpp

CMakeFiles/MyProject.dir/src/TcpConnection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyProject.dir/src/TcpConnection.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yds/webserver/ReactorHttp_cpp/src/TcpConnection.cpp > CMakeFiles/MyProject.dir/src/TcpConnection.cpp.i

CMakeFiles/MyProject.dir/src/TcpConnection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyProject.dir/src/TcpConnection.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yds/webserver/ReactorHttp_cpp/src/TcpConnection.cpp -o CMakeFiles/MyProject.dir/src/TcpConnection.cpp.s

CMakeFiles/MyProject.dir/src/TcpServer.cpp.o: CMakeFiles/MyProject.dir/flags.make
CMakeFiles/MyProject.dir/src/TcpServer.cpp.o: ../src/TcpServer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yds/webserver/ReactorHttp_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/MyProject.dir/src/TcpServer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyProject.dir/src/TcpServer.cpp.o -c /home/yds/webserver/ReactorHttp_cpp/src/TcpServer.cpp

CMakeFiles/MyProject.dir/src/TcpServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyProject.dir/src/TcpServer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yds/webserver/ReactorHttp_cpp/src/TcpServer.cpp > CMakeFiles/MyProject.dir/src/TcpServer.cpp.i

CMakeFiles/MyProject.dir/src/TcpServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyProject.dir/src/TcpServer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yds/webserver/ReactorHttp_cpp/src/TcpServer.cpp -o CMakeFiles/MyProject.dir/src/TcpServer.cpp.s

CMakeFiles/MyProject.dir/src/ThreadPool.cpp.o: CMakeFiles/MyProject.dir/flags.make
CMakeFiles/MyProject.dir/src/ThreadPool.cpp.o: ../src/ThreadPool.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yds/webserver/ReactorHttp_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/MyProject.dir/src/ThreadPool.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyProject.dir/src/ThreadPool.cpp.o -c /home/yds/webserver/ReactorHttp_cpp/src/ThreadPool.cpp

CMakeFiles/MyProject.dir/src/ThreadPool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyProject.dir/src/ThreadPool.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yds/webserver/ReactorHttp_cpp/src/ThreadPool.cpp > CMakeFiles/MyProject.dir/src/ThreadPool.cpp.i

CMakeFiles/MyProject.dir/src/ThreadPool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyProject.dir/src/ThreadPool.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yds/webserver/ReactorHttp_cpp/src/ThreadPool.cpp -o CMakeFiles/MyProject.dir/src/ThreadPool.cpp.s

CMakeFiles/MyProject.dir/src/WorkerThread.cpp.o: CMakeFiles/MyProject.dir/flags.make
CMakeFiles/MyProject.dir/src/WorkerThread.cpp.o: ../src/WorkerThread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yds/webserver/ReactorHttp_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/MyProject.dir/src/WorkerThread.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MyProject.dir/src/WorkerThread.cpp.o -c /home/yds/webserver/ReactorHttp_cpp/src/WorkerThread.cpp

CMakeFiles/MyProject.dir/src/WorkerThread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyProject.dir/src/WorkerThread.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yds/webserver/ReactorHttp_cpp/src/WorkerThread.cpp > CMakeFiles/MyProject.dir/src/WorkerThread.cpp.i

CMakeFiles/MyProject.dir/src/WorkerThread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyProject.dir/src/WorkerThread.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yds/webserver/ReactorHttp_cpp/src/WorkerThread.cpp -o CMakeFiles/MyProject.dir/src/WorkerThread.cpp.s

# Object files for target MyProject
MyProject_OBJECTS = \
"CMakeFiles/MyProject.dir/main.cpp.o" \
"CMakeFiles/MyProject.dir/src/Buffer.cpp.o" \
"CMakeFiles/MyProject.dir/src/Channel.cpp.o" \
"CMakeFiles/MyProject.dir/src/Dispatcher.cpp.o" \
"CMakeFiles/MyProject.dir/src/EpollDispatcher.cpp.o" \
"CMakeFiles/MyProject.dir/src/EventLoop.cpp.o" \
"CMakeFiles/MyProject.dir/src/HttpRequest.cpp.o" \
"CMakeFiles/MyProject.dir/src/HttpResponse.cpp.o" \
"CMakeFiles/MyProject.dir/src/PollDispatcher.cpp.o" \
"CMakeFiles/MyProject.dir/src/SelectDispatcher.cpp.o" \
"CMakeFiles/MyProject.dir/src/TcpConnection.cpp.o" \
"CMakeFiles/MyProject.dir/src/TcpServer.cpp.o" \
"CMakeFiles/MyProject.dir/src/ThreadPool.cpp.o" \
"CMakeFiles/MyProject.dir/src/WorkerThread.cpp.o"

# External object files for target MyProject
MyProject_EXTERNAL_OBJECTS =

MyProject: CMakeFiles/MyProject.dir/main.cpp.o
MyProject: CMakeFiles/MyProject.dir/src/Buffer.cpp.o
MyProject: CMakeFiles/MyProject.dir/src/Channel.cpp.o
MyProject: CMakeFiles/MyProject.dir/src/Dispatcher.cpp.o
MyProject: CMakeFiles/MyProject.dir/src/EpollDispatcher.cpp.o
MyProject: CMakeFiles/MyProject.dir/src/EventLoop.cpp.o
MyProject: CMakeFiles/MyProject.dir/src/HttpRequest.cpp.o
MyProject: CMakeFiles/MyProject.dir/src/HttpResponse.cpp.o
MyProject: CMakeFiles/MyProject.dir/src/PollDispatcher.cpp.o
MyProject: CMakeFiles/MyProject.dir/src/SelectDispatcher.cpp.o
MyProject: CMakeFiles/MyProject.dir/src/TcpConnection.cpp.o
MyProject: CMakeFiles/MyProject.dir/src/TcpServer.cpp.o
MyProject: CMakeFiles/MyProject.dir/src/ThreadPool.cpp.o
MyProject: CMakeFiles/MyProject.dir/src/WorkerThread.cpp.o
MyProject: CMakeFiles/MyProject.dir/build.make
MyProject: CMakeFiles/MyProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yds/webserver/ReactorHttp_cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Linking CXX executable MyProject"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MyProject.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MyProject.dir/build: MyProject

.PHONY : CMakeFiles/MyProject.dir/build

CMakeFiles/MyProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MyProject.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MyProject.dir/clean

CMakeFiles/MyProject.dir/depend:
	cd /home/yds/webserver/ReactorHttp_cpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yds/webserver/ReactorHttp_cpp /home/yds/webserver/ReactorHttp_cpp /home/yds/webserver/ReactorHttp_cpp/build /home/yds/webserver/ReactorHttp_cpp/build /home/yds/webserver/ReactorHttp_cpp/build/CMakeFiles/MyProject.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MyProject.dir/depend
