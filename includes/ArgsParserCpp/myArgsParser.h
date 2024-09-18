#ifndef ARGSPARSERCPP_MYARGSPARSER_H
#define ARGSPARSERCPP_MYARGSPARSER_H

#include "types.h"
#include <map>
#include <memory>
#include <set>
#include <vector>

namespace ArgsParserCpp {
class myArgsParser {
#ifdef Unit_Test
public:
#else
protected:
#endif // End of Unit_test

	/**
	 * @brief This field stores the position argument list.
	 *
	 * User can add all position arguments into this field. And then this class will store
	 * the parsed result into this field for each position argument.
	 */
	std::vector<std::shared_ptr<DataStructures::PositionArgument_s>> m_vpoPositionArguments;

	/**
	 * @brief This field stores the option argument list.
	 * User can add all option arguments into this field. And then this class will store the
	 * parsed result into this field for each option argument.
	 *
	 */
	std::vector<std::shared_ptr<DataStructures::OptionArgument_s>> m_vpoOptionArguments;

	/**
	 * @brief This field can store argument names.
	 *
	 * We need use this field to avoid user giving the existed argument names.
	 */
	std::set<std::string> m_oArgNameSet;

	/**
	 * @brief This field can store all added short arguments.
	 *
	 * We need use this field to avoid user giving the existed short arguments.
	 */
	std::set<char> m_oShortArgumentSet;

	/**
	 * @brief This field can store all added long arguments.
	 *
	 * We need use this field to avoid user giving the existed long arguments.
	 */
	std::set<std::string> m_oLongArguemntSet;

	/**
	 * @brief This field will store the parsed arguments.
	 *
	 * This class will store all parsed arguments into this field.
	 */
	std::map<std::string, std::string> m_oParsedArgs;

	// public member functions
public:
	/**
	 * @brief Constructor.
	 *
	 * This member function can initialize all resources.
	 */
	myArgsParser();

	/**
	 * @brief Destructor.
	 *
	 * This member function can release all resources.
	 */
	~myArgsParser();

	/**
	 * @brief Add a position argument.
	 *
	 * You can use this member function to add a position argument for your program. And
	 * then this class will parse the command line arguments for the added position argument.
	 *
	 * @param sArgName: Give the argument name for this added position argument. You will use the given argument name to get the parsed value for this added position argument. Note, any position argument and option argument must has the unique argument name.
	 * @param sDescription: Give the information for this added position argument.
	 * @param isNecessary: This added position argument is regarded as the necessary position argument for your program if you set this flag to true. Otherwise, this class requires user give a value for this position argument. The default value is false.
	 * @param sDefaultValue: You can give a default value for this added position argument. The default value is an empty string.
	 *
	 * @throw std::invalid_argument: This member function will issue this type exception if this member function gets any invalid parameter.
	 *
	 * @see PositionArgument_s
	 */
	void addPositionArgument(const std::string& sArgName, const std::string& sDescription, bool isNecessary = false, const std::string& sDefaultValue = "");

	/**
	 * @brief Add an option argument.
	 *
	 * You can use this member function to add an option argument for your command line
	 * program. And then this class will parse the command line arguments for the added
	 * option argument.
	 *
	 * @param sArgName: Give the argument name for this added option argument. You will use the given argument name to get the parsed value for this added option argument. Note, any option argument and option argument must has the unique argument name.
	 * @param sDescription: Give the information for this added option argument.
	 * @param sLongArg: Give an unique long argument name for this added option argument. This member function will automatically add "--" for the given long argument. For example, you just give "argument" if you hope to add "--argument" as the long argument. You can give an empty for this long argument if you don't set the long argument, but you have to set the short argument for this option argument.
	 * @param cShortArg: Give an unique short argument name like "a". This member function will add "-" for the given short argument. For example, you just give "a" if you want to add "-a" as the short argument. You can give null charactor "'\0'" or the number "0" for this short argument if you don't set the short argument, but you must set the long argument for this option argument.
	 * @param isNeedValue: If this option argument need receive a value, you need set this flag to true. Otherwise, you should give false for this option argument.
	 * @param sDefaultValue: You can give a default value for this added option argument. The default value is an empty string.
	 *
	 * @throw std::invalid_argument: This member function will issue this type exception if this member function gets any invalid parameters.
	 */
	void addOptionArgument(const std::string& sArgName, const std::string& sDescription, const std::string& sLongArg, char cShortArg, bool isNeedValue = false, const std::string& sDefaultValue = "");

	/**
	 * @brief Parse the command line arguments.
	 *
	 * You can use this member function to parse the command line arguments. This member
	 * function will store the parsed result into the field myArgsParser::m_oParsedArgs.
	 *
	 * @param argc: Give the number of the command line arguments.
	 * @param argv: Give the array of the command line arguments.
	 */
	void parseArgs(int argc, char** argv);
}; // End of class myArgsParser
} // End of namespace ArgsParserCpp

#endif
