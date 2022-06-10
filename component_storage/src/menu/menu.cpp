#include "menu.h"
#include <iostream>
#include "others/funkcje.h"

void Menu::display() {
	std::cout << Menu::title << std::endl;
	for (std::string line : Menu::content) {
		std::cout << line << std::endl;
	}
}
int Menu::getChoice() {
	int temp = getInt("Twoj wybor", 0);
	return temp;
}

//metody set
void Menu::setTitle(std::string _title) {Menu::title = _title;}
void Menu::setContent(std::vector<std::string> _content) {Menu::content = _content;}

