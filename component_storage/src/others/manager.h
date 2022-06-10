#ifndef MANAGER
#define MANAGER

#include "../menu/menuHandler.h"
#include "storageHandler.h"
#include "fileHandler.h"
#include "../producenci/producentHandler.h"

class Manager{
public:
    MenuHandler& menu();
    StorageHandler& storage();
    FileHandler& file();
    ProducentHandler& manufacturer();
private:
    static MenuHandler m_menu;
    static StorageHandler m_storage;
    static FileHandler m_file;
    static ProducentHandler m_manufacturer;
};

#endif