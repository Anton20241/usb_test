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
CMAKE_SOURCE_DIR = /home/anton20241/usb_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/anton20241/usb_test/build

# Include any dependencies generated for this target.
include CMakeFiles/usb_test_pub.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/usb_test_pub.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/usb_test_pub.dir/flags.make

CMakeFiles/usb_test_pub.dir/usb_test_pub.cpp.o: CMakeFiles/usb_test_pub.dir/flags.make
CMakeFiles/usb_test_pub.dir/usb_test_pub.cpp.o: ../usb_test_pub.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anton20241/usb_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/usb_test_pub.dir/usb_test_pub.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/usb_test_pub.dir/usb_test_pub.cpp.o -c /home/anton20241/usb_test/usb_test_pub.cpp

CMakeFiles/usb_test_pub.dir/usb_test_pub.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/usb_test_pub.dir/usb_test_pub.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anton20241/usb_test/usb_test_pub.cpp > CMakeFiles/usb_test_pub.dir/usb_test_pub.cpp.i

CMakeFiles/usb_test_pub.dir/usb_test_pub.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/usb_test_pub.dir/usb_test_pub.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anton20241/usb_test/usb_test_pub.cpp -o CMakeFiles/usb_test_pub.dir/usb_test_pub.cpp.s

CMakeFiles/usb_test_pub.dir/SerialPort.cpp.o: CMakeFiles/usb_test_pub.dir/flags.make
CMakeFiles/usb_test_pub.dir/SerialPort.cpp.o: ../SerialPort.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anton20241/usb_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/usb_test_pub.dir/SerialPort.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/usb_test_pub.dir/SerialPort.cpp.o -c /home/anton20241/usb_test/SerialPort.cpp

CMakeFiles/usb_test_pub.dir/SerialPort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/usb_test_pub.dir/SerialPort.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anton20241/usb_test/SerialPort.cpp > CMakeFiles/usb_test_pub.dir/SerialPort.cpp.i

CMakeFiles/usb_test_pub.dir/SerialPort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/usb_test_pub.dir/SerialPort.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anton20241/usb_test/SerialPort.cpp -o CMakeFiles/usb_test_pub.dir/SerialPort.cpp.s

# Object files for target usb_test_pub
usb_test_pub_OBJECTS = \
"CMakeFiles/usb_test_pub.dir/usb_test_pub.cpp.o" \
"CMakeFiles/usb_test_pub.dir/SerialPort.cpp.o"

# External object files for target usb_test_pub
usb_test_pub_EXTERNAL_OBJECTS =

usb_test_pub: CMakeFiles/usb_test_pub.dir/usb_test_pub.cpp.o
usb_test_pub: CMakeFiles/usb_test_pub.dir/SerialPort.cpp.o
usb_test_pub: CMakeFiles/usb_test_pub.dir/build.make
usb_test_pub: CMakeFiles/usb_test_pub.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/anton20241/usb_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable usb_test_pub"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/usb_test_pub.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/usb_test_pub.dir/build: usb_test_pub

.PHONY : CMakeFiles/usb_test_pub.dir/build

CMakeFiles/usb_test_pub.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/usb_test_pub.dir/cmake_clean.cmake
.PHONY : CMakeFiles/usb_test_pub.dir/clean

CMakeFiles/usb_test_pub.dir/depend:
	cd /home/anton20241/usb_test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anton20241/usb_test /home/anton20241/usb_test /home/anton20241/usb_test/build /home/anton20241/usb_test/build /home/anton20241/usb_test/build/CMakeFiles/usb_test_pub.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/usb_test_pub.dir/depend
