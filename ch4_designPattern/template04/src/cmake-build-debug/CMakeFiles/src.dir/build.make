# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\redmk\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\203.7148.70\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\redmk\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\203.7148.70\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\object_oriented_c\object_oriented_c\ch4_designPattern\template04\src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\object_oriented_c\object_oriented_c\ch4_designPattern\template04\src\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/src.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/src.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/src.dir/flags.make

CMakeFiles/src.dir/file_reader.c.obj: CMakeFiles/src.dir/flags.make
CMakeFiles/src.dir/file_reader.c.obj: CMakeFiles/src.dir/includes_C.rsp
CMakeFiles/src.dir/file_reader.c.obj: ../file_reader.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\object_oriented_c\object_oriented_c\ch4_designPattern\template04\src\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/src.dir/file_reader.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\src.dir\file_reader.c.obj   -c E:\object_oriented_c\object_oriented_c\ch4_designPattern\template04\src\file_reader.c

CMakeFiles/src.dir/file_reader.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/src.dir/file_reader.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:\object_oriented_c\object_oriented_c\ch4_designPattern\template04\src\file_reader.c > CMakeFiles\src.dir\file_reader.c.i

CMakeFiles/src.dir/file_reader.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/src.dir/file_reader.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:\object_oriented_c\object_oriented_c\ch4_designPattern\template04\src\file_reader.c -o CMakeFiles\src.dir\file_reader.c.s

CMakeFiles/src.dir/range.c.obj: CMakeFiles/src.dir/flags.make
CMakeFiles/src.dir/range.c.obj: CMakeFiles/src.dir/includes_C.rsp
CMakeFiles/src.dir/range.c.obj: ../range.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\object_oriented_c\object_oriented_c\ch4_designPattern\template04\src\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/src.dir/range.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\src.dir\range.c.obj   -c E:\object_oriented_c\object_oriented_c\ch4_designPattern\template04\src\range.c

CMakeFiles/src.dir/range.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/src.dir/range.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:\object_oriented_c\object_oriented_c\ch4_designPattern\template04\src\range.c > CMakeFiles\src.dir\range.c.i

CMakeFiles/src.dir/range.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/src.dir/range.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:\object_oriented_c\object_oriented_c\ch4_designPattern\template04\src\range.c -o CMakeFiles\src.dir\range.c.s

CMakeFiles/src.dir/main.c.obj: CMakeFiles/src.dir/flags.make
CMakeFiles/src.dir/main.c.obj: CMakeFiles/src.dir/includes_C.rsp
CMakeFiles/src.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\object_oriented_c\object_oriented_c\ch4_designPattern\template04\src\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/src.dir/main.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\src.dir\main.c.obj   -c E:\object_oriented_c\object_oriented_c\ch4_designPattern\template04\src\main.c

CMakeFiles/src.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/src.dir/main.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:\object_oriented_c\object_oriented_c\ch4_designPattern\template04\src\main.c > CMakeFiles\src.dir\main.c.i

CMakeFiles/src.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/src.dir/main.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:\object_oriented_c\object_oriented_c\ch4_designPattern\template04\src\main.c -o CMakeFiles\src.dir\main.c.s

# Object files for target src
src_OBJECTS = \
"CMakeFiles/src.dir/file_reader.c.obj" \
"CMakeFiles/src.dir/range.c.obj" \
"CMakeFiles/src.dir/main.c.obj"

# External object files for target src
src_EXTERNAL_OBJECTS =

src.exe: CMakeFiles/src.dir/file_reader.c.obj
src.exe: CMakeFiles/src.dir/range.c.obj
src.exe: CMakeFiles/src.dir/main.c.obj
src.exe: CMakeFiles/src.dir/build.make
src.exe: CMakeFiles/src.dir/linklibs.rsp
src.exe: CMakeFiles/src.dir/objects1.rsp
src.exe: CMakeFiles/src.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\object_oriented_c\object_oriented_c\ch4_designPattern\template04\src\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable src.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\src.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/src.dir/build: src.exe

.PHONY : CMakeFiles/src.dir/build

CMakeFiles/src.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\src.dir\cmake_clean.cmake
.PHONY : CMakeFiles/src.dir/clean

CMakeFiles/src.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\object_oriented_c\object_oriented_c\ch4_designPattern\template04\src E:\object_oriented_c\object_oriented_c\ch4_designPattern\template04\src E:\object_oriented_c\object_oriented_c\ch4_designPattern\template04\src\cmake-build-debug E:\object_oriented_c\object_oriented_c\ch4_designPattern\template04\src\cmake-build-debug E:\object_oriented_c\object_oriented_c\ch4_designPattern\template04\src\cmake-build-debug\CMakeFiles\src.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/src.dir/depend

