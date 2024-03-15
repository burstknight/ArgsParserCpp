enable_testing()

add_executable(test_myArgsParser ./test_myArgsParser.cpp)
target_link_libraries(
	test_myArgsParser
	ArgsParserCpp
	gtest
	)

add_test(test_myArgsParser test_myArgsParser)
