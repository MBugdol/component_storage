#include "tranzystor.h"
#include "../others/funkcje.h"
#include "../others/manager.h"

//!  _  ______  _   _  _____ _______ _____  _    _ _  _______     _
//! | |/ / __ \| \ | |/ ____|__   __|  __ \| |  | | |/ / ____|   | |  /\
//! | ' / |  | |  \| | (___    | |  | |__) | |  | | ' / |        | | /  \
//! |  <| |  | | . ` |\___ \   | |  |  _  /| |  | |  <| |    _   | |/ /\ \
//! | . \ |__| | |\  |____) |  | |  | | \ \| |__| | . \ |___| |__| / ____ \
//! |_|\_\____/|_| \_|_____/   |_|  |_|  \_\\____/|_|\_\_____\____/_/    \_\
//!

Tranzystor::Tranzystor(const TransistorParams& data)
	: Komponent(data),
	model(data.model),
	beta(data.beta),
	prad_kolektora(data.collector_current)  {
}
compPtr Tranzystor::create(){
	TransistorParams data = getValues();
	return std::make_shared<Tranzystor>(data);
}
compPtr Tranzystor::create(std::istream& istr){
	TransistorParams data = getValues(istr);
	return std::make_shared<Tranzystor>(data);
}

//!  _____   ____  ____ _____ ______ _____            _   _ _____ ______ 
//! |  __ \ / __ \|  _ \_   _|  ____|  __ \     /\   | \ | |_   _|  ____|
//! | |__) | |  | | |_) || | | |__  | |__) |   /  \  |  \| | | | | |__   
//! |  ___/| |  | |  _ < | | |  __| |  _  /   / /\ \ | . ` | | | |  __|  
//! | |    | |__| | |_) || |_| |____| | \ \  / ____ \| |\  |_| |_| |____ 
//! |_|     \____/|____/_____|______|_|  \_\/_/    \_\_| \_|_____|______|
//!                                                                      

TransistorParams Tranzystor::getValues() {
	TransistorParams data;
	data.type = ComponentType::Tranzystor;
	data.solder = getSolderType("Podaj typ montazu (tht/smt)");
	data.manufacturer = getString("Podaj nazwe producenta");
	Manager mng;
	mng.manufacturer().addProducent(Producent{data.manufacturer, "nieznany"});
	data.model = getString("Podaj nazwe modelu");
	data.beta = getDouble("Podaj bete/wzmocnienie");
	data.collector_current = getSIUnit("Podaj prad kolektora");
	return data;
}
TransistorParams Tranzystor::getValues(std::istream& istr){
	TransistorParams data;
	data.type = ComponentType::Tranzystor;
	data.solder = getSolderType(istr);
	data.manufacturer = getString(istr);
	data.model = getString(istr);
	data.beta = getDouble(istr);
	data.collector_current = getSIUnit(istr);
	return data;
}

//!   ____  _____  ______ _____         _______ ____  _______     __
//!  / __ \|  __ \|  ____|  __ \     /\|__   __/ __ \|  __ \ \   / /
//! | |  | | |__) | |__  | |__) |   /  \  | | | |  | | |__) \ \_/ /
//! | |  | |  ___/|  __| |  _  /   / /\ \ | | | |  | |  _  / \   /
//! | |__| | |    | |____| | \ \  / ____ \| | | |__| | | \ \  | |
//!  \____/|_|    |______|_|  \_\/_/    \_\_|  \____/|_|  \_\ |_|
//!

bool Tranzystor::operator==(const Komponent& obj){
	if(Komponent::operator!=(obj)) return false;
	const Tranzystor& casted = dynamic_cast<const Tranzystor&>(obj);
	const SIUnit default_si = {-1, ""};
	return (model.empty() || model == casted.model) &&
		(beta == -1 || beta == casted.beta) &&
		(prad_kolektora == default_si || prad_kolektora == casted.prad_kolektora);
	return false;
}
std::ostream& Tranzystor::operator<<(std::ostream& ostr){
	Komponent::operator<<(ostr);
	ostr;
    if(!model.empty()) ostr << ' ' << model;
	else ostr << ' ' << "nieznany";
    ostr  << ' ' << beta << ' ' <<
	prad_kolektora.first << prad_kolektora.second;
	return ostr;
}
void Tranzystor::exportData(std::ostream& os){
	Komponent::exportData(os);
	if(!model.empty()) os << ' ' << model;
	if(beta != -1) os << ' ' << beta << 'x';
	if(prad_kolektora.first != -1) os << ' ' << prad_kolektora.first << prad_kolektora.second << "A";
}