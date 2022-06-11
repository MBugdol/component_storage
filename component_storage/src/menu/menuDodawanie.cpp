#include "menuDodawanie.h"
#include "others/funkcje.h"
#include "others/manager.h"

void MenuDodawanie::run() {
    Manager mng;
    MenuDodawanie::initialize();
    while(running){
        Menu::display();
        int choice = Menu::getChoice();
        switch(choice){
        //powrot do mainmenu
        case 0:
            mng.menu().setStatus(Status::mainMenu);
            MenuDodawanie::running = false;
            break;
        //dodawanie komponentu
        case 1: case 2: case 3: case 4: case 5:
            mng.storage().addComponent(convertToComponentType(choice));
            break;
        default:
            std::cout << "Nie ma takiej opcji w menu!" << std::endl;
            break;
        }
    }      
}
void MenuDodawanie::initialize() {
    Menu::setTitle("\n=DODAWANIE ELEMENTU=");
    Menu::setContent({
        "Wybierz jeden z typow ponizej:",
        "1. Rezystor",
        "2. Kondensator",
        "3. Cewka",
        "4. Tranzystor",
        "5. Uklad scalony",
        "0. Powrot"
    });
    MenuDodawanie::running = true;
}