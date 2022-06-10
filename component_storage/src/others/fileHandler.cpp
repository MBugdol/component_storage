#include "fileHandler.h"
#include "funkcje.h"

std::string FileHandler::filepath = "../../component_storage/io/";

FileHandler::FileHandler(const std::string& fname) : filename{ fname } {
}
    
//input
void FileHandler::startInput(){
    in_file.open(filepath+filename);

    if(!in_file) {
        std::string errormsg = "Plik " + filename + " nie istnieje lub jest zajety!";
        throw errormsg;
    }
}
void FileHandler::stopInput(){
    in_file.close();
}

//output
void FileHandler::startOutput() {
    out_file.open(filepath+filename);
    if(!out_file) {
        std::string errormsg = "Plik " + filename + " nie istnieje lub jest zajety!";
        throw errormsg;
    }
}
void FileHandler::stopOutput() {
    out_file.close();
}