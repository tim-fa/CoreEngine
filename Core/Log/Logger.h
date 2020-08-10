//
// Created by Tim on 06.08.2020.
//
#ifndef LOGGER_H
#define LOGGER_H

// STL
#include <string>

// Libraries
#include <fmt/format.h>

#define Assert(condition, msg) Assert_fmt(condition, msg, "")
#define Assert_fmt(condition, msg, ...) fatal(condition, __FILE__, __FUNCTION__, __LINE__, std::string("{}\n") + msg, #condition, __VA_ARGS__)

namespace Core
{
class Logger
{
	public:
		enum LogLevel
		{
			error,
			info,
			warn,
			debug
		};

		explicit Logger(const std::string& name);

		template<class ... Args>
		void i(const std::string& msg, Args ... args)
		{
			log(LogLevel::info, fmt::format(msg, args...));
		}

		template<class ... Args>
		void w(const std::string& msg, Args ... args)
		{
			log(LogLevel::warn, fmt::format(msg, args...));
		}

		template<class ... Args>
		void e(const std::string& msg, Args ... args)
		{
			log(LogLevel::error, fmt::format(msg, args...));
		}

		template<class ... Args>
		void d(const std::string& msg, Args ... args)
		{
			log(LogLevel::debug, fmt::format(msg, args...));
		}

		template<class ... Args>
		void fatal(bool condition, const char* file, const char* function, int line, const std::string& msg, Args ... args)
		{
			if (!condition) {
				e("********** Assertion failed! **********\nin file '{}':{}\nin function '{}'\n" + msg, file, line, function, args...);
				exit(-1);
			}
		}

		void setName(const std::string& name);
		static void setMaxLoglevel(LogLevel level);

	private:
		static std::string getLogLevelStr(LogLevel level);
		void log(LogLevel level, const std::string& msg);
		std::string name;
};
}

#endif