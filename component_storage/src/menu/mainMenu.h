#ifndef MENU
#define MENU
#include "menu.h"

class MainMenu : public Menu{
public:
    void run();
private:
    void initialize();
    bool running;
};

#endif