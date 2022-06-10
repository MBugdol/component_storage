#ifndef LOG
#define LOG
#include <string>
#include <fstream>

class Log{
public:
    enum class ErrorLevel {
        All,
        Trace,
        Debug,
        Info,
        Warning,
        Error,
        Fatal,
        Off
    };
    static void start();
    static void stop();
    static void setLogLevel(ErrorLevel);
    static void trace(std::string);
    static void debug(std::string);
    static void info(std::string);
    static void warning(std::string);
    static void error(std::string);
    static void fatal(std::string);
private:
    static ErrorLevel log_level;
    static std::string log_file_name;
    static std::ofstream out;
};

#endif