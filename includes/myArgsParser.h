#ifndef MY_ARGS_PARSER_H
#define MY_ARGS_PARSER_H

#include <string>
#include <vector>
#include <memory>

namespace ArgsParserCpp {
	class myArgsParser{
		protected:
			/**
			 * @brief This struct wraps some necessary information for option argument.
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
			}; // End of struct OptionArgument_s

			/**
			 * @brief This struct wraps some important information for position argument.
			 *
			 * This class can use this struct to represent the position argument. For example, we can
			 * give a file path for the command "cat" like "cat file.txt", and then the command "cat"
			 * can read and show the context of the given file "file.txt". For this example, "file.txt"
			 * can called the position argument.
			 */
			struct PositionArgument_s{
				/**
				 * @brief Store the position argument name as keyword.
				 *
				 * We need set the value of this member as a keyword in order to get the parsed position
				 * argument in future.
				 */
				std::string sArgName;

				/**
				 * @brief Represent that this position argument is necessary.
				 *
				 * We can set this member to require user to give a value for this position argument.
				 * If user dosen't give a value for this option argument, we should show error message
				 * to alert user.
				 */
				bool isNecessary;

				/**
				 * @brief Store the default value for this position argument.
				 *
				 * We can set this member to give the default value for this position argument. If
				 * user dosen't give any value for this position argument, we can use the default
				 * value as the current value for this position argument.
				 */
				std::string sDefaultValue;

				/**
				 * @brief Store the parsed value.
				 *
				 * If user give a value, we can store the parsed value into this member.
				 */
				std::string sParsedValue;

				/**
				 * @brief Store the description for this position argument.
				 *
				 * We can set this member to show the details for this position argument if user wants
				 * to to more information about this position argument. 
				 */
				std::string sDescription;
			}; // End of struct PositionArgument_s

			/**
			 * @brief This field stores the position argument list.
			 *
			 * User can add all position arguments into this field. And then this class will store
			 * the parsed result into this field for each position argument.
			 */
			std::vector<std::shared_ptr<PositionArgument_s>> m_vpoPositionArguments;

			/**
			 * @brief This field stores the option argument list.
			 * User can add all option arguments into this field. And then this class will store the
			 * parsed result into this field for each option argument.
			 *
			 */
			std::vector<std::shared_ptr<OptionArgument_s>> m_vpoOptionArguments;
	}; // End of class myArgsParser
} // End of namespace ArgsParserCpp

#endif
