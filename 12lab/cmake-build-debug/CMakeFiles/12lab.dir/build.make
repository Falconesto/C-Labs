# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\labs\C-Labs\12lab

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\labs\C-Labs\12lab\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/12lab.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/12lab.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/12lab.dir/flags.make

CMakeFiles/12lab.dir/main.c.obj: CMakeFiles/12lab.dir/flags.make
CMakeFiles/12lab.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\labs\C-Labs\12lab\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/12lab.dir/main.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\12lab.dir\main.c.obj   -c D:\labs\C-Labs\12lab\main.c

CMakeFiles/12lab.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/12lab.dir/main.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\labs\C-Labs\12lab\main.c > CMakeFiles\12lab.dir\main.c.i

CMakeFiles/12lab.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/12lab.dir/main.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\labs\C-Labs\12lab\main.c -o CMakeFiles\12lab.dir\main.c.s

# Object files for target 12lab
12lab_OBJECTS = \
"CMakeFiles/12lab.dir/main.c.obj"

# External object files for target 12lab
12lab_EXTERNAL_OBJECTS =

12lab.exe: CMakeFiles/12lab.dir/main.c.obj
12lab.exe: CMakeFiles/12lab.dir/build.make
12lab.exe: CMakeFiles/12lab.dir/linklibs.rsp
12lab.exe: CMakeFiles/12lab.dir/objects1.rsp
12lab.exe: CMakeFiles/12lab.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\labs\C-Labs\12lab\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable 12lab.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\12lab.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/12lab.dir/build: 12lab.exe

.PHONY : CMakeFiles/12lab.dir/build

CMakeFiles/12lab.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\12lab.dir\cmake_clean.cmake
.PHONY : CMakeFiles/12lab.dir/clean

CMakeFiles/12lab.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\labs\C-Labs\12lab D:\labs\C-Labs\12lab D:\labs\C-Labs\12lab\cmake-build-debug D:\labs\C-Labs\12lab\cmake-build-debug D:\labs\C-Labs\12lab\cmake-build-debug\CMakeFiles\12lab.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/12lab.dir/depend

