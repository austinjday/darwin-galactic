# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = "C:\Program Files (x86)\JetBrains\CLion 2017.1\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\JetBrains\CLion 2017.1\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\austi\dev\DarwinGalactic

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\austi\dev\DarwinGalactic\cmake-build-debug

# Include any dependencies generated for this target.
include test/CMakeFiles/runUnitTests.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/runUnitTests.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/runUnitTests.dir/flags.make

test/CMakeFiles/runUnitTests.dir/main.cpp.obj: test/CMakeFiles/runUnitTests.dir/flags.make
test/CMakeFiles/runUnitTests.dir/main.cpp.obj: test/CMakeFiles/runUnitTests.dir/includes_CXX.rsp
test/CMakeFiles/runUnitTests.dir/main.cpp.obj: ../test/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\austi\dev\DarwinGalactic\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/runUnitTests.dir/main.cpp.obj"
	cd /d C:\Users\austi\dev\DarwinGalactic\cmake-build-debug\test && C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\runUnitTests.dir\main.cpp.obj -c C:\Users\austi\dev\DarwinGalactic\test\main.cpp

test/CMakeFiles/runUnitTests.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runUnitTests.dir/main.cpp.i"
	cd /d C:\Users\austi\dev\DarwinGalactic\cmake-build-debug\test && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\austi\dev\DarwinGalactic\test\main.cpp > CMakeFiles\runUnitTests.dir\main.cpp.i

test/CMakeFiles/runUnitTests.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runUnitTests.dir/main.cpp.s"
	cd /d C:\Users\austi\dev\DarwinGalactic\cmake-build-debug\test && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\austi\dev\DarwinGalactic\test\main.cpp -o CMakeFiles\runUnitTests.dir\main.cpp.s

test/CMakeFiles/runUnitTests.dir/main.cpp.obj.requires:

.PHONY : test/CMakeFiles/runUnitTests.dir/main.cpp.obj.requires

test/CMakeFiles/runUnitTests.dir/main.cpp.obj.provides: test/CMakeFiles/runUnitTests.dir/main.cpp.obj.requires
	$(MAKE) -f test\CMakeFiles\runUnitTests.dir\build.make test/CMakeFiles/runUnitTests.dir/main.cpp.obj.provides.build
.PHONY : test/CMakeFiles/runUnitTests.dir/main.cpp.obj.provides

test/CMakeFiles/runUnitTests.dir/main.cpp.obj.provides.build: test/CMakeFiles/runUnitTests.dir/main.cpp.obj


test/CMakeFiles/runUnitTests.dir/tests/common/PointTest.cpp.obj: test/CMakeFiles/runUnitTests.dir/flags.make
test/CMakeFiles/runUnitTests.dir/tests/common/PointTest.cpp.obj: test/CMakeFiles/runUnitTests.dir/includes_CXX.rsp
test/CMakeFiles/runUnitTests.dir/tests/common/PointTest.cpp.obj: ../test/tests/common/PointTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\austi\dev\DarwinGalactic\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/CMakeFiles/runUnitTests.dir/tests/common/PointTest.cpp.obj"
	cd /d C:\Users\austi\dev\DarwinGalactic\cmake-build-debug\test && C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\runUnitTests.dir\tests\common\PointTest.cpp.obj -c C:\Users\austi\dev\DarwinGalactic\test\tests\common\PointTest.cpp

test/CMakeFiles/runUnitTests.dir/tests/common/PointTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runUnitTests.dir/tests/common/PointTest.cpp.i"
	cd /d C:\Users\austi\dev\DarwinGalactic\cmake-build-debug\test && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\austi\dev\DarwinGalactic\test\tests\common\PointTest.cpp > CMakeFiles\runUnitTests.dir\tests\common\PointTest.cpp.i

test/CMakeFiles/runUnitTests.dir/tests/common/PointTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runUnitTests.dir/tests/common/PointTest.cpp.s"
	cd /d C:\Users\austi\dev\DarwinGalactic\cmake-build-debug\test && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\austi\dev\DarwinGalactic\test\tests\common\PointTest.cpp -o CMakeFiles\runUnitTests.dir\tests\common\PointTest.cpp.s

test/CMakeFiles/runUnitTests.dir/tests/common/PointTest.cpp.obj.requires:

.PHONY : test/CMakeFiles/runUnitTests.dir/tests/common/PointTest.cpp.obj.requires

test/CMakeFiles/runUnitTests.dir/tests/common/PointTest.cpp.obj.provides: test/CMakeFiles/runUnitTests.dir/tests/common/PointTest.cpp.obj.requires
	$(MAKE) -f test\CMakeFiles\runUnitTests.dir\build.make test/CMakeFiles/runUnitTests.dir/tests/common/PointTest.cpp.obj.provides.build
.PHONY : test/CMakeFiles/runUnitTests.dir/tests/common/PointTest.cpp.obj.provides

test/CMakeFiles/runUnitTests.dir/tests/common/PointTest.cpp.obj.provides.build: test/CMakeFiles/runUnitTests.dir/tests/common/PointTest.cpp.obj


test/CMakeFiles/runUnitTests.dir/tests/environment/AsteroidTest.cpp.obj: test/CMakeFiles/runUnitTests.dir/flags.make
test/CMakeFiles/runUnitTests.dir/tests/environment/AsteroidTest.cpp.obj: test/CMakeFiles/runUnitTests.dir/includes_CXX.rsp
test/CMakeFiles/runUnitTests.dir/tests/environment/AsteroidTest.cpp.obj: ../test/tests/environment/AsteroidTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\austi\dev\DarwinGalactic\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object test/CMakeFiles/runUnitTests.dir/tests/environment/AsteroidTest.cpp.obj"
	cd /d C:\Users\austi\dev\DarwinGalactic\cmake-build-debug\test && C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\runUnitTests.dir\tests\environment\AsteroidTest.cpp.obj -c C:\Users\austi\dev\DarwinGalactic\test\tests\environment\AsteroidTest.cpp

test/CMakeFiles/runUnitTests.dir/tests/environment/AsteroidTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runUnitTests.dir/tests/environment/AsteroidTest.cpp.i"
	cd /d C:\Users\austi\dev\DarwinGalactic\cmake-build-debug\test && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\austi\dev\DarwinGalactic\test\tests\environment\AsteroidTest.cpp > CMakeFiles\runUnitTests.dir\tests\environment\AsteroidTest.cpp.i

test/CMakeFiles/runUnitTests.dir/tests/environment/AsteroidTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runUnitTests.dir/tests/environment/AsteroidTest.cpp.s"
	cd /d C:\Users\austi\dev\DarwinGalactic\cmake-build-debug\test && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\austi\dev\DarwinGalactic\test\tests\environment\AsteroidTest.cpp -o CMakeFiles\runUnitTests.dir\tests\environment\AsteroidTest.cpp.s

test/CMakeFiles/runUnitTests.dir/tests/environment/AsteroidTest.cpp.obj.requires:

.PHONY : test/CMakeFiles/runUnitTests.dir/tests/environment/AsteroidTest.cpp.obj.requires

test/CMakeFiles/runUnitTests.dir/tests/environment/AsteroidTest.cpp.obj.provides: test/CMakeFiles/runUnitTests.dir/tests/environment/AsteroidTest.cpp.obj.requires
	$(MAKE) -f test\CMakeFiles\runUnitTests.dir\build.make test/CMakeFiles/runUnitTests.dir/tests/environment/AsteroidTest.cpp.obj.provides.build
.PHONY : test/CMakeFiles/runUnitTests.dir/tests/environment/AsteroidTest.cpp.obj.provides

test/CMakeFiles/runUnitTests.dir/tests/environment/AsteroidTest.cpp.obj.provides.build: test/CMakeFiles/runUnitTests.dir/tests/environment/AsteroidTest.cpp.obj


test/CMakeFiles/runUnitTests.dir/tests/environment/EnvironmentTest.cpp.obj: test/CMakeFiles/runUnitTests.dir/flags.make
test/CMakeFiles/runUnitTests.dir/tests/environment/EnvironmentTest.cpp.obj: test/CMakeFiles/runUnitTests.dir/includes_CXX.rsp
test/CMakeFiles/runUnitTests.dir/tests/environment/EnvironmentTest.cpp.obj: ../test/tests/environment/EnvironmentTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\austi\dev\DarwinGalactic\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object test/CMakeFiles/runUnitTests.dir/tests/environment/EnvironmentTest.cpp.obj"
	cd /d C:\Users\austi\dev\DarwinGalactic\cmake-build-debug\test && C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\runUnitTests.dir\tests\environment\EnvironmentTest.cpp.obj -c C:\Users\austi\dev\DarwinGalactic\test\tests\environment\EnvironmentTest.cpp

test/CMakeFiles/runUnitTests.dir/tests/environment/EnvironmentTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runUnitTests.dir/tests/environment/EnvironmentTest.cpp.i"
	cd /d C:\Users\austi\dev\DarwinGalactic\cmake-build-debug\test && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\austi\dev\DarwinGalactic\test\tests\environment\EnvironmentTest.cpp > CMakeFiles\runUnitTests.dir\tests\environment\EnvironmentTest.cpp.i

test/CMakeFiles/runUnitTests.dir/tests/environment/EnvironmentTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runUnitTests.dir/tests/environment/EnvironmentTest.cpp.s"
	cd /d C:\Users\austi\dev\DarwinGalactic\cmake-build-debug\test && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\austi\dev\DarwinGalactic\test\tests\environment\EnvironmentTest.cpp -o CMakeFiles\runUnitTests.dir\tests\environment\EnvironmentTest.cpp.s

test/CMakeFiles/runUnitTests.dir/tests/environment/EnvironmentTest.cpp.obj.requires:

.PHONY : test/CMakeFiles/runUnitTests.dir/tests/environment/EnvironmentTest.cpp.obj.requires

test/CMakeFiles/runUnitTests.dir/tests/environment/EnvironmentTest.cpp.obj.provides: test/CMakeFiles/runUnitTests.dir/tests/environment/EnvironmentTest.cpp.obj.requires
	$(MAKE) -f test\CMakeFiles\runUnitTests.dir\build.make test/CMakeFiles/runUnitTests.dir/tests/environment/EnvironmentTest.cpp.obj.provides.build
.PHONY : test/CMakeFiles/runUnitTests.dir/tests/environment/EnvironmentTest.cpp.obj.provides

test/CMakeFiles/runUnitTests.dir/tests/environment/EnvironmentTest.cpp.obj.provides.build: test/CMakeFiles/runUnitTests.dir/tests/environment/EnvironmentTest.cpp.obj


test/CMakeFiles/runUnitTests.dir/tests/environment/LaserShotTest.cpp.obj: test/CMakeFiles/runUnitTests.dir/flags.make
test/CMakeFiles/runUnitTests.dir/tests/environment/LaserShotTest.cpp.obj: test/CMakeFiles/runUnitTests.dir/includes_CXX.rsp
test/CMakeFiles/runUnitTests.dir/tests/environment/LaserShotTest.cpp.obj: ../test/tests/environment/LaserShotTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\austi\dev\DarwinGalactic\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object test/CMakeFiles/runUnitTests.dir/tests/environment/LaserShotTest.cpp.obj"
	cd /d C:\Users\austi\dev\DarwinGalactic\cmake-build-debug\test && C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\runUnitTests.dir\tests\environment\LaserShotTest.cpp.obj -c C:\Users\austi\dev\DarwinGalactic\test\tests\environment\LaserShotTest.cpp

test/CMakeFiles/runUnitTests.dir/tests/environment/LaserShotTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runUnitTests.dir/tests/environment/LaserShotTest.cpp.i"
	cd /d C:\Users\austi\dev\DarwinGalactic\cmake-build-debug\test && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\austi\dev\DarwinGalactic\test\tests\environment\LaserShotTest.cpp > CMakeFiles\runUnitTests.dir\tests\environment\LaserShotTest.cpp.i

test/CMakeFiles/runUnitTests.dir/tests/environment/LaserShotTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runUnitTests.dir/tests/environment/LaserShotTest.cpp.s"
	cd /d C:\Users\austi\dev\DarwinGalactic\cmake-build-debug\test && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\austi\dev\DarwinGalactic\test\tests\environment\LaserShotTest.cpp -o CMakeFiles\runUnitTests.dir\tests\environment\LaserShotTest.cpp.s

test/CMakeFiles/runUnitTests.dir/tests/environment/LaserShotTest.cpp.obj.requires:

.PHONY : test/CMakeFiles/runUnitTests.dir/tests/environment/LaserShotTest.cpp.obj.requires

test/CMakeFiles/runUnitTests.dir/tests/environment/LaserShotTest.cpp.obj.provides: test/CMakeFiles/runUnitTests.dir/tests/environment/LaserShotTest.cpp.obj.requires
	$(MAKE) -f test\CMakeFiles\runUnitTests.dir\build.make test/CMakeFiles/runUnitTests.dir/tests/environment/LaserShotTest.cpp.obj.provides.build
.PHONY : test/CMakeFiles/runUnitTests.dir/tests/environment/LaserShotTest.cpp.obj.provides

test/CMakeFiles/runUnitTests.dir/tests/environment/LaserShotTest.cpp.obj.provides.build: test/CMakeFiles/runUnitTests.dir/tests/environment/LaserShotTest.cpp.obj


test/CMakeFiles/runUnitTests.dir/tests/ship/ShipTest.cpp.obj: test/CMakeFiles/runUnitTests.dir/flags.make
test/CMakeFiles/runUnitTests.dir/tests/ship/ShipTest.cpp.obj: test/CMakeFiles/runUnitTests.dir/includes_CXX.rsp
test/CMakeFiles/runUnitTests.dir/tests/ship/ShipTest.cpp.obj: ../test/tests/ship/ShipTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\austi\dev\DarwinGalactic\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object test/CMakeFiles/runUnitTests.dir/tests/ship/ShipTest.cpp.obj"
	cd /d C:\Users\austi\dev\DarwinGalactic\cmake-build-debug\test && C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\runUnitTests.dir\tests\ship\ShipTest.cpp.obj -c C:\Users\austi\dev\DarwinGalactic\test\tests\ship\ShipTest.cpp

test/CMakeFiles/runUnitTests.dir/tests/ship/ShipTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runUnitTests.dir/tests/ship/ShipTest.cpp.i"
	cd /d C:\Users\austi\dev\DarwinGalactic\cmake-build-debug\test && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\austi\dev\DarwinGalactic\test\tests\ship\ShipTest.cpp > CMakeFiles\runUnitTests.dir\tests\ship\ShipTest.cpp.i

test/CMakeFiles/runUnitTests.dir/tests/ship/ShipTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runUnitTests.dir/tests/ship/ShipTest.cpp.s"
	cd /d C:\Users\austi\dev\DarwinGalactic\cmake-build-debug\test && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\austi\dev\DarwinGalactic\test\tests\ship\ShipTest.cpp -o CMakeFiles\runUnitTests.dir\tests\ship\ShipTest.cpp.s

test/CMakeFiles/runUnitTests.dir/tests/ship/ShipTest.cpp.obj.requires:

.PHONY : test/CMakeFiles/runUnitTests.dir/tests/ship/ShipTest.cpp.obj.requires

test/CMakeFiles/runUnitTests.dir/tests/ship/ShipTest.cpp.obj.provides: test/CMakeFiles/runUnitTests.dir/tests/ship/ShipTest.cpp.obj.requires
	$(MAKE) -f test\CMakeFiles\runUnitTests.dir\build.make test/CMakeFiles/runUnitTests.dir/tests/ship/ShipTest.cpp.obj.provides.build
.PHONY : test/CMakeFiles/runUnitTests.dir/tests/ship/ShipTest.cpp.obj.provides

test/CMakeFiles/runUnitTests.dir/tests/ship/ShipTest.cpp.obj.provides.build: test/CMakeFiles/runUnitTests.dir/tests/ship/ShipTest.cpp.obj


test/CMakeFiles/runUnitTests.dir/tests/ship/equipment/LaserTest.cpp.obj: test/CMakeFiles/runUnitTests.dir/flags.make
test/CMakeFiles/runUnitTests.dir/tests/ship/equipment/LaserTest.cpp.obj: test/CMakeFiles/runUnitTests.dir/includes_CXX.rsp
test/CMakeFiles/runUnitTests.dir/tests/ship/equipment/LaserTest.cpp.obj: ../test/tests/ship/equipment/LaserTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\austi\dev\DarwinGalactic\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object test/CMakeFiles/runUnitTests.dir/tests/ship/equipment/LaserTest.cpp.obj"
	cd /d C:\Users\austi\dev\DarwinGalactic\cmake-build-debug\test && C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\runUnitTests.dir\tests\ship\equipment\LaserTest.cpp.obj -c C:\Users\austi\dev\DarwinGalactic\test\tests\ship\equipment\LaserTest.cpp

test/CMakeFiles/runUnitTests.dir/tests/ship/equipment/LaserTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runUnitTests.dir/tests/ship/equipment/LaserTest.cpp.i"
	cd /d C:\Users\austi\dev\DarwinGalactic\cmake-build-debug\test && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\austi\dev\DarwinGalactic\test\tests\ship\equipment\LaserTest.cpp > CMakeFiles\runUnitTests.dir\tests\ship\equipment\LaserTest.cpp.i

test/CMakeFiles/runUnitTests.dir/tests/ship/equipment/LaserTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runUnitTests.dir/tests/ship/equipment/LaserTest.cpp.s"
	cd /d C:\Users\austi\dev\DarwinGalactic\cmake-build-debug\test && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\austi\dev\DarwinGalactic\test\tests\ship\equipment\LaserTest.cpp -o CMakeFiles\runUnitTests.dir\tests\ship\equipment\LaserTest.cpp.s

test/CMakeFiles/runUnitTests.dir/tests/ship/equipment/LaserTest.cpp.obj.requires:

.PHONY : test/CMakeFiles/runUnitTests.dir/tests/ship/equipment/LaserTest.cpp.obj.requires

test/CMakeFiles/runUnitTests.dir/tests/ship/equipment/LaserTest.cpp.obj.provides: test/CMakeFiles/runUnitTests.dir/tests/ship/equipment/LaserTest.cpp.obj.requires
	$(MAKE) -f test\CMakeFiles\runUnitTests.dir\build.make test/CMakeFiles/runUnitTests.dir/tests/ship/equipment/LaserTest.cpp.obj.provides.build
.PHONY : test/CMakeFiles/runUnitTests.dir/tests/ship/equipment/LaserTest.cpp.obj.provides

test/CMakeFiles/runUnitTests.dir/tests/ship/equipment/LaserTest.cpp.obj.provides.build: test/CMakeFiles/runUnitTests.dir/tests/ship/equipment/LaserTest.cpp.obj


test/CMakeFiles/runUnitTests.dir/tests/utility/IntegerMathTest.cpp.obj: test/CMakeFiles/runUnitTests.dir/flags.make
test/CMakeFiles/runUnitTests.dir/tests/utility/IntegerMathTest.cpp.obj: test/CMakeFiles/runUnitTests.dir/includes_CXX.rsp
test/CMakeFiles/runUnitTests.dir/tests/utility/IntegerMathTest.cpp.obj: ../test/tests/utility/IntegerMathTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\austi\dev\DarwinGalactic\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object test/CMakeFiles/runUnitTests.dir/tests/utility/IntegerMathTest.cpp.obj"
	cd /d C:\Users\austi\dev\DarwinGalactic\cmake-build-debug\test && C:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\runUnitTests.dir\tests\utility\IntegerMathTest.cpp.obj -c C:\Users\austi\dev\DarwinGalactic\test\tests\utility\IntegerMathTest.cpp

test/CMakeFiles/runUnitTests.dir/tests/utility/IntegerMathTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runUnitTests.dir/tests/utility/IntegerMathTest.cpp.i"
	cd /d C:\Users\austi\dev\DarwinGalactic\cmake-build-debug\test && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\austi\dev\DarwinGalactic\test\tests\utility\IntegerMathTest.cpp > CMakeFiles\runUnitTests.dir\tests\utility\IntegerMathTest.cpp.i

test/CMakeFiles/runUnitTests.dir/tests/utility/IntegerMathTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runUnitTests.dir/tests/utility/IntegerMathTest.cpp.s"
	cd /d C:\Users\austi\dev\DarwinGalactic\cmake-build-debug\test && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\austi\dev\DarwinGalactic\test\tests\utility\IntegerMathTest.cpp -o CMakeFiles\runUnitTests.dir\tests\utility\IntegerMathTest.cpp.s

test/CMakeFiles/runUnitTests.dir/tests/utility/IntegerMathTest.cpp.obj.requires:

.PHONY : test/CMakeFiles/runUnitTests.dir/tests/utility/IntegerMathTest.cpp.obj.requires

test/CMakeFiles/runUnitTests.dir/tests/utility/IntegerMathTest.cpp.obj.provides: test/CMakeFiles/runUnitTests.dir/tests/utility/IntegerMathTest.cpp.obj.requires
	$(MAKE) -f test\CMakeFiles\runUnitTests.dir\build.make test/CMakeFiles/runUnitTests.dir/tests/utility/IntegerMathTest.cpp.obj.provides.build
.PHONY : test/CMakeFiles/runUnitTests.dir/tests/utility/IntegerMathTest.cpp.obj.provides

test/CMakeFiles/runUnitTests.dir/tests/utility/IntegerMathTest.cpp.obj.provides.build: test/CMakeFiles/runUnitTests.dir/tests/utility/IntegerMathTest.cpp.obj


# Object files for target runUnitTests
runUnitTests_OBJECTS = \
"CMakeFiles/runUnitTests.dir/main.cpp.obj" \
"CMakeFiles/runUnitTests.dir/tests/common/PointTest.cpp.obj" \
"CMakeFiles/runUnitTests.dir/tests/environment/AsteroidTest.cpp.obj" \
"CMakeFiles/runUnitTests.dir/tests/environment/EnvironmentTest.cpp.obj" \
"CMakeFiles/runUnitTests.dir/tests/environment/LaserShotTest.cpp.obj" \
"CMakeFiles/runUnitTests.dir/tests/ship/ShipTest.cpp.obj" \
"CMakeFiles/runUnitTests.dir/tests/ship/equipment/LaserTest.cpp.obj" \
"CMakeFiles/runUnitTests.dir/tests/utility/IntegerMathTest.cpp.obj"

# External object files for target runUnitTests
runUnitTests_EXTERNAL_OBJECTS =

test/runUnitTests.exe: test/CMakeFiles/runUnitTests.dir/main.cpp.obj
test/runUnitTests.exe: test/CMakeFiles/runUnitTests.dir/tests/common/PointTest.cpp.obj
test/runUnitTests.exe: test/CMakeFiles/runUnitTests.dir/tests/environment/AsteroidTest.cpp.obj
test/runUnitTests.exe: test/CMakeFiles/runUnitTests.dir/tests/environment/EnvironmentTest.cpp.obj
test/runUnitTests.exe: test/CMakeFiles/runUnitTests.dir/tests/environment/LaserShotTest.cpp.obj
test/runUnitTests.exe: test/CMakeFiles/runUnitTests.dir/tests/ship/ShipTest.cpp.obj
test/runUnitTests.exe: test/CMakeFiles/runUnitTests.dir/tests/ship/equipment/LaserTest.cpp.obj
test/runUnitTests.exe: test/CMakeFiles/runUnitTests.dir/tests/utility/IntegerMathTest.cpp.obj
test/runUnitTests.exe: test/CMakeFiles/runUnitTests.dir/build.make
test/runUnitTests.exe: test/lib/googletest-master/googlemock/gtest/libgtest.a
test/runUnitTests.exe: test/lib/googletest-master/googlemock/gtest/libgtest_main.a
test/runUnitTests.exe: src/libcore.a
test/runUnitTests.exe: test/lib/googletest-master/googlemock/gtest/libgtest.a
test/runUnitTests.exe: test/CMakeFiles/runUnitTests.dir/linklibs.rsp
test/runUnitTests.exe: test/CMakeFiles/runUnitTests.dir/objects1.rsp
test/runUnitTests.exe: test/CMakeFiles/runUnitTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\austi\dev\DarwinGalactic\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable runUnitTests.exe"
	cd /d C:\Users\austi\dev\DarwinGalactic\cmake-build-debug\test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\runUnitTests.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/runUnitTests.dir/build: test/runUnitTests.exe

.PHONY : test/CMakeFiles/runUnitTests.dir/build

test/CMakeFiles/runUnitTests.dir/requires: test/CMakeFiles/runUnitTests.dir/main.cpp.obj.requires
test/CMakeFiles/runUnitTests.dir/requires: test/CMakeFiles/runUnitTests.dir/tests/common/PointTest.cpp.obj.requires
test/CMakeFiles/runUnitTests.dir/requires: test/CMakeFiles/runUnitTests.dir/tests/environment/AsteroidTest.cpp.obj.requires
test/CMakeFiles/runUnitTests.dir/requires: test/CMakeFiles/runUnitTests.dir/tests/environment/EnvironmentTest.cpp.obj.requires
test/CMakeFiles/runUnitTests.dir/requires: test/CMakeFiles/runUnitTests.dir/tests/environment/LaserShotTest.cpp.obj.requires
test/CMakeFiles/runUnitTests.dir/requires: test/CMakeFiles/runUnitTests.dir/tests/ship/ShipTest.cpp.obj.requires
test/CMakeFiles/runUnitTests.dir/requires: test/CMakeFiles/runUnitTests.dir/tests/ship/equipment/LaserTest.cpp.obj.requires
test/CMakeFiles/runUnitTests.dir/requires: test/CMakeFiles/runUnitTests.dir/tests/utility/IntegerMathTest.cpp.obj.requires

.PHONY : test/CMakeFiles/runUnitTests.dir/requires

test/CMakeFiles/runUnitTests.dir/clean:
	cd /d C:\Users\austi\dev\DarwinGalactic\cmake-build-debug\test && $(CMAKE_COMMAND) -P CMakeFiles\runUnitTests.dir\cmake_clean.cmake
.PHONY : test/CMakeFiles/runUnitTests.dir/clean

test/CMakeFiles/runUnitTests.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\austi\dev\DarwinGalactic C:\Users\austi\dev\DarwinGalactic\test C:\Users\austi\dev\DarwinGalactic\cmake-build-debug C:\Users\austi\dev\DarwinGalactic\cmake-build-debug\test C:\Users\austi\dev\DarwinGalactic\cmake-build-debug\test\CMakeFiles\runUnitTests.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/runUnitTests.dir/depend
