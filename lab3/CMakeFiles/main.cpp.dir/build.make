# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/hronoz/vp21/lab3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hronoz/vp21/lab3

# Include any dependencies generated for this target.
include CMakeFiles/main.cpp.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main.cpp.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main.cpp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.cpp.dir/flags.make

CMakeFiles/main.cpp.dir/src/Views/AView.cpp.o: CMakeFiles/main.cpp.dir/flags.make
CMakeFiles/main.cpp.dir/src/Views/AView.cpp.o: src/Views/AView.cpp
CMakeFiles/main.cpp.dir/src/Views/AView.cpp.o: CMakeFiles/main.cpp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hronoz/vp21/lab3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.cpp.dir/src/Views/AView.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.cpp.dir/src/Views/AView.cpp.o -MF CMakeFiles/main.cpp.dir/src/Views/AView.cpp.o.d -o CMakeFiles/main.cpp.dir/src/Views/AView.cpp.o -c /home/hronoz/vp21/lab3/src/Views/AView.cpp

CMakeFiles/main.cpp.dir/src/Views/AView.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.cpp.dir/src/Views/AView.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hronoz/vp21/lab3/src/Views/AView.cpp > CMakeFiles/main.cpp.dir/src/Views/AView.cpp.i

CMakeFiles/main.cpp.dir/src/Views/AView.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.cpp.dir/src/Views/AView.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hronoz/vp21/lab3/src/Views/AView.cpp -o CMakeFiles/main.cpp.dir/src/Views/AView.cpp.s

CMakeFiles/main.cpp.dir/src/Views/Menu/MenuItemFactory.cpp.o: CMakeFiles/main.cpp.dir/flags.make
CMakeFiles/main.cpp.dir/src/Views/Menu/MenuItemFactory.cpp.o: src/Views/Menu/MenuItemFactory.cpp
CMakeFiles/main.cpp.dir/src/Views/Menu/MenuItemFactory.cpp.o: CMakeFiles/main.cpp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hronoz/vp21/lab3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main.cpp.dir/src/Views/Menu/MenuItemFactory.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.cpp.dir/src/Views/Menu/MenuItemFactory.cpp.o -MF CMakeFiles/main.cpp.dir/src/Views/Menu/MenuItemFactory.cpp.o.d -o CMakeFiles/main.cpp.dir/src/Views/Menu/MenuItemFactory.cpp.o -c /home/hronoz/vp21/lab3/src/Views/Menu/MenuItemFactory.cpp

CMakeFiles/main.cpp.dir/src/Views/Menu/MenuItemFactory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.cpp.dir/src/Views/Menu/MenuItemFactory.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hronoz/vp21/lab3/src/Views/Menu/MenuItemFactory.cpp > CMakeFiles/main.cpp.dir/src/Views/Menu/MenuItemFactory.cpp.i

CMakeFiles/main.cpp.dir/src/Views/Menu/MenuItemFactory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.cpp.dir/src/Views/Menu/MenuItemFactory.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hronoz/vp21/lab3/src/Views/Menu/MenuItemFactory.cpp -o CMakeFiles/main.cpp.dir/src/Views/Menu/MenuItemFactory.cpp.s

CMakeFiles/main.cpp.dir/src/Views/Menu/MenuItem.cpp.o: CMakeFiles/main.cpp.dir/flags.make
CMakeFiles/main.cpp.dir/src/Views/Menu/MenuItem.cpp.o: src/Views/Menu/MenuItem.cpp
CMakeFiles/main.cpp.dir/src/Views/Menu/MenuItem.cpp.o: CMakeFiles/main.cpp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hronoz/vp21/lab3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main.cpp.dir/src/Views/Menu/MenuItem.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.cpp.dir/src/Views/Menu/MenuItem.cpp.o -MF CMakeFiles/main.cpp.dir/src/Views/Menu/MenuItem.cpp.o.d -o CMakeFiles/main.cpp.dir/src/Views/Menu/MenuItem.cpp.o -c /home/hronoz/vp21/lab3/src/Views/Menu/MenuItem.cpp

CMakeFiles/main.cpp.dir/src/Views/Menu/MenuItem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.cpp.dir/src/Views/Menu/MenuItem.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hronoz/vp21/lab3/src/Views/Menu/MenuItem.cpp > CMakeFiles/main.cpp.dir/src/Views/Menu/MenuItem.cpp.i

CMakeFiles/main.cpp.dir/src/Views/Menu/MenuItem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.cpp.dir/src/Views/Menu/MenuItem.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hronoz/vp21/lab3/src/Views/Menu/MenuItem.cpp -o CMakeFiles/main.cpp.dir/src/Views/Menu/MenuItem.cpp.s

CMakeFiles/main.cpp.dir/src/Views/Menu/Menu.cpp.o: CMakeFiles/main.cpp.dir/flags.make
CMakeFiles/main.cpp.dir/src/Views/Menu/Menu.cpp.o: src/Views/Menu/Menu.cpp
CMakeFiles/main.cpp.dir/src/Views/Menu/Menu.cpp.o: CMakeFiles/main.cpp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hronoz/vp21/lab3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/main.cpp.dir/src/Views/Menu/Menu.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.cpp.dir/src/Views/Menu/Menu.cpp.o -MF CMakeFiles/main.cpp.dir/src/Views/Menu/Menu.cpp.o.d -o CMakeFiles/main.cpp.dir/src/Views/Menu/Menu.cpp.o -c /home/hronoz/vp21/lab3/src/Views/Menu/Menu.cpp

CMakeFiles/main.cpp.dir/src/Views/Menu/Menu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.cpp.dir/src/Views/Menu/Menu.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hronoz/vp21/lab3/src/Views/Menu/Menu.cpp > CMakeFiles/main.cpp.dir/src/Views/Menu/Menu.cpp.i

CMakeFiles/main.cpp.dir/src/Views/Menu/Menu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.cpp.dir/src/Views/Menu/Menu.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hronoz/vp21/lab3/src/Views/Menu/Menu.cpp -o CMakeFiles/main.cpp.dir/src/Views/Menu/Menu.cpp.s

# Object files for target main.cpp
main_cpp_OBJECTS = \
"CMakeFiles/main.cpp.dir/src/Views/AView.cpp.o" \
"CMakeFiles/main.cpp.dir/src/Views/Menu/MenuItemFactory.cpp.o" \
"CMakeFiles/main.cpp.dir/src/Views/Menu/MenuItem.cpp.o" \
"CMakeFiles/main.cpp.dir/src/Views/Menu/Menu.cpp.o"

# External object files for target main.cpp
main_cpp_EXTERNAL_OBJECTS =

main.cpp: CMakeFiles/main.cpp.dir/src/Views/AView.cpp.o
main.cpp: CMakeFiles/main.cpp.dir/src/Views/Menu/MenuItemFactory.cpp.o
main.cpp: CMakeFiles/main.cpp.dir/src/Views/Menu/MenuItem.cpp.o
main.cpp: CMakeFiles/main.cpp.dir/src/Views/Menu/Menu.cpp.o
main.cpp: CMakeFiles/main.cpp.dir/build.make
main.cpp: CMakeFiles/main.cpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hronoz/vp21/lab3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable main.cpp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.cpp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.cpp.dir/build: main.cpp
.PHONY : CMakeFiles/main.cpp.dir/build

CMakeFiles/main.cpp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.cpp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.cpp.dir/clean

CMakeFiles/main.cpp.dir/depend:
	cd /home/hronoz/vp21/lab3 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hronoz/vp21/lab3 /home/hronoz/vp21/lab3 /home/hronoz/vp21/lab3 /home/hronoz/vp21/lab3 /home/hronoz/vp21/lab3/CMakeFiles/main.cpp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.cpp.dir/depend

