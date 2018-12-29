# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.12.4/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.12.4/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Pablo/git/ATCSim

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Pablo/git/ATCSim/build_MacOS

# Utility rule file for ATCSim_cpplint.

# Include the progress variables for this target.
include CMakeFiles/ATCSim_cpplint.dir/progress.make

CMakeFiles/ATCSim_cpplint: ../src/lib/Common.h
CMakeFiles/ATCSim_cpplint: ../src/lib/Singleton.h
CMakeFiles/ATCSim_cpplint: ../src/simulator/AirController.cpp
CMakeFiles/ATCSim_cpplint: ../src/simulator/AirController.h
CMakeFiles/ATCSim_cpplint: ../src/simulator/Airport.cpp
CMakeFiles/ATCSim_cpplint: ../src/simulator/Airport.h
CMakeFiles/ATCSim_cpplint: ../src/simulator/Flight.cpp
CMakeFiles/ATCSim_cpplint: ../src/simulator/Flight.h
CMakeFiles/ATCSim_cpplint: ../src/simulator/IceComms.cpp
CMakeFiles/ATCSim_cpplint: ../src/simulator/IceComms.h
CMakeFiles/ATCSim_cpplint: ../src/simulator/Position.cpp
CMakeFiles/ATCSim_cpplint: ../src/simulator/Position.h
CMakeFiles/ATCSim_cpplint: ../src/simulator/Storm.cpp
CMakeFiles/ATCSim_cpplint: ../src/simulator/Storm.h
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/Pablo/git/ATCSim/build_MacOS/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Linting ATCSim_cpplint"
	/usr/local/Cellar/cmake/3.12.4/bin/cmake -E chdir /Users/Pablo/git/ATCSim /usr/bin/python /Users/Pablo/git/ATCSim/cmake/cpplint.py --filter=-build/include,-readability/streams,-runtime/threadsafe_fn, --counting=detailed --extensions=cpp,hpp,h --linelength=250 src/lib/Common.h src/lib/Singleton.h src/simulator/AirController.cpp src/simulator/AirController.h src/simulator/Airport.cpp src/simulator/Airport.h src/simulator/Flight.cpp src/simulator/Flight.h src/simulator/IceComms.cpp src/simulator/IceComms.h src/simulator/Position.cpp src/simulator/Position.h src/simulator/Storm.cpp src/simulator/Storm.h

ATCSim_cpplint: CMakeFiles/ATCSim_cpplint
ATCSim_cpplint: CMakeFiles/ATCSim_cpplint.dir/build.make

.PHONY : ATCSim_cpplint

# Rule to build all files generated by this target.
CMakeFiles/ATCSim_cpplint.dir/build: ATCSim_cpplint

.PHONY : CMakeFiles/ATCSim_cpplint.dir/build

CMakeFiles/ATCSim_cpplint.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ATCSim_cpplint.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ATCSim_cpplint.dir/clean

CMakeFiles/ATCSim_cpplint.dir/depend:
	cd /Users/Pablo/git/ATCSim/build_MacOS && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Pablo/git/ATCSim /Users/Pablo/git/ATCSim /Users/Pablo/git/ATCSim/build_MacOS /Users/Pablo/git/ATCSim/build_MacOS /Users/Pablo/git/ATCSim/build_MacOS/CMakeFiles/ATCSim_cpplint.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ATCSim_cpplint.dir/depend

