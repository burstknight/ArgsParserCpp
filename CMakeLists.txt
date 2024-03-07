cmake_minimum_required(VERSION 3.5)

###########################################################
# Set the project name.
###########################################################
project(ArgsParserCpp)

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
