#ifndef MENUDODAWANIE
#define MENUDODAWANIE
#include "menu.h"

class MenuDodawanie : public Menu {
public:
    void run();
private:
    void initialize();
    bool running;
};

#endif