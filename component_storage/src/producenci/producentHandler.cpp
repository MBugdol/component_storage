#include "producentHandler.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include "../others/fileHandler.h"
#include "../others/funkcje.h"

const std::string ProducentHandler::producentfile = "manufacturer.txt";

void ProducentHandler::loadFromFile(){
    FileHandler fh(producentfile);
    fh.startInput();

    std::string line;
    while(std::getline(fh.getInput(), line)){
        std::istringstream iss(line);
        try {
            std::string name = getString(iss);
            std::string address = getString(iss);
            producenci.push_back(Producent{name, address});
        }
        catch(const std::string& errormsg){
            std::cout << errormsg << std::endl;
        }
    }
    fh.stopInput();
}
void ProducentHandler::saveToFile(){
    FileHandler fh(producentfile);
    fh.startOutput();
    for(Producent obj : producenci){
        fh.getOutput() << obj << std::endl;
    }
    fh.stopOutput();
}
void ProducentHandler::addProducent(){
    Producent obj = getProducent();
    if(std::find(producenci.begin(), producenci.end(), obj) != producenci.end()){
        std::cout << "Producent o podanej nazwie znajduje sie juz na liscie!" << std::endl;
        return;
    }
    producenci.push_back(obj);
}
void ProducentHandler::addProducent(Producent obj){
    if(std::find(producenci.begin(), producenci.end(), obj) != producenci.end() || obj.getName().empty()) 
        return;
    producenci.push_back(obj);
}
void ProducentHandler::deleteProducent(){
    std::string name = getString("Podaj nazwe producenta, ktorego chcesz usunac");
    Producent to_delete = {name, ""};
    auto pos = std::find(producenci.begin(), producenci.end(), to_delete);
    if(pos == producenci.end()){ 
        std::cout << "Producent o podanej nazwie nie znajduje sie w bazie!" << std::endl;
        return;
    }
    producenci.erase(pos);
}
void ProducentHandler::modifyProducent(){
    std::string name = getString("Podaj nazwe producenta, ktorego dane chcesz zmienic");
    Producent to_change = {name, ""};
    auto pos = std::find(producenci.begin(), producenci.end(), to_change);
    if(pos == producenci.end()){
        std::cout << "Producent o podanej nazwie nie znajduje sie w bazie!" << std::endl;
        return;
    }
    pos->setAdress(getString("Podaj nowy adres"));
}
void ProducentHandler::listProducents(){
    if(producenci.size() == 0){
        std::cout << "Nie ma jeszcze w bazie zadnych producentow" << std::endl;
        return;
    }
    for(int i = 0; i < producenci.size(); i++) {
        std::cout << i+1 << "] ";
        producenci[i].display();
    }
}
void ProducentHandler::exportToFile(){
    std::string filename = getString("Podaj nazwe pliku do eksportu");
    if(filename == "storage.txt" || filename == "manufacturer.txt") {
        std::cout << "Ta nazwa pliku jest niedozwolona!" << std::endl;
        return;
    }
    FileHandler fh(filename);
    fh.startOutput();
    for(Producent p : producenci){
        p.exportData(fh.getOutput());
        fh.getOutput() << std::endl; 
    }
    fh.stopOutput();
}