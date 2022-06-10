#ifndef PRODUCENT
#define PRODUCENT
#include <iostream>
#include <string>

class Producent {
public:
    Producent(std::string, std::string);
    void setAdress(std::string);
    void display();
    void exportData(std::ostream&);
    std::string getName() {return nazwa;}
    friend bool operator==(const Producent&, const Producent&);
    friend std::ostream& operator<<(std::ostream&, const Producent&);
private:
    std::string nazwa;
    std::string adres;
};
#endif