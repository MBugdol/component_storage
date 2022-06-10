#include "manufacturerMenu.h"
#include "../others/manager.h"
void ManufacturerMenu::run(){
    Manager mng;
    ManufacturerMenu::initialize();
    while(ManufacturerMenu::running){
        Menu::display();
        switch(Menu::getChoice()){
        case 0:
            mng.menu().setStatus(Status::mainMenu);
            ManufacturerMenu::running = false;
            break;
        case 1:
            mng.manufacturer().listProducents();
            break;
        case 2:
            mng.manufacturer().addProducent();
            break;
        case 3:
            mng.manufacturer().modifyProducent();
            break;
        case 4:
            mng.manufacturer().deleteProducent();
            break;
        }
    }
}

void ManufacturerMenu::initialize(){
    Menu::setTitle("\n=PRODUCENCI=\nWybierz jedna z opcji ponizej:");
    Menu::setContent({
        "1. Wyswietl liste producentow",
        "2. Dodaj producenta",
        "3. Zmien adres producenta",
        "4. Usun producenta",
        "0. Powrot"
    });
    ManufacturerMenu::running = true;
}