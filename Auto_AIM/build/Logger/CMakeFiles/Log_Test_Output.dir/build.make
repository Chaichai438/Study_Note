# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /opt/cmake-3.31.0/bin/cmake

# The command to remove a file.
RM = /opt/cmake-3.31.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/chaichai/project/Study_Note/Auto_AIM

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chaichai/project/Study_Note/Auto_AIM/build

# Include any dependencies generated for this target.
include Logger/CMakeFiles/Log_Test_Output.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Logger/CMakeFiles/Log_Test_Output.dir/compiler_depend.make

# Include the progress variables for this target.
include Logger/CMakeFiles/Log_Test_Output.dir/progress.make

# Include the compile flags for this target's objects.
include Logger/CMakeFiles/Log_Test_Output.dir/flags.make

Logger/CMakeFiles/Log_Test_Output.dir/codegen:
.PHONY : Logger/CMakeFiles/Log_Test_Output.dir/codegen

Logger/CMakeFiles/Log_Test_Output.dir/test/Test_Output.cpp.o: Logger/CMakeFiles/Log_Test_Output.dir/flags.make
Logger/CMakeFiles/Log_Test_Output.dir/test/Test_Output.cpp.o: /home/chaichai/project/Study_Note/Auto_AIM/Logger/test/Test_Output.cpp
Logger/CMakeFiles/Log_Test_Output.dir/test/Test_Output.cpp.o: Logger/CMakeFiles/Log_Test_Output.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/chaichai/project/Study_Note/Auto_AIM/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Logger/CMakeFiles/Log_Test_Output.dir/test/Test_Output.cpp.o"
	cd /home/chaichai/project/Study_Note/Auto_AIM/build/Logger && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Logger/CMakeFiles/Log_Test_Output.dir/test/Test_Output.cpp.o -MF CMakeFiles/Log_Test_Output.dir/test/Test_Output.cpp.o.d -o CMakeFiles/Log_Test_Output.dir/test/Test_Output.cpp.o -c /home/chaichai/project/Study_Note/Auto_AIM/Logger/test/Test_Output.cpp

Logger/CMakeFiles/Log_Test_Output.dir/test/Test_Output.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Log_Test_Output.dir/test/Test_Output.cpp.i"
	cd /home/chaichai/project/Study_Note/Auto_AIM/build/Logger && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chaichai/project/Study_Note/Auto_AIM/Logger/test/Test_Output.cpp > CMakeFiles/Log_Test_Output.dir/test/Test_Output.cpp.i

Logger/CMakeFiles/Log_Test_Output.dir/test/Test_Output.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Log_Test_Output.dir/test/Test_Output.cpp.s"
	cd /home/chaichai/project/Study_Note/Auto_AIM/build/Logger && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chaichai/project/Study_Note/Auto_AIM/Logger/test/Test_Output.cpp -o CMakeFiles/Log_Test_Output.dir/test/Test_Output.cpp.s

# Object files for target Log_Test_Output
Log_Test_Output_OBJECTS = \
"CMakeFiles/Log_Test_Output.dir/test/Test_Output.cpp.o"

# External object files for target Log_Test_Output
Log_Test_Output_EXTERNAL_OBJECTS =

bin/Log_Test_Output: Logger/CMakeFiles/Log_Test_Output.dir/test/Test_Output.cpp.o
bin/Log_Test_Output: Logger/CMakeFiles/Log_Test_Output.dir/build.make
bin/Log_Test_Output: bin/libUtilsLogger.a
bin/Log_Test_Output: Logger/CMakeFiles/Log_Test_Output.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/chaichai/project/Study_Note/Auto_AIM/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/Log_Test_Output"
	cd /home/chaichai/project/Study_Note/Auto_AIM/build/Logger && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Log_Test_Output.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Logger/CMakeFiles/Log_Test_Output.dir/build: bin/Log_Test_Output
.PHONY : Logger/CMakeFiles/Log_Test_Output.dir/build

Logger/CMakeFiles/Log_Test_Output.dir/clean:
	cd /home/chaichai/project/Study_Note/Auto_AIM/build/Logger && $(CMAKE_COMMAND) -P CMakeFiles/Log_Test_Output.dir/cmake_clean.cmake
.PHONY : Logger/CMakeFiles/Log_Test_Output.dir/clean

Logger/CMakeFiles/Log_Test_Output.dir/depend:
	cd /home/chaichai/project/Study_Note/Auto_AIM/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chaichai/project/Study_Note/Auto_AIM /home/chaichai/project/Study_Note/Auto_AIM/Logger /home/chaichai/project/Study_Note/Auto_AIM/build /home/chaichai/project/Study_Note/Auto_AIM/build/Logger /home/chaichai/project/Study_Note/Auto_AIM/build/Logger/CMakeFiles/Log_Test_Output.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : Logger/CMakeFiles/Log_Test_Output.dir/depend

