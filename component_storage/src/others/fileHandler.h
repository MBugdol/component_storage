#pragma once
#include <string>
#include <vector>
#include <fstream>

class FileHandler{
public:
    FileHandler() = default;
    FileHandler(const std::string&);
    void setFileName(const std::string& n_filename) { filename = n_filename; };
    static void getCurrentDir();

    void startInput();
    std::ifstream& getInput() {return in_file;}
    void stopInput();
    
    void startOutput();
    std::ofstream& getOutput() {return out_file;}
    void stopOutput();
private:
    static std::string filepath;
    std::string filename;
    std::ifstream in_file;
    std::ofstream out_file;
};