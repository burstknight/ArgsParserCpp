#include "../includes/myArgsParser.h"

using namespace std;
using namespace ArgsParserCpp;

myArgsParser::myArgsParser(){
	this->m_vpoOptionArguments.clear();
	this->m_vpoPositionArguments.clear();
} // End of constructor

myArgsParser::~myArgsParser(){
	this->m_vpoOptionArguments.clear();
	this->m_vpoPositionArguments.clear();
} // End of destructor

