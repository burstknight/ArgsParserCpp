#ifndef MY_ARGS_PARSER_H
#define MY_ARGS_PARSER_H

#include <string>
#include <vector>
#include <memory>
#include <set>

namespace ArgsParserCpp {
	class myArgsParser{
#ifdef Unit_Test
		public:
#else
		protected:
#endif // End of Unit_test

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
			 * @retval 0: Succeed to add the given position argument. 
			 * @retval 1: Fail to add the given position argument becasue the argument name has been added.
			 * @retval -1: Fail to add the give position argument becasue the give argument name is an empty string.
			 *
			 * @see PositionArgument_s
			 */
			int addPositionArgument(const std::string& sArgName, const std::string& sDescription, bool isNecessary = false, const std::string& sDefaultValue = "");

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
			 * @param cShortArg: Give an unique short argument name like "a". This member function will add "-" for the given short argument. For example, you just give "a" if you want to add "-a" as the short argument. You can give null charactor "'\0'" for this short argument if you don't set the short argument, but you must set the long argument for this option argument.
			 * @param isNeedValue: If this option argument need receive a value, you need set this flag to true. Otherwise, you should give false for this option argument.
			 * @param sDefaultValue: You can give a default value for this added option argument. The default value is an empty string.
			 *
			 * @return 
			 */
			void addOptionArgument(const std::string& sArgName, const std::string& sDescription, const std::string& sLongArg, char cShortArg, bool isNeedValue = false, const std::string& sDefaultValue = "");
	}; // End of class myArgsParser
} // End of namespace ArgsParserCpp

#endif
