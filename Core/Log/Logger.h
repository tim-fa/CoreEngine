//
// Created by Tim on 06.08.2020.
//


// STL
#include <string>

// Libraries
#include <fmt/format.h>

namespace Core {
    class Logger {

        enum LogLevel{
            info,
            warn,
            error,
            debug
        };

    public:
        Logger(const std::string &name);

        template<class ... Args>
        void i(const std::string &msg, Args ... args) {
            log(LogLevel::info, fmt::format(msg, args...));
        }

        template<class ... Args>
        void w(const std::string &msg, Args ... args){
            log(LogLevel::warn, fmt::format(msg, args...));
        }

        template<class ... Args>
        void e(const std::string &msg, Args ... args){
            log(LogLevel::error, fmt::format(msg, args...));
        }

        template<class ... Args>
        void d(const std::string &msg, Args ... args){
            log(LogLevel::debug, fmt::format(msg, args...));
        }

    private:
        static std::string getLogLevelStr(LogLevel level);
        void log(LogLevel level, const std::string &msg);

        std::string name;

    };
}