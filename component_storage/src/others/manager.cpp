#include "manager.h"

MenuHandler Manager::m_menu;
StorageHandler Manager::m_storage;
ProducentHandler Manager::m_manufacturer;

MenuHandler& Manager::menu() {
    return m_menu;
}
StorageHandler& Manager::storage() {
    return m_storage;
}

ProducentHandler& Manager::manufacturer(){
    return m_manufacturer;
}