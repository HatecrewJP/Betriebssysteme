# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\CLion 2024.1\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2024.1\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\JP\CLionProjects\Betriebssysteme

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\JP\CLionProjects\Betriebssysteme\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Betriebssysteme.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Betriebssysteme.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Betriebssysteme.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Betriebssysteme.dir/flags.make

CMakeFiles/Betriebssysteme.dir/wsort.c.obj: CMakeFiles/Betriebssysteme.dir/flags.make
CMakeFiles/Betriebssysteme.dir/wsort.c.obj: C:/Users/JP/CLionProjects/Betriebssysteme/wsort.c
CMakeFiles/Betriebssysteme.dir/wsort.c.obj: CMakeFiles/Betriebssysteme.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\JP\CLionProjects\Betriebssysteme\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Betriebssysteme.dir/wsort.c.obj"
	"D:\CLion 2024.1\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Betriebssysteme.dir/wsort.c.obj -MF CMakeFiles\Betriebssysteme.dir\wsort.c.obj.d -o CMakeFiles\Betriebssysteme.dir\wsort.c.obj -c C:\Users\JP\CLionProjects\Betriebssysteme\wsort.c

CMakeFiles/Betriebssysteme.dir/wsort.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Betriebssysteme.dir/wsort.c.i"
	"D:\CLion 2024.1\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\JP\CLionProjects\Betriebssysteme\wsort.c > CMakeFiles\Betriebssysteme.dir\wsort.c.i

CMakeFiles/Betriebssysteme.dir/wsort.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Betriebssysteme.dir/wsort.c.s"
	"D:\CLion 2024.1\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\JP\CLionProjects\Betriebssysteme\wsort.c -o CMakeFiles\Betriebssysteme.dir\wsort.c.s

# Object files for target Betriebssysteme
Betriebssysteme_OBJECTS = \
"CMakeFiles/Betriebssysteme.dir/wsort.c.obj"

# External object files for target Betriebssysteme
Betriebssysteme_EXTERNAL_OBJECTS =

Betriebssysteme.exe: CMakeFiles/Betriebssysteme.dir/wsort.c.obj
Betriebssysteme.exe: CMakeFiles/Betriebssysteme.dir/build.make
Betriebssysteme.exe: CMakeFiles/Betriebssysteme.dir/linkLibs.rsp
Betriebssysteme.exe: CMakeFiles/Betriebssysteme.dir/objects1.rsp
Betriebssysteme.exe: CMakeFiles/Betriebssysteme.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\JP\CLionProjects\Betriebssysteme\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Betriebssysteme.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Betriebssysteme.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Betriebssysteme.dir/build: Betriebssysteme.exe
.PHONY : CMakeFiles/Betriebssysteme.dir/build

CMakeFiles/Betriebssysteme.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Betriebssysteme.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Betriebssysteme.dir/clean

CMakeFiles/Betriebssysteme.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\JP\CLionProjects\Betriebssysteme C:\Users\JP\CLionProjects\Betriebssysteme C:\Users\JP\CLionProjects\Betriebssysteme\cmake-build-debug C:\Users\JP\CLionProjects\Betriebssysteme\cmake-build-debug C:\Users\JP\CLionProjects\Betriebssysteme\cmake-build-debug\CMakeFiles\Betriebssysteme.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Betriebssysteme.dir/depend

