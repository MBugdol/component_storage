#include "komponent.h"
#include "../others/funkcje.h"

//!  _  ______  _   _  _____ _______ _____  _    _ _  _______     _         
//! | |/ / __ \| \ | |/ ____|__   __|  __ \| |  | | |/ / ____|   | |  /\    
//! | ' / |  | |  \| | (___    | |  | |__) | |  | | ' / |        | | /  \   
//! |  <| |  | | . ` |\___ \   | |  |  _  /| |  | |  <| |    _   | |/ /\ \  
//! | . \ |__| | |\  |____) |  | |  | | \ \| |__| | . \ |___| |__| / ____ \ 
//! |_|\_\____/|_| \_|_____/   |_|  |_|  \_\\____/|_|\_\_____\____/_/    \_\
//!                                                                         
                                                                         
Komponent::Komponent(const ComponentParams& data)
    : rodzaj(data.type), montaz(data.solder), prod(data.manufacturer) {}

//!   ____  _____  ______ _____         _______ ____  _______     __
//!  / __ \|  __ \|  ____|  __ \     /\|__   __/ __ \|  __ \ \   / /
//! | |  | | |__) | |__  | |__) |   /  \  | | | |  | | |__) \ \_/ / 
//! | |  | |  ___/|  __| |  _  /   / /\ \ | | | |  | |  _  / \   /  
//! | |__| | |    | |____| | \ \  / ____ \| | | |__| | | \ \  | |   
//!  \____/|_|    |______|_|  \_\/_/    \_\_|  \____/|_|  \_\ |_|   
//!                                                                 
                                                                 
bool Komponent::operator==(const Komponent& obj){
    return (rodzaj == obj.rodzaj) &&
        (prod == "" || prod == obj.prod) &&
        (montaz == SolderType::Undefined || montaz == obj.montaz);   
}
bool Komponent::operator!=(const Komponent& obj){
    return !(Komponent::operator==(obj));
}
std::ostream& Komponent::operator<<(std::ostream& ostr) {
    ostr << convertToString(rodzaj) << 
    ' ' << convertToString(montaz);
    if(!prod.empty()) ostr << ' ' << prod;
    else ostr << ' ' << "nieznany"; 
    return ostr;
}
void Komponent::exportData(std::ostream& os){
    os << convertToString(rodzaj);
    if(montaz != SolderType::Undefined) os << ' ' << convertToString(montaz);
    if(!prod.empty()) os << ' ' << prod;
}