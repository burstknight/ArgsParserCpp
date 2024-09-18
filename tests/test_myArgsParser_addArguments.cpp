#include "ArgsParserCpp/myArgsParser.h"
#include "gtest/gtest.h"
#include <cstdio>
#include <gtest/gtest.h>
#include <memory>
#include <stdexcept>

using namespace std;
using namespace ArgsParserCpp;

TEST(myArgsParserTest, AddPositionArgumentFail) {
	unique_ptr<myArgsParser> poPaser(new myArgsParser());

	EXPECT_THROW(poPaser->addPositionArgument("", ""), invalid_argument);
	EXPECT_EQ(poPaser->m_vpoPositionArguments.empty(), true);
	EXPECT_EQ(poPaser->m_vpoOptionArguments.empty(), true);
	EXPECT_EQ(poPaser->m_oArgNameSet.empty(), true);

	EXPECT_NO_THROW(poPaser->addPositionArgument("arg01", "The first position argument."));
	EXPECT_EQ(poPaser->m_vpoOptionArguments.empty(), true);
	EXPECT_EQ(poPaser->m_oArgNameSet.count("arg01"), 1);
	EXPECT_EQ(poPaser->m_vpoPositionArguments.size(), 1);
	EXPECT_EQ(poPaser->m_vpoPositionArguments[0]->sArgName, "arg01");
	EXPECT_EQ(poPaser->m_vpoPositionArguments[0]->isNecessary, false);
	EXPECT_EQ(poPaser->m_vpoPositionArguments[0]->sDescription, "The first position argument.");
	EXPECT_EQ(poPaser->m_vpoPositionArguments[0]->sDefaultValue.empty(), true);
	EXPECT_EQ(poPaser->m_vpoPositionArguments[0]->sParsedValue.empty(), true);

	EXPECT_THROW(poPaser->addPositionArgument("arg01", "The first position argument."), invalid_argument);
	EXPECT_EQ(poPaser->m_oArgNameSet.count("arg01"), 1);
	EXPECT_EQ(poPaser->m_vpoOptionArguments.empty(), true);
	EXPECT_EQ(poPaser->m_vpoPositionArguments.size(), 1);

	EXPECT_NO_THROW(poPaser->addPositionArgument("arg02", "The second position argument.", true, "123"));
	EXPECT_EQ(poPaser->m_vpoOptionArguments.empty(), true);
	EXPECT_EQ(poPaser->m_oArgNameSet.count("arg01"), 1);
	EXPECT_EQ(poPaser->m_vpoPositionArguments.size(), 2);
	EXPECT_EQ(poPaser->m_vpoPositionArguments[1]->sArgName, "arg02");
	EXPECT_EQ(poPaser->m_vpoPositionArguments[1]->isNecessary, true);
	EXPECT_EQ(poPaser->m_vpoPositionArguments[1]->sDescription, "The second position argument.");
	EXPECT_EQ(poPaser->m_vpoPositionArguments[1]->sDefaultValue, "123");
	EXPECT_EQ(poPaser->m_vpoPositionArguments[1]->sParsedValue, "123");

	EXPECT_NO_THROW(poPaser->addPositionArgument("arg_03", "The third position argument.", false, "test.txt"));
	EXPECT_EQ(poPaser->m_vpoOptionArguments.empty(), true);
	EXPECT_EQ(poPaser->m_oArgNameSet.count("arg_03"), 1);
	EXPECT_EQ(poPaser->m_vpoPositionArguments.size(), 3);
	EXPECT_EQ(poPaser->m_vpoPositionArguments[2]->sArgName, "arg_03");
	EXPECT_EQ(poPaser->m_vpoPositionArguments[2]->isNecessary, false);
	EXPECT_EQ(poPaser->m_vpoPositionArguments[2]->sDescription, "The third position argument.");
	EXPECT_EQ(poPaser->m_vpoPositionArguments[2]->sDefaultValue, "test.txt");
	EXPECT_EQ(poPaser->m_vpoPositionArguments[2]->sParsedValue, "test.txt");
} // End of myArgsParserTest::AddPositionArgumentFail

TEST(myArgsParserTest, AddPositionArgumentSucceed) {
	unique_ptr<myArgsParser> poPaser(new myArgsParser());

	EXPECT_THROW(poPaser->addPositionArgument("", ""), invalid_argument);
	EXPECT_EQ(poPaser->m_vpoPositionArguments.empty(), true);
	EXPECT_EQ(poPaser->m_vpoOptionArguments.empty(), true);
	EXPECT_EQ(poPaser->m_oArgNameSet.empty(), true);

	EXPECT_NO_THROW(poPaser->addPositionArgument("arg01", "The first position argument."));
	EXPECT_EQ(poPaser->m_vpoOptionArguments.empty(), true);
	EXPECT_EQ(poPaser->m_oArgNameSet.count("arg01"), 1);
	EXPECT_EQ(poPaser->m_vpoPositionArguments.size(), 1);
	EXPECT_EQ(poPaser->m_vpoPositionArguments[0]->sArgName, "arg01");
	EXPECT_EQ(poPaser->m_vpoPositionArguments[0]->isNecessary, false);
	EXPECT_EQ(poPaser->m_vpoPositionArguments[0]->sDescription, "The first position argument.");
	EXPECT_EQ(poPaser->m_vpoPositionArguments[0]->sDefaultValue.empty(), true);
	EXPECT_EQ(poPaser->m_vpoPositionArguments[0]->sParsedValue.empty(), true);

	EXPECT_THROW(poPaser->addPositionArgument("arg01", "The first position argument."), invalid_argument);
	EXPECT_EQ(poPaser->m_oArgNameSet.count("arg01"), 1);
	EXPECT_EQ(poPaser->m_vpoOptionArguments.empty(), true);
	EXPECT_EQ(poPaser->m_vpoPositionArguments.size(), 1);

	EXPECT_NO_THROW(poPaser->addPositionArgument("arg02", "The second position argument.", true, "123"));
	EXPECT_EQ(poPaser->m_vpoOptionArguments.empty(), true);
	EXPECT_EQ(poPaser->m_oArgNameSet.count("arg01"), 1);
	EXPECT_EQ(poPaser->m_vpoPositionArguments.size(), 2);
	EXPECT_EQ(poPaser->m_vpoPositionArguments[1]->sArgName, "arg02");
	EXPECT_EQ(poPaser->m_vpoPositionArguments[1]->isNecessary, true);
	EXPECT_EQ(poPaser->m_vpoPositionArguments[1]->sDescription, "The second position argument.");
	EXPECT_EQ(poPaser->m_vpoPositionArguments[1]->sDefaultValue, "123");
	EXPECT_EQ(poPaser->m_vpoPositionArguments[1]->sParsedValue, "123");

	EXPECT_NO_THROW(poPaser->addPositionArgument("arg_03", "The third position argument.", false, "test.txt"));
	EXPECT_EQ(poPaser->m_vpoOptionArguments.empty(), true);
	EXPECT_EQ(poPaser->m_oArgNameSet.count("arg_03"), 1);
	EXPECT_EQ(poPaser->m_vpoPositionArguments.size(), 3);
	EXPECT_EQ(poPaser->m_vpoPositionArguments[2]->sArgName, "arg_03");
	EXPECT_EQ(poPaser->m_vpoPositionArguments[2]->isNecessary, false);
	EXPECT_EQ(poPaser->m_vpoPositionArguments[2]->sDescription, "The third position argument.");
	EXPECT_EQ(poPaser->m_vpoPositionArguments[2]->sDefaultValue, "test.txt");
	EXPECT_EQ(poPaser->m_vpoPositionArguments[2]->sParsedValue, "test.txt");
} // End of myArgsParserTest::AddPositionArgumentSucceed

TEST(myArgsParserTest, AddOptionArgumentFailed) {
	shared_ptr<myArgsParser> poPaser(new myArgsParser());

	EXPECT_THROW(poPaser->addOptionArgument("", "", "", '\0'), invalid_argument);

	poPaser->m_oArgNameSet.insert("existed_argname");
	EXPECT_THROW(poPaser->addOptionArgument("existed_argname", "existed arg name", "test", 't'), invalid_argument);
	poPaser->m_oArgNameSet.erase(poPaser->m_oArgNameSet.find("existed_argname"));

	poPaser->m_oLongArguemntSet.insert("existed_arg");
	EXPECT_THROW(poPaser->addOptionArgument("existed", "", "existed_arg", '\0'), invalid_argument);
	poPaser->m_oLongArguemntSet.erase(poPaser->m_oLongArguemntSet.find("existed_arg"));

	poPaser->m_oShortArgumentSet.insert('a');
	EXPECT_THROW(poPaser->addOptionArgument("existed", "", "", 'a'), invalid_argument);
	poPaser->m_oShortArgumentSet.erase(poPaser->m_oShortArgumentSet.find('a'));

	EXPECT_THROW(poPaser->addOptionArgument("invalid_short_arg", "", "", 27), invalid_argument);
} // End of myArgsParserTest::AddOptionArgumentFailed

TEST(myArgsParserTest, AddOptionArgumentSucceed) {
	shared_ptr<myArgsParser> poPaser(new myArgsParser());

	EXPECT_NO_THROW(poPaser->addOptionArgument("option1", "The firt option argugment.", "option1", '\0'));
	EXPECT_EQ(poPaser->m_oShortArgumentSet.empty(), true);
	EXPECT_EQ(poPaser->m_oArgNameSet.count("option1"), 1);
	EXPECT_EQ(poPaser->m_oLongArguemntSet.size(), 1);
	EXPECT_EQ(poPaser->m_oLongArguemntSet.count("option1"), 1);
	EXPECT_EQ(poPaser->m_vpoOptionArguments.size(), 1);
	EXPECT_EQ(poPaser->m_vpoOptionArguments[0]->sArgName, "option1");
	EXPECT_EQ(poPaser->m_vpoOptionArguments[0]->sLongArg, "--option1");
	EXPECT_EQ(poPaser->m_vpoOptionArguments[0]->sShortArg.empty(), true);
	EXPECT_EQ(poPaser->m_vpoOptionArguments[0]->sDescription, "The firt option argugment.");
	EXPECT_EQ(poPaser->m_vpoOptionArguments[0]->isNeedValue, false);
	EXPECT_EQ(poPaser->m_vpoOptionArguments[0]->sDefaultValue.empty(), true);
	EXPECT_EQ(poPaser->m_vpoOptionArguments[0]->sParsedValue.empty(), true);

	EXPECT_NO_THROW(poPaser->addOptionArgument("option2", "The second option argugment.", "", 'a', true, "123"));
	EXPECT_EQ(poPaser->m_oArgNameSet.size(), 2);
	EXPECT_EQ(poPaser->m_oArgNameSet.count("option2"), 1);
	EXPECT_EQ(poPaser->m_oShortArgumentSet.size(), 1);
	EXPECT_EQ(poPaser->m_oShortArgumentSet.count('a'), 1);
	EXPECT_EQ(poPaser->m_oLongArguemntSet.size(), 1);
	EXPECT_EQ(poPaser->m_vpoOptionArguments.size(), 2);
	EXPECT_EQ(poPaser->m_vpoOptionArguments[1]->sArgName, "option2");
	EXPECT_EQ(poPaser->m_vpoOptionArguments[1]->sLongArg.empty(), true);
	EXPECT_EQ(poPaser->m_vpoOptionArguments[1]->sShortArg, "a");
	EXPECT_EQ(poPaser->m_vpoOptionArguments[1]->sDescription, "The second option argugment.");
	EXPECT_EQ(poPaser->m_vpoOptionArguments[1]->isNeedValue, true);
	EXPECT_EQ(poPaser->m_vpoOptionArguments[1]->sDefaultValue, "123");
	EXPECT_EQ(poPaser->m_vpoOptionArguments[1]->sParsedValue, "123");

	EXPECT_NO_THROW(poPaser->addOptionArgument("option3", "The third option argugment.", "third", 'c', false));
	EXPECT_EQ(poPaser->m_oArgNameSet.size(), 3);
	EXPECT_EQ(poPaser->m_oArgNameSet.count("option3"), 1);
	EXPECT_EQ(poPaser->m_oShortArgumentSet.size(), 2);
	EXPECT_EQ(poPaser->m_oShortArgumentSet.count('c'), 1);
	EXPECT_EQ(poPaser->m_oLongArguemntSet.size(), 2);
	EXPECT_EQ(poPaser->m_oLongArguemntSet.count("third"), 1);
	EXPECT_EQ(poPaser->m_vpoOptionArguments.size(), 3);
	EXPECT_EQ(poPaser->m_vpoOptionArguments[2]->sArgName, "option3");
	EXPECT_EQ(poPaser->m_vpoOptionArguments[2]->sLongArg, "--third");
	EXPECT_EQ(poPaser->m_vpoOptionArguments[2]->sShortArg, "c");
	EXPECT_EQ(poPaser->m_vpoOptionArguments[2]->sDescription, "The third option argugment.");
	EXPECT_EQ(poPaser->m_vpoOptionArguments[2]->isNeedValue, false);
	EXPECT_EQ(poPaser->m_vpoOptionArguments[2]->sDefaultValue, "");
	EXPECT_EQ(poPaser->m_vpoOptionArguments[2]->sParsedValue, "");

	EXPECT_NO_THROW(poPaser->addOptionArgument("option4", "The fourth option argugment.", "fourth", 0));
	EXPECT_EQ(poPaser->m_oArgNameSet.size(), 4);
	EXPECT_EQ(poPaser->m_oArgNameSet.count("option4"), 1);
	EXPECT_EQ(poPaser->m_oShortArgumentSet.size(), 2);
	EXPECT_EQ(poPaser->m_oLongArguemntSet.size(), 3);
	EXPECT_EQ(poPaser->m_oLongArguemntSet.count("fourth"), 1);
	EXPECT_EQ(poPaser->m_vpoOptionArguments.size(), 4);
	EXPECT_EQ(poPaser->m_vpoOptionArguments[3]->sArgName, "option4");
	EXPECT_EQ(poPaser->m_vpoOptionArguments[3]->sLongArg, "--fourth");
	EXPECT_EQ(poPaser->m_vpoOptionArguments[3]->sShortArg.empty(), true);
	EXPECT_EQ(poPaser->m_vpoOptionArguments[3]->sDescription, "The fourth option argugment.");
	EXPECT_EQ(poPaser->m_vpoOptionArguments[3]->isNeedValue, false);
	EXPECT_EQ(poPaser->m_vpoOptionArguments[3]->sDefaultValue, "");
	EXPECT_EQ(poPaser->m_vpoOptionArguments[3]->sParsedValue, "");
} // End of myArgsParserTest::AddOptionArgumentSucceed

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
} // End of main
