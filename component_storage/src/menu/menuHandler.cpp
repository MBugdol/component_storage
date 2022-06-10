#include "menuHandler.h"
#include "mainMenu.h"
#include "menuDodawanie.h"
#include "menuPobieranie.h"
#include "manufacturerMenu.h"
#include "menuPrint.h"
#include <iostream>

//glowne metody
void MenuHandler::start() {
	current_status = Status::mainMenu;
	while (current_status != Status::offline) {
		//obsluga zmiany menu
		switch (current_status) {
		case Status::mainMenu:
			launchMain();
			break;
		case Status::addComponent:
			launchAdd();
			break;
		case Status::takeComponent:
			launchTake();
			break;
		case Status::manufacturers:
			launchManufacturers();
			break;
		case Status::exporting:
			launchExport();
			break;
		}
	}
	MenuHandler::stop();
}
void MenuHandler::stop() {
	std::cout << "Konczenie programu..." << std::endl;
}

void MenuHandler::launchMain() {
	MainMenu main;
	main.run();
}
void MenuHandler::launchAdd(){
	MenuDodawanie add;
	add.run();
}
void MenuHandler::launchTake(){
	MenuPobieranie take;
	take.run();
}
void MenuHandler::launchManufacturers(){
	ManufacturerMenu manufacturer;
	manufacturer.run();
}
void MenuHandler::launchExport(){
	MenuPrint exporting;
	exporting.run();
}


//metody set
void MenuHandler::setStatus(Status _st) {
	MenuHandler::current_status = _st;
}
