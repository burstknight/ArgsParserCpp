enable_testing()

add_executable(
	test_myArgsParser_addArguments
	./test_myArgsParser_addArguments.cpp
	)
target_link_libraries(
	test_myArgsParser_addArguments
	ArgsParserCpp
	gtest
	)

add_test(
	test_myArgsParser_addArguments test_myArgsParser_addArguments
	)

add_executable(test_myArgsParser_parseArgs ./test_myArgsParser_parseArgs.cpp)
target_link_libraries(
	test_myArgsParser_parseArgs
	gtest
	ArgsParserCpp
	)
add_test(
	test_myArgsParser_parseArgs test_myArgsParser_parseArgs
	)
