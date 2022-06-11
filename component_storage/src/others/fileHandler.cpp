#include "fileHandler.h"
#include "funkcje.h"

std::filesystem::path FileHandler::iopath;

FileHandler::FileHandler(const std::string& fname) : filename{ fname }, fullpath{ (iopath / fname).string() }{
}
void FileHandler::setFilepath(const std::string& binpath) {
    iopath = binpath;
    iopath = iopath.parent_path();
    //aby przejsc z pliku binarnego do folderu io nalezy wrocic dwa foldery (../..), a nastepnie przejsc do component_storage/io/
    iopath = (iopath / "../../component_storage/io").lexically_normal();
    iopath.make_preferred();
}
void FileHandler::startInput(){
    in_file.open(fullpath);
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
    out_file.open(fullpath);
    if(!out_file) {
        std::string errormsg = "Plik " + filename + " nie istnieje lub jest zajety!";
        throw errormsg;
    }
}
void FileHandler::stopOutput() {
    out_file.close();
}