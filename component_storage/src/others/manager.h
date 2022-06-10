#ifndef MANAGER
#define MANAGER

#include "menu/menuHandler.h"
#include "storageHandler.h"
#include "producenci/producentHandler.h"

class Manager{
public:
    MenuHandler& menu();
    StorageHandler& storage();
    ProducentHandler& manufacturer();
private:
    static MenuHandler m_menu;
    static StorageHandler m_storage;
    static ProducentHandler m_manufacturer;
};

#endif