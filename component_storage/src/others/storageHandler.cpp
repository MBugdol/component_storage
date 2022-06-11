#include "storageHandler.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include "komponenty/rezystor.h"
#include "komponenty/kondensator.h"
#include "komponenty/cewka.h"
#include "komponenty/tranzystor.h"
#include "komponenty/ukladScalony.h"
#include "fileHandler.h"
#include "funkcje.h"

const std::string StorageHandler::storagefile = "storage.csv";

//  _______ ______ _____  __  __ _____ _   _          _      
// |__   __|  ____|  __ \|  \/  |_   _| \ | |   /\   | |     
//    | |  | |__  | |__) | \  / | | | |  \| |  /  \  | |     
//    | |  |  __| |  _  /| |\/| | | | | . ` | / /\ \ | |     
//    | |  | |____| | \ \| |  | |_| |_| |\  |/ ____ \| |____ 
//    |_|  |______|_|  \_\_|  |_|_____|_| \_/_/    \_\______|
//

compPtr StorageHandler::createComponent(ComponentType type){
    switch(type){
    case ComponentType::Rezystor:
        return Rezystor::create();
        break;
    case ComponentType::Kondensator:
        return Kondensator::create();
        break;
    case ComponentType::Cewka:
        return Cewka::create();
        break;
    case ComponentType::Tranzystor:
        return Tranzystor::create();
        break;
    case ComponentType::UkladSc:
        return UkladScalony::create();
        break;
    }
    return nullptr;
}
void StorageHandler::addComponent(ComponentType type){
    compPtr newComponent = createComponent(type);
    magazyn.push_back(newComponent);
}
void StorageHandler::takeComponent(ComponentType type) {
    compPtr searchedComponent = createComponent(type);
    auto iter = std::find_if(magazyn.begin(), magazyn.end(), [searchedComponent](compPtr obj){
        return *searchedComponent == *obj;
    });
    if(iter == magazyn.end()) {
        std::cout << "Nie ma takiego elementu w magazynie!" << std::endl;
        return;
    }
    magazyn.erase(iter);
    std::cout << "Pomyslnie pobrano komponent z magazynu!" << std::endl;
}

//  _____  _      _____ _  __
// |  __ \| |    |_   _| |/ /
// | |__) | |      | | | ' / 
// |  ___/| |      | | |  <  
// | |    | |____ _| |_| . \ 
// |_|    |______|_____|_|\_\
//

compPtr StorageHandler::createComponent(ComponentType type, std::istream& istr){
    switch(type){
    case ComponentType::Rezystor:
        return Rezystor::create(istr);
        break;
    case ComponentType::Kondensator:
        return Kondensator::create(istr);
        break;
    case ComponentType::Cewka:
        return Cewka::create(istr);
        break;
    case ComponentType::Tranzystor:
        return Tranzystor::create(istr);
        break;
    case ComponentType::UkladSc:
        return UkladScalony::create(istr);
        break;
    }
    return nullptr;
}
void StorageHandler::loadFromFile(){
    FileHandler fh(storagefile);
    fh.startInput();
    std::string line;
    while(std::getline(fh.getInput(), line)) {
        try {
            if(line.empty()) continue;   
            std::istringstream iss(line);
            std::string compTypeStr = getString(iss);
            ComponentType compType = convertToComponentType(compTypeStr);
            compPtr newComponent = createComponent(compType, iss);
            magazyn.push_back(newComponent);
        }
        catch(std::string errormsg){
            std::cout << errormsg << '-';
            std::cout << "Pominieto wiersz" << std::endl;
        }
    }
    fh.stopInput();
}
void StorageHandler::exportToFile(){
    std::string filename = getString("Podaj nazwe pliku do eksportu (domyslnie: magexp.txt)", "magexp.txt");
    if(filename == "storage.txt" || filename == "manufacturer.txt") {
        std::cout << "Ta nazwa pliku jest niedozwolona!" << std::endl;
        return;
    }
    FileHandler fh(filename);
    fh.startOutput();
    for(compPtr komponent : magazyn){
        komponent -> exportData(fh.getOutput());
        fh.getOutput() << std::endl;
    }
    fh.stopOutput();
}
void StorageHandler::saveToFile(){
    FileHandler fh(storagefile);
    fh.startOutput();
    for(compPtr komponent : magazyn){
        komponent -> saveData(fh.getOutput());
        fh.getOutput() << std::endl;
    }
    fh.stopOutput();
}