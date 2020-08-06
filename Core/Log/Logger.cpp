//
// Created by Tim on 06.08.2020.
//

#include "Logger.h"

namespace Core
{

	Logger::Logger(const std::string& name)
		: name(name)
	{
	}

	std::string Logger::getLogLevelStr(Core::Logger::LogLevel level)
	{
		switch (level) {
			case info:
				return "Info";
			case warn:
				return "Warning";
			case error:
				return "Error";
			case debug:
				return "Debug";
			default:
				return "Unknown";
		}
	}

	void Logger::log(Core::Logger::LogLevel level, const std::string& msg)
	{
		std::string message;
		message = addPadding(name, 15);
		message += addPadding("[" + getLogLevelStr(level) + "]", 15);
		message += msg + "\n";
		printf("%s", message.c_str());
	}

	std::string Logger::addPadding(const std::string& msg, int len)
	{
		std::string text = msg.substr(0, std::min(static_cast<int>(msg.length()), len));
		for (int i = msg.length(); i < len; i++) {
			text += " ";
		}
		return text;
	}

	void Logger::setName(const std::string& name)
	{
		this->name = name;
	}
}