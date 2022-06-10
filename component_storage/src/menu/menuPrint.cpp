#include "menuPrint.h"
#include "../others/manager.h"

void MenuPrint::run(){
    Manager mng;
    MenuPrint::initialize();
    while(running){
        Menu::display();
        switch(Menu::getChoice()){
        case 0:
            mng.menu().setStatus(Status::mainMenu);
            MenuPrint::running = false;
            break;
        case 1:
            mng.storage().exportToFile();
            mng.menu().setStatus(Status::mainMenu);
            break;
        case 2:
            mng.manufacturer().exportToFile();
            mng.menu().setStatus(Status::mainMenu);
            break;
        }
    }
}

void MenuPrint::initialize(){
    Menu::setTitle("\n=WYDRUK DANYCH=");
    Menu::setContent({
        "Wybierz jedna z opcji ponizej:",
        "1. Wypisz stan magazynu do pliku",
        "2. Wypisz liste producentow do pliku",
        "0. Powrot"
    });
    MenuPrint::running = true;
}