#include <iostream>
#include <sstream>
#include "others/manager.h"
#include "menu/menuHandler.h"
#include "others/storageHandler.h"
#include "others/fileHandler.h"
#include "others/funkcje.h"

int main() {
	//try-catch dla bledow poziomu fatal
	try 
	{
		Manager manager;
		FileHandler fh("Help");

		manager.manufacturer().loadFromFile();	
		manager.storage().loadFromFile();

		manager.menu().start();

		manager.storage().saveToFile();
		manager.manufacturer().saveToFile();
	}
	catch(std::string msg)
	{
		std::cout << "Wystapil blad ("<< msg << ")\nKonczenie programu..." << std::endl;
	}
	return 0;
}