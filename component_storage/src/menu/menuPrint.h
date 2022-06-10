#ifndef MENUPRINT
#define MENUPRINT
#include "menu.h"

class MenuPrint : public Menu {
    public:
        void run();
    private:
        void initialize();
        bool running;
};

#endif