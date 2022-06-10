#ifndef MENUPOBIERANIE
#define MENUPOBIERANIE
#include "menu.h"

class MenuPobieranie : public Menu{
public:
    void run();
private:
    void initialize();
    bool running;
};
#endif