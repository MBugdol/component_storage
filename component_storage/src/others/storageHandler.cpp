#include "storageHandler.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include "komponenty/rezystor.h"
#include "komponenty/kondensator.h"
#include "komponenty/cewka.h"
#include "komponenty/tranzystor.h"
#include "komponenty/ukladScalony.h"
#include "manager.h"
#include "funkcje.h"

//!  _______ ______ _____  __  __ _____ _   _          _      
//! |__   __|  ____|  __ \|  \/  |_   _| \ | |   /\   | |     
//!    | |  | |__  | |__) | \  / | | | |  \| |  /  \  | |     
//!    | |  |  __| |  _  /| |\/| | | | | . ` | / /\ \ | |     
//!    | |  | |____| | \ \| |  | |_| |_| |\  |/ ____ \| |____ 
//!    |_|  |______|_|  \_\_|  |_|_____|_| \_/_/    \_\______|
//!

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
    Manager mng;
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

//!  _____  _      _____ _  __
//! |  __ \| |    |_   _| |/ /
//! | |__) | |      | | | ' / 
//! |  ___/| |      | | |  <  
//! | |    | |____ _| |_| . \ 
//! |_|    |______|_____|_|\_\
//!

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
void StorageHandler::getComponentsFromFile(std::ifstream& ifile){
    std::string line;
    while(std::getline(ifile, line)){
        try {
            if(line.empty()) continue;   
            std::istringstream iss(line);
            std::string compTypeStr;
            iss >> compTypeStr;
            ComponentType compType = convertToComponentType(compTypeStr);
            compPtr newComponent = createComponent(compType, iss);
            magazyn.push_back(newComponent);
        }
        catch(std::string errormsg){
            std::cout << "Pominieto wiersz" << std::endl;
        }
    }
}
void StorageHandler::exportToFile(){
    std::string filename = getString("Podaj nazwe pliku do eksportu");
    FileHandler fh(filename);
    fh.startOutput();
    for(compPtr komponent : magazyn){
        komponent -> exportData(fh.getOutput());
        fh.getOutput() << std::endl;
    }
    fh.stopOutput();
}
void StorageHandler::saveToFile(){
    Manager mng;
    mng.file().startOutput();
    for(compPtr komponent : magazyn){
        komponent -> operator<<(mng.file().getOutput());
        mng.file().getOutput() << std::endl;
    }
    mng.file().stopOutput();
}