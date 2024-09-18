#include "ArgsParserCpp/myArgsParser.h"
#include "gtest/gtest.h"
#include <cstdio>
#include <cstdlib>
#include <memory>

#define STRING_SIZE 4096

using namespace std;
using namespace ArgsParserCpp;

TEST(TestParseArgs, PositionArgsFail) {
	shared_ptr<myArgsParser> poParser(new myArgsParser());

	EXPECT_NO_THROW(poParser->addPositionArgument("pos_arg1", "The first position argument", true));
	EXPECT_NO_THROW(poParser->addPositionArgument("pos_arg2", "The second position argument", true));

	char** ppcArgv = (char**)malloc(sizeof(char*) * 2);
	for (int i = 0; i < 2; i++) {
		ppcArgv[i] = nullptr;
	} // End of for-loop

	ppcArgv[0] = (char*)malloc(sizeof(char) * STRING_SIZE);
	snprintf(ppcArgv[0], STRING_SIZE, "./program");
	EXPECT_ANY_THROW(poParser->parseArgs(1, ppcArgv));

	ppcArgv[1] = (char*)malloc(sizeof(char) * STRING_SIZE);
	snprintf(ppcArgv[1], STRING_SIZE, "pos_arg01");
	EXPECT_ANY_THROW(poParser->parseArgs(2, ppcArgv));

	for (int i = 0; i < 2; i++) {
		if (nullptr == ppcArgv[i]) {
			continue;
		} // End of if-condition

		free(ppcArgv[i]);
		ppcArgv[i] = nullptr;
	} // End of for-loop
	free(ppcArgv);
	ppcArgv = nullptr;
} // End of TestParseArgs::PositionArgsFail

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
} // End of main
