#include "mainMenu.h"
#include <iostream>
#include "../others/funkcje.h"
#include "../others/manager.h"

void MainMenu::run() {
	Manager mng;
	MainMenu::initialize();
	while (MainMenu::running) {
		Menu::display();
		switch (Menu::getChoice()) {
		case 1:
			mng.menu().setStatus(Status::addComponent);
			MainMenu::running = false;
			break;
		case 2:
			mng.menu().setStatus(Status::takeComponent);
			MainMenu::running = false;
			break;
		case 3:
			mng.menu().setStatus(Status::manufacturers);
			MainMenu::running = false;
			break;
		case 4:
			mng.menu().setStatus(Status::exporting);
			MainMenu::running = false;
			break;
		case 0:
			mng.menu().setStatus(Status::offline);
			MainMenu::running = false;
			break;
		}
	}
	
}
void MainMenu::initialize() {
	Menu::setTitle("\n=MENU GLOWNE=\nWybierz jedna z opcji ponizej: ");
	Menu::setContent({
		"1. Dodaj komponent",
		"2. Pobierz komponent",
		"3. Menu producentow",
		"4. Eksportuj dane",
		"0. Zakoncz program"
		});
	MainMenu::running = true;
}