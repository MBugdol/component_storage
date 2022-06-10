#include "fileHandler.h"
#include "funkcje.h"

FileHandler::FileHandler(std::string fname)
    {
        filename = fname;
    }
    
//!input
void FileHandler::startInput(){
    in_file.open(filename);
    if(!in_file) {
        std::string errormsg = "Plik " + filename + " nie istnieje lub jest zajety!";
        throw errormsg;
    }
}
void FileHandler::stopInput(){
    in_file.close();
}
void FileHandler::getFileNameFromMain(int argc, char** argv){
    if(argc != 2) throw std::string("Zła ilość argumentów funkcji main");
    filename = argv[1];
}
//!output
void FileHandler::startOutput() {
    out_file.open(filename);
    if(!out_file) {
        std::string errormsg = "Plik " + filename + " nie istnieje lub jest zajety!";
        throw errormsg;
    }
}
void FileHandler::stopOutput() {
    out_file.close();
}