#include <gtest/gtest.h>
#include "../includes/myArgsParser.h"

using namespace std;
using namespace ArgsParserCpp;

TEST(myArgsParserTest, AddPositionArgument){
	myArgsParser* poPaser = new myArgsParser();

	EXPECT_EQ(poPaser->addPositionArgument("", ""), -1);
	EXPECT_EQ(poPaser->m_vpoPositionArguments.empty(), true);
	EXPECT_EQ(poPaser->m_vpoOptionArguments.empty(), true);
	EXPECT_EQ(poPaser->m_oArgNameSet.empty(), true);

	EXPECT_EQ(poPaser->addPositionArgument("arg01", "The first position argument."), 0);
	EXPECT_EQ(poPaser->m_vpoOptionArguments.empty(), true);
	EXPECT_EQ(poPaser->m_oArgNameSet.count("arg01"), 1);
	EXPECT_EQ(poPaser->m_vpoPositionArguments.size(), 1);
	EXPECT_EQ(poPaser->m_vpoPositionArguments[0]->sArgName, "arg01");
	EXPECT_EQ(poPaser->m_vpoPositionArguments[0]->isNecessary, false);
	EXPECT_EQ(poPaser->m_vpoPositionArguments[0]->sDescription, "The first position argument.");
	EXPECT_EQ(poPaser->m_vpoPositionArguments[0]->sDefaultValue.empty(), true);
	EXPECT_EQ(poPaser->m_vpoPositionArguments[0]->sParsedValue.empty(), true);

	EXPECT_EQ(poPaser->addPositionArgument("arg01", "The first position argument."), 1);
	EXPECT_EQ(poPaser->m_oArgNameSet.count("arg01"), 1);
	EXPECT_EQ(poPaser->m_vpoOptionArguments.empty(), true);
	EXPECT_EQ(poPaser->m_vpoPositionArguments.size(), 1);

	EXPECT_EQ(poPaser->addPositionArgument("arg02", "The second position argument.", true, "123"), 0);
	EXPECT_EQ(poPaser->m_vpoOptionArguments.empty(), true);
	EXPECT_EQ(poPaser->m_oArgNameSet.count("arg01"), 1);
	EXPECT_EQ(poPaser->m_vpoPositionArguments.size(), 2);
	EXPECT_EQ(poPaser->m_vpoPositionArguments[1]->sArgName, "arg02");
	EXPECT_EQ(poPaser->m_vpoPositionArguments[1]->isNecessary, true);
	EXPECT_EQ(poPaser->m_vpoPositionArguments[1]->sDescription, "The second position argument.");
	EXPECT_EQ(poPaser->m_vpoPositionArguments[1]->sDefaultValue, "123");
	EXPECT_EQ(poPaser->m_vpoPositionArguments[1]->sParsedValue, "123");

	EXPECT_EQ(poPaser->addPositionArgument("arg_03", "The third position argument.", false, "test.txt"), 0);
	EXPECT_EQ(poPaser->m_vpoOptionArguments.empty(), true);
	EXPECT_EQ(poPaser->m_oArgNameSet.count("arg_03"), 1);
	EXPECT_EQ(poPaser->m_vpoPositionArguments.size(), 3);
	EXPECT_EQ(poPaser->m_vpoPositionArguments[2]->sArgName, "arg_03");
	EXPECT_EQ(poPaser->m_vpoPositionArguments[2]->isNecessary, false);
	EXPECT_EQ(poPaser->m_vpoPositionArguments[2]->sDescription, "The third position argument.");
	EXPECT_EQ(poPaser->m_vpoPositionArguments[2]->sDefaultValue, "test.txt");
	EXPECT_EQ(poPaser->m_vpoPositionArguments[2]->sParsedValue, "test.txt");

	delete poPaser;
	poPaser = nullptr;
} // End of myArgsParserTest::AddPositionArgument

int main(int argc, char** argv){
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
} // End of main
