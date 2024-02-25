#ifndef MY_ARGS_PARSER_H
#define MY_ARGS_PARSER_H

#include <string>

namespace ArgsParserCpp {
	class myArgsParser{
		protected:
			/**
			 * @brief This struct wrap some necessary information for option argument.
			 *
			 * This class need this struct to represent option arguments like `-h` or `--help`.
			 */
			struct OptionArgument_s{
				/**
				 * @brief Store the option argument name as keyword.
				 *
				 * We need set the value of this member as a keyword in order to get the parsed option
				 * argument in future.
				 */
				std::string sArgName;

				/**
				 * @brief Store the short option argument.
				 *
				 * We need set the short option argument like `-h` to parse the particular option
				 * argument, so this member is necessary.
				 */
				std::string sShortArg;

				/**
				 * @brief Store the long option argument.
				 *
				 * We need set the long option argument like `--help` to parse the particular option
				 * argument. However, this member isn't necessary because we can just use short option
				 * argument.
				 */
				std::string sLongArg;

				/**
				 * @brief Represent that this option argument need be given a value.
				 *
				 * We can set this member to require user to give a value for this option argument.
				 * If user dosen't give a value for this option argument, we should show error message
				 * to alert user.
				 */
				bool isNeedValue;

				/**
				 * @brief Store the default value for this option argument.
				 *
				 * We can set this member to give the default value for this option argument. If
				 * user dosen't give any value for this option argument, we can use the default
				 * value as the current value for this option argument.
				 */
				std::string sDefaultValue;

				/**
				 * @brief Store the parsed value.
				 *
				 * If user give a value, we can store the parsed value into this member.
				 */
				std::string sParsedValue;

				/**
				 * @brief Store the description for this option argument.
				 *
				 * We can set this member to show the details for this option argument if user wants
				 * to to more information about this option argument. 
				 */
				std::string sDescription;
			};
	}; // End of class myArgsParser
} // End of namespace ArgsParserCpp

#endif