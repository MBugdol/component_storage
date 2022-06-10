#ifndef MANUFACTURERMENU
#define MANUFACTURERMENU
#include "menu.h"

class ManufacturerMenu : public Menu {
public:
    void run();
private:
    void initialize();
    bool running;
};

#endif