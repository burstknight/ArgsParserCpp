#include "../includes/myArgsParser.h"
#include <memory>

using namespace std;
using namespace ArgsParserCpp;

myArgsParser::myArgsParser(){
	this->m_vpoOptionArguments.clear();
	this->m_vpoPositionArguments.clear();
	this->m_oArgNameSet.clear();
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

