#ifndef PRODUCENTHANDLER
#define PRODUCENTHANDLER

#include "producent.h"
#include <vector>
class ProducentHandler {
public:
    void loadFromFile();
    void saveToFile();
    void addProducent();
    void addProducent(Producent);
    void deleteProducent();
    void modifyProducent();
    void listProducents();
    void exportToFile();
private:
    std::vector<Producent>producenci;
};

#endif