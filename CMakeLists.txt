cmake_minimum_required(VERSION 3.5)

###########################################################
# Set the project name.
###########################################################
project(ArgsParserCpp)

###########################################################
# Require to use C++14 to build source code.
###########################################################
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

###########################################################
# Set the version for this project.
###########################################################
set(ArgsParserCpp_Version_Major 0)
set(ArgsParserCpp_Version_Minor 1)
set(ArgsParserCpp_Version_Patch 0)
set(ArgsParserCpp_Status "-dev")
set(
	ArgsParserCpp_Version
	"${ArgsParserCpp_Version_Major}.${ArgsParserCpp_Version_Minor}.${ArgsParserCpp_Version_Patch}${ArgsParserCpp_Status}"
	)

###########################################################
# Add build config to enable or disable for generating
# document using doxygen.
###########################################################
option(Enable_Generate_Document "Do you want to generate document using doxygen?" ON)
if(${Enable_Generate_Document})
	configure_file(
		${CMAKE_SOURCE_DIR}/doc/Doxyfile.in
		${CMAKE_SOURCE_DIR}/doc/Doxyfile
		@ONLY
		)

	find_package(Doxygen REQUIRED)
	add_custom_target("doc" COMMENT "Use doxygen to generate the document.")
	add_custom_command(
		TARGET "doc"
		COMMENT "Generating the document using doxygen."
		COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_SOURCE_DIR}/doc/Doxyfile
		WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/doc
		)
endif(${Enable_Generate_Document})

aux_source_directory(./src SOURCES)
add_library(ArgsParserCpp ${SOURCES})
target_include_directories(ArgsParserCpp
	PUBLIC
		$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/includes>
	)

###########################################################
# Add the build config to enable or disable in order to 
# test this project.
###########################################################
option(Do_Unit_Test "Do you want to do unit test?" ON)
if(${Do_Unit_Test})
	enable_testing()

	# Add macro for unit test.
	add_definitions(-DUnit_Test)

	# Clone googletest for unit test
	include(FetchContent)
	# For windows, this setting can prevent overriding this project's compiler/linker settings.
	set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
	FetchContent_Declare(
		googletest
		GIT_REPOSITORY https://github.com/google/googletest.git
		GIT_TAG v1.14.0
		)
	FetchContent_MakeAvailable(googletest)

	add_subdirectory(./tests)
endif(${Do_Unit_Test})

