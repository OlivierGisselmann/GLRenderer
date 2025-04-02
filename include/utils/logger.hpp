#pragma once

#include <iostream>
#include <string>

#define LOG(level, message) (logger::log(level, message))

class logger
{
public:
    enum level
    {
        DEBUG,
        INFO,
        WARNING,
        ERROR,
        FATAL
    };
    static void log(level severity, const std::string& message)
    {
        std::cout << '[' << level_to_string(severity) << "] " << message << '\n';
    }
    static std::string level_to_string(level severity)
    {
        switch (severity)
        {
        case level::DEBUG: return "DEBUG";
        case level::INFO: return "INFO";
        case level::WARNING: return "WARNING";
        case level::ERROR: return "ERROR";
        case level::FATAL: return "FATAL";
        default: return "LOG";
        }
    }
};
