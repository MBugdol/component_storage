#include "log.h"
#include <iostream>
#include <fstream>

Log::ErrorLevel Log::log_level = Log::ErrorLevel::Info;
std::string Log::log_file_name = "log.txt";
std::ofstream Log::out;

void Log::setLogLevel(Log::ErrorLevel level){
    Log::log_level = level;
}
void Log::start(){
    out.open(Log::log_file_name);
}
void Log::stop(){
    out.close();
}
void Log::trace(std::string msg){
    if(Log::log_level > Log::ErrorLevel::Trace) return;
    out << "[TRACE] " << msg << std::endl;
}
void Log::debug(std::string msg){
    if(Log::log_level > Log::ErrorLevel::Debug) return;
    out << "[DEBUG] " << msg << std::endl;
}
void Log::info(std::string msg){
    if(Log::log_level > Log::ErrorLevel::Info) return;
    out << "[INFO] " << msg << std::endl;
}
void Log::warning(std::string msg){
    if(Log::log_level > Log::ErrorLevel::Warning) return;
    out << "[WARNING] " << msg << std::endl;
}
void Log::error(std::string msg){
    if(Log::log_level > Log::ErrorLevel::Error) return;
    out << "[ERROR] " << msg << std::endl;
}
void Log::fatal(std::string msg){
    if(Log::log_level > Log::ErrorLevel::Fatal) return;
    out << "[FATAL] " << msg << std::endl;
}