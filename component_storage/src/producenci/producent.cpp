#include "producent.h"
#include "others/funkcje.h"
#include <iostream>

Producent::Producent(const std::string& n_nazwa, const std::string& n_adres)
    : nazwa(n_nazwa), adres(n_adres) {}

void Producent::exportData(std::ostream& istr) {
    istr << nazwa << ":\n\t" << "Adres : " << adres;
}

void Producent::setAdress(const std::string& n_adress){
    adres = n_adress;
}

void Producent::display(){
    std::cout << nazwa << ":\n\t" << "Adres: " << adres << std::endl;
}

bool operator==(const Producent& obj1, const Producent& obj2){
    return copyToLower(obj1.nazwa) == copyToLower(obj2.nazwa);
}
std::ostream& operator<<(std::ostream& ostr, const Producent& obj){
    ostr << obj.nazwa << ';';;
    if(obj.adres.empty()) ostr << "nieznany" << ';';
    else ostr << obj.adres << ';';
    return ostr;
}
