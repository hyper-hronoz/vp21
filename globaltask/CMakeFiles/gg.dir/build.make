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
CMAKE_SOURCE_DIR = /home/hronoz/vp21/globaltask

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hronoz/vp21/globaltask

# Include any dependencies generated for this target.
include CMakeFiles/gg.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/gg.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/gg.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gg.dir/flags.make

CMakeFiles/gg.dir/index.cpp.o: CMakeFiles/gg.dir/flags.make
CMakeFiles/gg.dir/index.cpp.o: index.cpp
CMakeFiles/gg.dir/index.cpp.o: CMakeFiles/gg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hronoz/vp21/globaltask/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/gg.dir/index.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gg.dir/index.cpp.o -MF CMakeFiles/gg.dir/index.cpp.o.d -o CMakeFiles/gg.dir/index.cpp.o -c /home/hronoz/vp21/globaltask/index.cpp

CMakeFiles/gg.dir/index.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gg.dir/index.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hronoz/vp21/globaltask/index.cpp > CMakeFiles/gg.dir/index.cpp.i

CMakeFiles/gg.dir/index.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gg.dir/index.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hronoz/vp21/globaltask/index.cpp -o CMakeFiles/gg.dir/index.cpp.s

CMakeFiles/gg.dir/src/Controllers/StartController.cpp.o: CMakeFiles/gg.dir/flags.make
CMakeFiles/gg.dir/src/Controllers/StartController.cpp.o: src/Controllers/StartController.cpp
CMakeFiles/gg.dir/src/Controllers/StartController.cpp.o: CMakeFiles/gg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hronoz/vp21/globaltask/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/gg.dir/src/Controllers/StartController.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gg.dir/src/Controllers/StartController.cpp.o -MF CMakeFiles/gg.dir/src/Controllers/StartController.cpp.o.d -o CMakeFiles/gg.dir/src/Controllers/StartController.cpp.o -c /home/hronoz/vp21/globaltask/src/Controllers/StartController.cpp

CMakeFiles/gg.dir/src/Controllers/StartController.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gg.dir/src/Controllers/StartController.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hronoz/vp21/globaltask/src/Controllers/StartController.cpp > CMakeFiles/gg.dir/src/Controllers/StartController.cpp.i

CMakeFiles/gg.dir/src/Controllers/StartController.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gg.dir/src/Controllers/StartController.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hronoz/vp21/globaltask/src/Controllers/StartController.cpp -o CMakeFiles/gg.dir/src/Controllers/StartController.cpp.s

CMakeFiles/gg.dir/src/Controllers/AuthenticationController.cpp.o: CMakeFiles/gg.dir/flags.make
CMakeFiles/gg.dir/src/Controllers/AuthenticationController.cpp.o: src/Controllers/AuthenticationController.cpp
CMakeFiles/gg.dir/src/Controllers/AuthenticationController.cpp.o: CMakeFiles/gg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hronoz/vp21/globaltask/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/gg.dir/src/Controllers/AuthenticationController.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gg.dir/src/Controllers/AuthenticationController.cpp.o -MF CMakeFiles/gg.dir/src/Controllers/AuthenticationController.cpp.o.d -o CMakeFiles/gg.dir/src/Controllers/AuthenticationController.cpp.o -c /home/hronoz/vp21/globaltask/src/Controllers/AuthenticationController.cpp

CMakeFiles/gg.dir/src/Controllers/AuthenticationController.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gg.dir/src/Controllers/AuthenticationController.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hronoz/vp21/globaltask/src/Controllers/AuthenticationController.cpp > CMakeFiles/gg.dir/src/Controllers/AuthenticationController.cpp.i

CMakeFiles/gg.dir/src/Controllers/AuthenticationController.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gg.dir/src/Controllers/AuthenticationController.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hronoz/vp21/globaltask/src/Controllers/AuthenticationController.cpp -o CMakeFiles/gg.dir/src/Controllers/AuthenticationController.cpp.s

CMakeFiles/gg.dir/src/Controllers/IntroController.cpp.o: CMakeFiles/gg.dir/flags.make
CMakeFiles/gg.dir/src/Controllers/IntroController.cpp.o: src/Controllers/IntroController.cpp
CMakeFiles/gg.dir/src/Controllers/IntroController.cpp.o: CMakeFiles/gg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hronoz/vp21/globaltask/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/gg.dir/src/Controllers/IntroController.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gg.dir/src/Controllers/IntroController.cpp.o -MF CMakeFiles/gg.dir/src/Controllers/IntroController.cpp.o.d -o CMakeFiles/gg.dir/src/Controllers/IntroController.cpp.o -c /home/hronoz/vp21/globaltask/src/Controllers/IntroController.cpp

CMakeFiles/gg.dir/src/Controllers/IntroController.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gg.dir/src/Controllers/IntroController.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hronoz/vp21/globaltask/src/Controllers/IntroController.cpp > CMakeFiles/gg.dir/src/Controllers/IntroController.cpp.i

CMakeFiles/gg.dir/src/Controllers/IntroController.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gg.dir/src/Controllers/IntroController.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hronoz/vp21/globaltask/src/Controllers/IntroController.cpp -o CMakeFiles/gg.dir/src/Controllers/IntroController.cpp.s

CMakeFiles/gg.dir/src/Controllers/ProviderController.cpp.o: CMakeFiles/gg.dir/flags.make
CMakeFiles/gg.dir/src/Controllers/ProviderController.cpp.o: src/Controllers/ProviderController.cpp
CMakeFiles/gg.dir/src/Controllers/ProviderController.cpp.o: CMakeFiles/gg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hronoz/vp21/globaltask/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/gg.dir/src/Controllers/ProviderController.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gg.dir/src/Controllers/ProviderController.cpp.o -MF CMakeFiles/gg.dir/src/Controllers/ProviderController.cpp.o.d -o CMakeFiles/gg.dir/src/Controllers/ProviderController.cpp.o -c /home/hronoz/vp21/globaltask/src/Controllers/ProviderController.cpp

CMakeFiles/gg.dir/src/Controllers/ProviderController.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gg.dir/src/Controllers/ProviderController.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hronoz/vp21/globaltask/src/Controllers/ProviderController.cpp > CMakeFiles/gg.dir/src/Controllers/ProviderController.cpp.i

CMakeFiles/gg.dir/src/Controllers/ProviderController.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gg.dir/src/Controllers/ProviderController.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hronoz/vp21/globaltask/src/Controllers/ProviderController.cpp -o CMakeFiles/gg.dir/src/Controllers/ProviderController.cpp.s

CMakeFiles/gg.dir/src/Controllers/DirectorController.cpp.o: CMakeFiles/gg.dir/flags.make
CMakeFiles/gg.dir/src/Controllers/DirectorController.cpp.o: src/Controllers/DirectorController.cpp
CMakeFiles/gg.dir/src/Controllers/DirectorController.cpp.o: CMakeFiles/gg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hronoz/vp21/globaltask/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/gg.dir/src/Controllers/DirectorController.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gg.dir/src/Controllers/DirectorController.cpp.o -MF CMakeFiles/gg.dir/src/Controllers/DirectorController.cpp.o.d -o CMakeFiles/gg.dir/src/Controllers/DirectorController.cpp.o -c /home/hronoz/vp21/globaltask/src/Controllers/DirectorController.cpp

CMakeFiles/gg.dir/src/Controllers/DirectorController.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gg.dir/src/Controllers/DirectorController.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hronoz/vp21/globaltask/src/Controllers/DirectorController.cpp > CMakeFiles/gg.dir/src/Controllers/DirectorController.cpp.i

CMakeFiles/gg.dir/src/Controllers/DirectorController.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gg.dir/src/Controllers/DirectorController.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hronoz/vp21/globaltask/src/Controllers/DirectorController.cpp -o CMakeFiles/gg.dir/src/Controllers/DirectorController.cpp.s

CMakeFiles/gg.dir/src/Views/StartView.cpp.o: CMakeFiles/gg.dir/flags.make
CMakeFiles/gg.dir/src/Views/StartView.cpp.o: src/Views/StartView.cpp
CMakeFiles/gg.dir/src/Views/StartView.cpp.o: CMakeFiles/gg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hronoz/vp21/globaltask/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/gg.dir/src/Views/StartView.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gg.dir/src/Views/StartView.cpp.o -MF CMakeFiles/gg.dir/src/Views/StartView.cpp.o.d -o CMakeFiles/gg.dir/src/Views/StartView.cpp.o -c /home/hronoz/vp21/globaltask/src/Views/StartView.cpp

CMakeFiles/gg.dir/src/Views/StartView.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gg.dir/src/Views/StartView.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hronoz/vp21/globaltask/src/Views/StartView.cpp > CMakeFiles/gg.dir/src/Views/StartView.cpp.i

CMakeFiles/gg.dir/src/Views/StartView.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gg.dir/src/Views/StartView.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hronoz/vp21/globaltask/src/Views/StartView.cpp -o CMakeFiles/gg.dir/src/Views/StartView.cpp.s

CMakeFiles/gg.dir/src/Views/AuthEmployerSignUpView.cpp.o: CMakeFiles/gg.dir/flags.make
CMakeFiles/gg.dir/src/Views/AuthEmployerSignUpView.cpp.o: src/Views/AuthEmployerSignUpView.cpp
CMakeFiles/gg.dir/src/Views/AuthEmployerSignUpView.cpp.o: CMakeFiles/gg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hronoz/vp21/globaltask/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/gg.dir/src/Views/AuthEmployerSignUpView.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gg.dir/src/Views/AuthEmployerSignUpView.cpp.o -MF CMakeFiles/gg.dir/src/Views/AuthEmployerSignUpView.cpp.o.d -o CMakeFiles/gg.dir/src/Views/AuthEmployerSignUpView.cpp.o -c /home/hronoz/vp21/globaltask/src/Views/AuthEmployerSignUpView.cpp

CMakeFiles/gg.dir/src/Views/AuthEmployerSignUpView.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gg.dir/src/Views/AuthEmployerSignUpView.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hronoz/vp21/globaltask/src/Views/AuthEmployerSignUpView.cpp > CMakeFiles/gg.dir/src/Views/AuthEmployerSignUpView.cpp.i

CMakeFiles/gg.dir/src/Views/AuthEmployerSignUpView.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gg.dir/src/Views/AuthEmployerSignUpView.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hronoz/vp21/globaltask/src/Views/AuthEmployerSignUpView.cpp -o CMakeFiles/gg.dir/src/Views/AuthEmployerSignUpView.cpp.s

CMakeFiles/gg.dir/src/Views/AuthEmployerLoginView.cpp.o: CMakeFiles/gg.dir/flags.make
CMakeFiles/gg.dir/src/Views/AuthEmployerLoginView.cpp.o: src/Views/AuthEmployerLoginView.cpp
CMakeFiles/gg.dir/src/Views/AuthEmployerLoginView.cpp.o: CMakeFiles/gg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hronoz/vp21/globaltask/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/gg.dir/src/Views/AuthEmployerLoginView.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gg.dir/src/Views/AuthEmployerLoginView.cpp.o -MF CMakeFiles/gg.dir/src/Views/AuthEmployerLoginView.cpp.o.d -o CMakeFiles/gg.dir/src/Views/AuthEmployerLoginView.cpp.o -c /home/hronoz/vp21/globaltask/src/Views/AuthEmployerLoginView.cpp

CMakeFiles/gg.dir/src/Views/AuthEmployerLoginView.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gg.dir/src/Views/AuthEmployerLoginView.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hronoz/vp21/globaltask/src/Views/AuthEmployerLoginView.cpp > CMakeFiles/gg.dir/src/Views/AuthEmployerLoginView.cpp.i

CMakeFiles/gg.dir/src/Views/AuthEmployerLoginView.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gg.dir/src/Views/AuthEmployerLoginView.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hronoz/vp21/globaltask/src/Views/AuthEmployerLoginView.cpp -o CMakeFiles/gg.dir/src/Views/AuthEmployerLoginView.cpp.s

CMakeFiles/gg.dir/src/Views/AuthProviderSignUpView.cpp.o: CMakeFiles/gg.dir/flags.make
CMakeFiles/gg.dir/src/Views/AuthProviderSignUpView.cpp.o: src/Views/AuthProviderSignUpView.cpp
CMakeFiles/gg.dir/src/Views/AuthProviderSignUpView.cpp.o: CMakeFiles/gg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hronoz/vp21/globaltask/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/gg.dir/src/Views/AuthProviderSignUpView.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gg.dir/src/Views/AuthProviderSignUpView.cpp.o -MF CMakeFiles/gg.dir/src/Views/AuthProviderSignUpView.cpp.o.d -o CMakeFiles/gg.dir/src/Views/AuthProviderSignUpView.cpp.o -c /home/hronoz/vp21/globaltask/src/Views/AuthProviderSignUpView.cpp

CMakeFiles/gg.dir/src/Views/AuthProviderSignUpView.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gg.dir/src/Views/AuthProviderSignUpView.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hronoz/vp21/globaltask/src/Views/AuthProviderSignUpView.cpp > CMakeFiles/gg.dir/src/Views/AuthProviderSignUpView.cpp.i

CMakeFiles/gg.dir/src/Views/AuthProviderSignUpView.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gg.dir/src/Views/AuthProviderSignUpView.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hronoz/vp21/globaltask/src/Views/AuthProviderSignUpView.cpp -o CMakeFiles/gg.dir/src/Views/AuthProviderSignUpView.cpp.s

CMakeFiles/gg.dir/src/Views/AuthProviderLoginView.cpp.o: CMakeFiles/gg.dir/flags.make
CMakeFiles/gg.dir/src/Views/AuthProviderLoginView.cpp.o: src/Views/AuthProviderLoginView.cpp
CMakeFiles/gg.dir/src/Views/AuthProviderLoginView.cpp.o: CMakeFiles/gg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hronoz/vp21/globaltask/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/gg.dir/src/Views/AuthProviderLoginView.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gg.dir/src/Views/AuthProviderLoginView.cpp.o -MF CMakeFiles/gg.dir/src/Views/AuthProviderLoginView.cpp.o.d -o CMakeFiles/gg.dir/src/Views/AuthProviderLoginView.cpp.o -c /home/hronoz/vp21/globaltask/src/Views/AuthProviderLoginView.cpp

CMakeFiles/gg.dir/src/Views/AuthProviderLoginView.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gg.dir/src/Views/AuthProviderLoginView.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hronoz/vp21/globaltask/src/Views/AuthProviderLoginView.cpp > CMakeFiles/gg.dir/src/Views/AuthProviderLoginView.cpp.i

CMakeFiles/gg.dir/src/Views/AuthProviderLoginView.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gg.dir/src/Views/AuthProviderLoginView.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hronoz/vp21/globaltask/src/Views/AuthProviderLoginView.cpp -o CMakeFiles/gg.dir/src/Views/AuthProviderLoginView.cpp.s

CMakeFiles/gg.dir/src/Views/DirectorView.cpp.o: CMakeFiles/gg.dir/flags.make
CMakeFiles/gg.dir/src/Views/DirectorView.cpp.o: src/Views/DirectorView.cpp
CMakeFiles/gg.dir/src/Views/DirectorView.cpp.o: CMakeFiles/gg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hronoz/vp21/globaltask/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/gg.dir/src/Views/DirectorView.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gg.dir/src/Views/DirectorView.cpp.o -MF CMakeFiles/gg.dir/src/Views/DirectorView.cpp.o.d -o CMakeFiles/gg.dir/src/Views/DirectorView.cpp.o -c /home/hronoz/vp21/globaltask/src/Views/DirectorView.cpp

CMakeFiles/gg.dir/src/Views/DirectorView.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gg.dir/src/Views/DirectorView.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hronoz/vp21/globaltask/src/Views/DirectorView.cpp > CMakeFiles/gg.dir/src/Views/DirectorView.cpp.i

CMakeFiles/gg.dir/src/Views/DirectorView.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gg.dir/src/Views/DirectorView.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hronoz/vp21/globaltask/src/Views/DirectorView.cpp -o CMakeFiles/gg.dir/src/Views/DirectorView.cpp.s

CMakeFiles/gg.dir/src/Views/IntoView.cpp.o: CMakeFiles/gg.dir/flags.make
CMakeFiles/gg.dir/src/Views/IntoView.cpp.o: src/Views/IntoView.cpp
CMakeFiles/gg.dir/src/Views/IntoView.cpp.o: CMakeFiles/gg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hronoz/vp21/globaltask/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/gg.dir/src/Views/IntoView.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gg.dir/src/Views/IntoView.cpp.o -MF CMakeFiles/gg.dir/src/Views/IntoView.cpp.o.d -o CMakeFiles/gg.dir/src/Views/IntoView.cpp.o -c /home/hronoz/vp21/globaltask/src/Views/IntoView.cpp

CMakeFiles/gg.dir/src/Views/IntoView.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gg.dir/src/Views/IntoView.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hronoz/vp21/globaltask/src/Views/IntoView.cpp > CMakeFiles/gg.dir/src/Views/IntoView.cpp.i

CMakeFiles/gg.dir/src/Views/IntoView.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gg.dir/src/Views/IntoView.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hronoz/vp21/globaltask/src/Views/IntoView.cpp -o CMakeFiles/gg.dir/src/Views/IntoView.cpp.s

CMakeFiles/gg.dir/src/Views/AuthenticationView.cpp.o: CMakeFiles/gg.dir/flags.make
CMakeFiles/gg.dir/src/Views/AuthenticationView.cpp.o: src/Views/AuthenticationView.cpp
CMakeFiles/gg.dir/src/Views/AuthenticationView.cpp.o: CMakeFiles/gg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hronoz/vp21/globaltask/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/gg.dir/src/Views/AuthenticationView.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gg.dir/src/Views/AuthenticationView.cpp.o -MF CMakeFiles/gg.dir/src/Views/AuthenticationView.cpp.o.d -o CMakeFiles/gg.dir/src/Views/AuthenticationView.cpp.o -c /home/hronoz/vp21/globaltask/src/Views/AuthenticationView.cpp

CMakeFiles/gg.dir/src/Views/AuthenticationView.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gg.dir/src/Views/AuthenticationView.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hronoz/vp21/globaltask/src/Views/AuthenticationView.cpp > CMakeFiles/gg.dir/src/Views/AuthenticationView.cpp.i

CMakeFiles/gg.dir/src/Views/AuthenticationView.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gg.dir/src/Views/AuthenticationView.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hronoz/vp21/globaltask/src/Views/AuthenticationView.cpp -o CMakeFiles/gg.dir/src/Views/AuthenticationView.cpp.s

CMakeFiles/gg.dir/src/Views/ProviderView.cpp.o: CMakeFiles/gg.dir/flags.make
CMakeFiles/gg.dir/src/Views/ProviderView.cpp.o: src/Views/ProviderView.cpp
CMakeFiles/gg.dir/src/Views/ProviderView.cpp.o: CMakeFiles/gg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hronoz/vp21/globaltask/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/gg.dir/src/Views/ProviderView.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gg.dir/src/Views/ProviderView.cpp.o -MF CMakeFiles/gg.dir/src/Views/ProviderView.cpp.o.d -o CMakeFiles/gg.dir/src/Views/ProviderView.cpp.o -c /home/hronoz/vp21/globaltask/src/Views/ProviderView.cpp

CMakeFiles/gg.dir/src/Views/ProviderView.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gg.dir/src/Views/ProviderView.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hronoz/vp21/globaltask/src/Views/ProviderView.cpp > CMakeFiles/gg.dir/src/Views/ProviderView.cpp.i

CMakeFiles/gg.dir/src/Views/ProviderView.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gg.dir/src/Views/ProviderView.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hronoz/vp21/globaltask/src/Views/ProviderView.cpp -o CMakeFiles/gg.dir/src/Views/ProviderView.cpp.s

CMakeFiles/gg.dir/src/Views/Menu/Menu.cpp.o: CMakeFiles/gg.dir/flags.make
CMakeFiles/gg.dir/src/Views/Menu/Menu.cpp.o: src/Views/Menu/Menu.cpp
CMakeFiles/gg.dir/src/Views/Menu/Menu.cpp.o: CMakeFiles/gg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hronoz/vp21/globaltask/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/gg.dir/src/Views/Menu/Menu.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gg.dir/src/Views/Menu/Menu.cpp.o -MF CMakeFiles/gg.dir/src/Views/Menu/Menu.cpp.o.d -o CMakeFiles/gg.dir/src/Views/Menu/Menu.cpp.o -c /home/hronoz/vp21/globaltask/src/Views/Menu/Menu.cpp

CMakeFiles/gg.dir/src/Views/Menu/Menu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gg.dir/src/Views/Menu/Menu.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hronoz/vp21/globaltask/src/Views/Menu/Menu.cpp > CMakeFiles/gg.dir/src/Views/Menu/Menu.cpp.i

CMakeFiles/gg.dir/src/Views/Menu/Menu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gg.dir/src/Views/Menu/Menu.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hronoz/vp21/globaltask/src/Views/Menu/Menu.cpp -o CMakeFiles/gg.dir/src/Views/Menu/Menu.cpp.s

CMakeFiles/gg.dir/src/Views/Menu/MenuItem.cpp.o: CMakeFiles/gg.dir/flags.make
CMakeFiles/gg.dir/src/Views/Menu/MenuItem.cpp.o: src/Views/Menu/MenuItem.cpp
CMakeFiles/gg.dir/src/Views/Menu/MenuItem.cpp.o: CMakeFiles/gg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hronoz/vp21/globaltask/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/gg.dir/src/Views/Menu/MenuItem.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gg.dir/src/Views/Menu/MenuItem.cpp.o -MF CMakeFiles/gg.dir/src/Views/Menu/MenuItem.cpp.o.d -o CMakeFiles/gg.dir/src/Views/Menu/MenuItem.cpp.o -c /home/hronoz/vp21/globaltask/src/Views/Menu/MenuItem.cpp

CMakeFiles/gg.dir/src/Views/Menu/MenuItem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gg.dir/src/Views/Menu/MenuItem.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hronoz/vp21/globaltask/src/Views/Menu/MenuItem.cpp > CMakeFiles/gg.dir/src/Views/Menu/MenuItem.cpp.i

CMakeFiles/gg.dir/src/Views/Menu/MenuItem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gg.dir/src/Views/Menu/MenuItem.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hronoz/vp21/globaltask/src/Views/Menu/MenuItem.cpp -o CMakeFiles/gg.dir/src/Views/Menu/MenuItem.cpp.s

CMakeFiles/gg.dir/src/Views/Menu/MenuItemFactory.cpp.o: CMakeFiles/gg.dir/flags.make
CMakeFiles/gg.dir/src/Views/Menu/MenuItemFactory.cpp.o: src/Views/Menu/MenuItemFactory.cpp
CMakeFiles/gg.dir/src/Views/Menu/MenuItemFactory.cpp.o: CMakeFiles/gg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hronoz/vp21/globaltask/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building CXX object CMakeFiles/gg.dir/src/Views/Menu/MenuItemFactory.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gg.dir/src/Views/Menu/MenuItemFactory.cpp.o -MF CMakeFiles/gg.dir/src/Views/Menu/MenuItemFactory.cpp.o.d -o CMakeFiles/gg.dir/src/Views/Menu/MenuItemFactory.cpp.o -c /home/hronoz/vp21/globaltask/src/Views/Menu/MenuItemFactory.cpp

CMakeFiles/gg.dir/src/Views/Menu/MenuItemFactory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gg.dir/src/Views/Menu/MenuItemFactory.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hronoz/vp21/globaltask/src/Views/Menu/MenuItemFactory.cpp > CMakeFiles/gg.dir/src/Views/Menu/MenuItemFactory.cpp.i

CMakeFiles/gg.dir/src/Views/Menu/MenuItemFactory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gg.dir/src/Views/Menu/MenuItemFactory.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hronoz/vp21/globaltask/src/Views/Menu/MenuItemFactory.cpp -o CMakeFiles/gg.dir/src/Views/Menu/MenuItemFactory.cpp.s

# Object files for target gg
gg_OBJECTS = \
"CMakeFiles/gg.dir/index.cpp.o" \
"CMakeFiles/gg.dir/src/Controllers/StartController.cpp.o" \
"CMakeFiles/gg.dir/src/Controllers/AuthenticationController.cpp.o" \
"CMakeFiles/gg.dir/src/Controllers/IntroController.cpp.o" \
"CMakeFiles/gg.dir/src/Controllers/ProviderController.cpp.o" \
"CMakeFiles/gg.dir/src/Controllers/DirectorController.cpp.o" \
"CMakeFiles/gg.dir/src/Views/StartView.cpp.o" \
"CMakeFiles/gg.dir/src/Views/AuthEmployerSignUpView.cpp.o" \
"CMakeFiles/gg.dir/src/Views/AuthEmployerLoginView.cpp.o" \
"CMakeFiles/gg.dir/src/Views/AuthProviderSignUpView.cpp.o" \
"CMakeFiles/gg.dir/src/Views/AuthProviderLoginView.cpp.o" \
"CMakeFiles/gg.dir/src/Views/DirectorView.cpp.o" \
"CMakeFiles/gg.dir/src/Views/IntoView.cpp.o" \
"CMakeFiles/gg.dir/src/Views/AuthenticationView.cpp.o" \
"CMakeFiles/gg.dir/src/Views/ProviderView.cpp.o" \
"CMakeFiles/gg.dir/src/Views/Menu/Menu.cpp.o" \
"CMakeFiles/gg.dir/src/Views/Menu/MenuItem.cpp.o" \
"CMakeFiles/gg.dir/src/Views/Menu/MenuItemFactory.cpp.o"

# External object files for target gg
gg_EXTERNAL_OBJECTS =

gg: CMakeFiles/gg.dir/index.cpp.o
gg: CMakeFiles/gg.dir/src/Controllers/StartController.cpp.o
gg: CMakeFiles/gg.dir/src/Controllers/AuthenticationController.cpp.o
gg: CMakeFiles/gg.dir/src/Controllers/IntroController.cpp.o
gg: CMakeFiles/gg.dir/src/Controllers/ProviderController.cpp.o
gg: CMakeFiles/gg.dir/src/Controllers/DirectorController.cpp.o
gg: CMakeFiles/gg.dir/src/Views/StartView.cpp.o
gg: CMakeFiles/gg.dir/src/Views/AuthEmployerSignUpView.cpp.o
gg: CMakeFiles/gg.dir/src/Views/AuthEmployerLoginView.cpp.o
gg: CMakeFiles/gg.dir/src/Views/AuthProviderSignUpView.cpp.o
gg: CMakeFiles/gg.dir/src/Views/AuthProviderLoginView.cpp.o
gg: CMakeFiles/gg.dir/src/Views/DirectorView.cpp.o
gg: CMakeFiles/gg.dir/src/Views/IntoView.cpp.o
gg: CMakeFiles/gg.dir/src/Views/AuthenticationView.cpp.o
gg: CMakeFiles/gg.dir/src/Views/ProviderView.cpp.o
gg: CMakeFiles/gg.dir/src/Views/Menu/Menu.cpp.o
gg: CMakeFiles/gg.dir/src/Views/Menu/MenuItem.cpp.o
gg: CMakeFiles/gg.dir/src/Views/Menu/MenuItemFactory.cpp.o
gg: CMakeFiles/gg.dir/build.make
gg: CMakeFiles/gg.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hronoz/vp21/globaltask/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Linking CXX executable gg"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gg.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gg.dir/build: gg
.PHONY : CMakeFiles/gg.dir/build

CMakeFiles/gg.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gg.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gg.dir/clean

CMakeFiles/gg.dir/depend:
	cd /home/hronoz/vp21/globaltask && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hronoz/vp21/globaltask /home/hronoz/vp21/globaltask /home/hronoz/vp21/globaltask /home/hronoz/vp21/globaltask /home/hronoz/vp21/globaltask/CMakeFiles/gg.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gg.dir/depend

