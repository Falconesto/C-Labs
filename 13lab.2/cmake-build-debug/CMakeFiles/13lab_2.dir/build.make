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
CMAKE_SOURCE_DIR = D:\labs\C-Labs\13lab.2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\labs\C-Labs\13lab.2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/13lab_2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/13lab_2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/13lab_2.dir/flags.make

CMakeFiles/13lab_2.dir/main.c.obj: CMakeFiles/13lab_2.dir/flags.make
CMakeFiles/13lab_2.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\labs\C-Labs\13lab.2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/13lab_2.dir/main.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\13lab_2.dir\main.c.obj   -c D:\labs\C-Labs\13lab.2\main.c

CMakeFiles/13lab_2.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/13lab_2.dir/main.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\labs\C-Labs\13lab.2\main.c > CMakeFiles\13lab_2.dir\main.c.i

CMakeFiles/13lab_2.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/13lab_2.dir/main.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\labs\C-Labs\13lab.2\main.c -o CMakeFiles\13lab_2.dir\main.c.s

CMakeFiles/13lab_2.dir/library.c.obj: CMakeFiles/13lab_2.dir/flags.make
CMakeFiles/13lab_2.dir/library.c.obj: ../library.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\labs\C-Labs\13lab.2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/13lab_2.dir/library.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\13lab_2.dir\library.c.obj   -c D:\labs\C-Labs\13lab.2\library.c

CMakeFiles/13lab_2.dir/library.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/13lab_2.dir/library.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\labs\C-Labs\13lab.2\library.c > CMakeFiles\13lab_2.dir\library.c.i

CMakeFiles/13lab_2.dir/library.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/13lab_2.dir/library.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\labs\C-Labs\13lab.2\library.c -o CMakeFiles\13lab_2.dir\library.c.s

# Object files for target 13lab_2
13lab_2_OBJECTS = \
"CMakeFiles/13lab_2.dir/main.c.obj" \
"CMakeFiles/13lab_2.dir/library.c.obj"

# External object files for target 13lab_2
13lab_2_EXTERNAL_OBJECTS =

13lab_2.exe: CMakeFiles/13lab_2.dir/main.c.obj
13lab_2.exe: CMakeFiles/13lab_2.dir/library.c.obj
13lab_2.exe: CMakeFiles/13lab_2.dir/build.make
13lab_2.exe: CMakeFiles/13lab_2.dir/linklibs.rsp
13lab_2.exe: CMakeFiles/13lab_2.dir/objects1.rsp
13lab_2.exe: CMakeFiles/13lab_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\labs\C-Labs\13lab.2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable 13lab_2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\13lab_2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/13lab_2.dir/build: 13lab_2.exe

.PHONY : CMakeFiles/13lab_2.dir/build

CMakeFiles/13lab_2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\13lab_2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/13lab_2.dir/clean

CMakeFiles/13lab_2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\labs\C-Labs\13lab.2 D:\labs\C-Labs\13lab.2 D:\labs\C-Labs\13lab.2\cmake-build-debug D:\labs\C-Labs\13lab.2\cmake-build-debug D:\labs\C-Labs\13lab.2\cmake-build-debug\CMakeFiles\13lab_2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/13lab_2.dir/depend

