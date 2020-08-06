//
// Created by Tim on 06.08.2020.
//

#include "Logger.h"

Core::Logger::Logger(const std::string &name)
        : name(name) {

}

std::string Core::Logger::getLogLevelStr(Core::Logger::LogLevel level) {
    switch (level) {
        case info:
            return "Info";
        case warn:
            return "Warn";
        case error:
            return "Error";
        case debug:
            return "Debug";
        default:
            return "Unknown";
    }
}

void Core::Logger::log(Core::Logger::LogLevel level, const std::string &msg) {
    printf("%s\t\t[%s]:\t %s\n", name.c_str(), getLogLevelStr(level).c_str(), msg.c_str());
}
