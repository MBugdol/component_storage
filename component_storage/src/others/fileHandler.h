#pragma once
#include <string>
#include <vector>
#include <fstream>

class FileHandler{
public:
    FileHandler() = default;
    FileHandler(std::string);
    void getFileNameFromMain(int, char**);

    void startInput();
    std::ifstream& getInput() {return in_file;}
    void stopInput();
    
    void startOutput();
    std::ofstream& getOutput() {return out_file;}
    void stopOutput();
private:

    std::string filename;
    std::ifstream in_file;
    std::ofstream out_file;
};