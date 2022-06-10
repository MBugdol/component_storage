#include "producent.h"
#include <iostream>

Producent::Producent(std::string _nazwa, std::string _adres)
    : nazwa(_nazwa), adres(_adres) {}

void Producent::exportData(std::ostream& istr) {
    istr << nazwa << ":\n\t" << "Adres : " << adres;
}

void Producent::setAdress(std::string n_adress){
    adres = n_adress;
}

void Producent::display(){
    std::cout << nazwa << ":\n\t" << "Adres: " << adres << std::endl;
}

bool operator==(const Producent& obj1, const Producent& obj2){
    return obj1.nazwa == obj2.nazwa;
}
std::ostream& operator<<(std::ostream& ostr, const Producent& obj){
    ostr << obj.nazwa << ' ' << obj.adres;
    return ostr;
}
