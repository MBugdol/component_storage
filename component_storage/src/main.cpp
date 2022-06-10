#include <iostream>
#include <sstream>
#include "others/manager.h"
#include "menu/menuHandler.h"
#include "others/storageHandler.h"
#include "others/fileHandler.h"
#include "others/log.h"
#include "others/funkcje.h"

int main(int argc, char** argv) {
	Log::start();
	try 
	{
		Manager manager;
		manager.manufacturer().loadFromFile();
		manager.file().getFileNameFromMain(argc, argv);
		manager.file().startInput(); 
		manager.storage().getComponentsFromFile(manager.file().getInput());
		manager.file().stopInput();
		manager.menu().start(); ///uruchom system menu
		manager.storage().saveToFile();
		manager.manufacturer().saveToFile();
	}
	catch(std::string msg)
	{
		Log::fatal(msg);
		Log::fatal("Konczenie programu...");
		std::cout << "Wystapil blad ("<< msg << ")\nKonczenie programu..." << std::endl;
	}
	Log::stop();
	return 0;
}