cmake_minimum_required(VERSION 3.5)

project(ArgsParserCpp)

aux_source_directory(./src SOURCES)
add_library(ArgsParserCpp ${SOURCES})
