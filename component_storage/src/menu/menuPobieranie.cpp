#include "menuPobieranie.h"
#include "others/funkcje.h"
#include "others/manager.h"

void MenuPobieranie::run() {
    Manager mng;
    MenuPobieranie::initialize();
    while(running){
        Menu::display();
        int choice = Menu::getChoice();
        switch(choice){
        case 0:
            mng.menu().setStatus(Status::mainMenu);
            MenuPobieranie::running = false;
            break;
        case 1: case 2: case 3: case 4: case 5:
            mng.storage().takeComponent(convertToComponentType(choice));
            break;
        default:
            std::cout << "Nie ma takiej opcji w menu!" << std::endl;
            break;
        }
    }
}

void MenuPobieranie::initialize() {
    Menu::setTitle("\n=POBIERANIE ELEMENTU=");
    Menu::setContent({
        "Wybierz jeden z typow ponizej:",
        "1. Rezystor",
        "2. Kondensator",
        "3. Cewka",
        "4. Tranzystor",
        "5. Uklad scalony",
        "0. Powrot"
    });
    MenuPobieranie::running = true;
}