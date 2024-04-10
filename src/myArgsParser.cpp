#include "ArgsParserCpp/myArgsParser.h"
#include <cctype>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <string>

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

int myArgsParser::addPositionArgument(const std::string& sArgName, const std::string& sDescription, bool isNecessary, const std::string& sDefaultValue){
	if (true == sArgName.empty()) {
		return -1;
	} // End of if-condition

	auto poIter = this->m_oArgNameSet.find(sArgName);
	if (poIter != this->m_oArgNameSet.end()) {
		return 1;
	} // End of if-condition

	this->m_oArgNameSet.insert(sArgName);

	shared_ptr<PositionArgument_s> poPositionArgument = make_shared<PositionArgument_s>();
	poPositionArgument->sArgName = sArgName;
	poPositionArgument->sDescription = sDescription;
	poPositionArgument->sDefaultValue = sDefaultValue;
	poPositionArgument->isNecessary = isNecessary;
	poPositionArgument->sParsedValue = sDefaultValue;
	this->m_vpoPositionArguments.push_back(poPositionArgument);

	return 0;
} // End of myArgsParser::addPositionArgument

void myArgsParser::addOptionArgument(const std::string& sArgName, const std::string& sDescription, const std::string& sLongArg, char cShortArg, bool isNeedValue, const std::string& sDefaultValue){
	char acBuffer[BUFFER_SIZE];

	if (true == sArgName.empty()) {
		snprintf(acBuffer, BUFFER_SIZE, "%s: The parameter `sArgName` cannot be an empty string!", __PRETTY_FUNCTION__);
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

	if (0 != isalpha(cShortArg)) {
		if (0 != this->m_oShortArgumentSet.count(cShortArg)) {
			snprintf(acBuffer, BUFFER_SIZE, "%s: The short argument `-%c` for this option argument `%s` has been added!\n", __PRETTY_FUNCTION__, cShortArg, sArgName.c_str());
			throw invalid_argument(acBuffer);
		} // End of if-condition
	} // End of if-condition

	this->m_oArgNameSet.insert(sArgName);
	shared_ptr<OptionArgument_s> poOptionArgument = make_shared<OptionArgument_s>();
	poOptionArgument->sArgName = sArgName;
	poOptionArgument->isNeedValue = isNeedValue;
	poOptionArgument->sDefaultValue = sDefaultValue;
	poOptionArgument->sParsedValue = sDefaultValue;
	poOptionArgument->sDescription = sDescription;
	poOptionArgument->sLongArg = string("--") + sLongArg;
	snprintf(acBuffer, BUFFER_SIZE, "-%c", cShortArg);
	poOptionArgument->sShortArg = acBuffer;

	this->m_vpoOptionArguments.push_back(poOptionArgument);
} // End of myArgsParser::addOptionArgument

