#include "ArgsParserCpp/myArgsParser.h"
#include <cctype>
#include <cstdio>
#include <list>
#include <memory>
#include <stdexcept>
#include <string>
#include <utility>

#ifdef _MSC_VER
	#define __PRETTY_FUNCTION__ 	__FUNCSIG__
#endif // End of _MSC_VER

#define BUFFER_SIZE 4096

using namespace std;
using namespace ArgsParserCpp;

myArgsParser::myArgsParser(){
	this->m_vpoOptionArguments.clear();
	this->m_vpoPositionArguments.clear();
	this->m_oArgNameSet.clear();
	this->m_oShortArgumentSet.clear();
	this->m_oLongArguemntSet.clear();
} // End of constructor

myArgsParser::~myArgsParser(){
	this->m_vpoOptionArguments.clear();
	this->m_vpoPositionArguments.clear();
	this->m_oArgNameSet.clear();
} // End of destructor

void myArgsParser::addPositionArgument(const std::string& sArgName, const std::string& sDescription, bool isNecessary, const std::string& sDefaultValue){
	char acBuffer[BUFFER_SIZE];
	if (true == sArgName.empty()) {
		snprintf(acBuffer, BUFFER_SIZE, "%s: The parameter `sArgName` cannot be an empty string!", __PRETTY_FUNCTION__);
		throw invalid_argument(acBuffer);
	} // End of if-condition

	auto poIter = this->m_oArgNameSet.find(sArgName);
	if (poIter != this->m_oArgNameSet.end()) {
		snprintf(acBuffer, BUFFER_SIZE, "%s: The value `%s` of the parameter `sArgName` has been added!", __PRETTY_FUNCTION__, sArgName.c_str());
		throw invalid_argument(acBuffer);
	} // End of if-condition

	this->m_oArgNameSet.insert(sArgName);

	shared_ptr<PositionArgument_s> poPositionArgument = make_shared<PositionArgument_s>();
	poPositionArgument->sArgName = sArgName;
	poPositionArgument->sDescription = sDescription;
	poPositionArgument->sDefaultValue = sDefaultValue;
	poPositionArgument->isNecessary = isNecessary;
	poPositionArgument->sParsedValue = sDefaultValue;
	this->m_vpoPositionArguments.push_back(poPositionArgument);
} // End of myArgsParser::addPositionArgument

void myArgsParser::addOptionArgument(const std::string& sArgName, const std::string& sDescription, const std::string& sLongArg, char cShortArg, bool isNeedValue, const std::string& sDefaultValue){
	char acBuffer[BUFFER_SIZE];

	if (true == sArgName.empty()) {
		snprintf(acBuffer, BUFFER_SIZE, "%s: The parameter `sArgName` cannot be an empty string!", __PRETTY_FUNCTION__);
		throw invalid_argument(acBuffer);
	} // End of if-condition

	auto poIter = this->m_oArgNameSet.find(sArgName);
	if (poIter != this->m_oArgNameSet.end()) {
		snprintf(acBuffer, BUFFER_SIZE, "%s: The value `%s` of the parameter `sArgName` has been added!", __PRETTY_FUNCTION__, sArgName.c_str());
		throw invalid_argument(acBuffer);
	} // End of if-condition

	if (true == sLongArg.empty() && 0 == isalpha(cShortArg)) {
		snprintf(acBuffer, BUFFER_SIZE, "%s: The parameters `sLongArg` and `cShortArg` are set invalid values meanwhile!", __PRETTY_FUNCTION__);
		throw invalid_argument(acBuffer);
	} // End of if-condition

	if (false == sLongArg.empty()) {
		if (0 != this->m_oLongArguemntSet.count(sLongArg)) {
			snprintf(acBuffer, BUFFER_SIZE, "%s: The long argument `--%s` for this option argument `%s` has been added!\n", __PRETTY_FUNCTION__, sLongArg.c_str(), sArgName.c_str());
			throw invalid_argument(acBuffer);
		} // End of if-condition
	} // End of if-condition

	if (!('\0' == cShortArg || 0 != isalpha(cShortArg))) {
		snprintf(acBuffer, BUFFER_SIZE, "%s: The short argument must get alphabet!\n", __PRETTY_FUNCTION__);
		throw invalid_argument(acBuffer);
	} // End of if-condition

	if (0 != isalpha(cShortArg)) {
		if (0 != this->m_oShortArgumentSet.count(cShortArg)) {
			snprintf(acBuffer, BUFFER_SIZE, "%s: The short argument `-%c` for this option argument `%s` has been added!\n", __PRETTY_FUNCTION__, cShortArg, sArgName.c_str());
			throw invalid_argument(acBuffer);
		} // End of if-condition
	} // End of if-condition

	shared_ptr<OptionArgument_s> poOptionArgument = make_shared<OptionArgument_s>();
	poOptionArgument->sArgName = sArgName;
	poOptionArgument->isNeedValue = isNeedValue;
	poOptionArgument->sDefaultValue = sDefaultValue;
	poOptionArgument->sParsedValue = sDefaultValue;
	poOptionArgument->sDescription = sDescription;

	if (0 != isalpha(cShortArg)) {
		snprintf(acBuffer, BUFFER_SIZE, "%c", cShortArg);
		poOptionArgument->sShortArg = acBuffer;
		this->m_oShortArgumentSet.insert(cShortArg);
	} else {
		poOptionArgument->sShortArg = "";
	} // End of if-condition

	this->m_oArgNameSet.insert(sArgName);
	if (sLongArg.size() > 0) {
		this->m_oLongArguemntSet.insert(sLongArg);
		poOptionArgument->sLongArg = string("--") + sLongArg;
	} else {
		poOptionArgument->sLongArg = "";
	} // End of if-condition

	this->m_vpoOptionArguments.push_back(poOptionArgument);
} // End of myArgsParser::addOptionArgument

void myArgsParser::parseArgs(int argc, char** argv){
	this->m_oParsedArgs.clear();

	list<int> oOptionArgsIndexList;
	for (int i = 0; i < this->m_vpoOptionArguments.size(); i++) {
		oOptionArgsIndexList.push_back(i);
		this->m_oParsedArgs.insert(pair<string, string>(this->m_vpoOptionArguments[i]->sArgName, this->m_vpoOptionArguments[i]->sParsedValue));
	} // End of for-loop

	list<int> oPosistionArgsIndexList;
	for (int i = 0; i < this->m_vpoPositionArguments.size(); i++) {
		oPosistionArgsIndexList.push_back(i);
		this->m_oParsedArgs.insert(pair<string, string>(this->m_vpoPositionArguments[i]->sArgName, this->m_vpoPositionArguments[i]->sParsedValue));
	} // End of for-loop

	enum ArgType_e{
		kPositionArg,
		kLongOptionArg,
		kShortOptionArg,
	};

	int i = 1;
	while (true) {
		if (i >= argc) {
			break;
		} // End of if-condition

		ArgType_e kArgType = ArgType_e::kPositionArg;
		int iCountOfHyphenSymbol = 0;
		for (int j = 0; j < 2; j++) {
			if ('-' == argv[i][j]) {
				iCountOfHyphenSymbol++;
			} // End of if-condition
		} // End of for-loop

		switch (iCountOfHyphenSymbol) {
			case 1:
				kArgType = ArgType_e::kShortOptionArg;
				break;
			case 2:
				kArgType = ArgType_e::kLongOptionArg;
				break;
			default:
				break;
		} // End of switch

		switch (kArgType) {
			case ArgType_e::kPositionArg:
				{
					int index = oPosistionArgsIndexList.front();
					string sArgName = this->m_vpoPositionArguments[index]->sArgName;
					auto poIter = this->m_oParsedArgs.find(sArgName);
					if (poIter != this->m_oParsedArgs.end()) {
						poIter->second = argv[i];
					} // End of if-condition

					oPosistionArgsIndexList.pop_front();
					break;
				}
			default:
				break;
		} // End of switch

		i++;
	} // End of while-loop

	for (auto poIter = oPosistionArgsIndexList.begin(); poIter != oPosistionArgsIndexList.end(); poIter++) {
		int index = *poIter;
		if (true == this->m_vpoPositionArguments[index]->isNecessary) {
			char acBuffer[BUFFER_SIZE];
			snprintf(acBuffer, BUFFER_SIZE, "Error: You must give a value for the position argument `%s!`", this->m_vpoPositionArguments[index]->sArgName.c_str());
			throw runtime_error(acBuffer);
		} // End of if-condition
	} // End of for-loop
} // End of myArgsParser::parseArgs

