#pragma once
#include <vector>
#include <memory>
#include <fstream>
#include "komponenty/rezystor.h"
#include "komponenty/komponent.h"


class StorageHandler
{
public:
	void addComponent(ComponentType);
	void takeComponent(ComponentType);
	void loadFromFile();
	void exportToFile();
	void saveToFile();
private:
	static const std::string storagefile;
	std::vector<compPtr> magazyn;
	compPtr createComponent(ComponentType);
	compPtr createComponent(ComponentType, std::istream&);
};

