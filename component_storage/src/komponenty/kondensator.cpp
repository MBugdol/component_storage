#include "kondensator.h"
#include "../others/funkcje.h"
#include "../others/manager.h"

//!  _  ______  _   _  _____ _______ _____  _    _ _  _______     _
//! | |/ / __ \| \ | |/ ____|__   __|  __ \| |  | | |/ / ____|   | |  /\
//! | ' / |  | |  \| | (___    | |  | |__) | |  | | ' / |        | | /  \
//! |  <| |  | | . ` |\___ \   | |  |  _  /| |  | |  <| |    _   | |/ /\ \
//! | . \ |__| | |\  |____) |  | |  | | \ \| |__| | . \ |___| |__| / ____ \
//! |_|\_\____/|_| \_|_____/   |_|  |_|  \_\\____/|_|\_\_____\____/_/    \_\
//!

Kondensator::Kondensator(const CapacitorParams& data)
    : Komponent(data),
    pojemnosc(data.capacitance),
    tolerancja(data.tolerance),
    napiecie_pracy(data.working_voltage) {
}
compPtr Kondensator::create(){
	CapacitorParams data = getValues();
	return std::make_shared<Kondensator>(data);
}
compPtr Kondensator::create(std::istream& istr){
	CapacitorParams data = getValues(istr);
	return std::make_shared<Kondensator>(data);
}

//!  _____   ____  ____ _____ ______ _____            _   _ _____ ______ 
//! |  __ \ / __ \|  _ \_   _|  ____|  __ \     /\   | \ | |_   _|  ____|
//! | |__) | |  | | |_) || | | |__  | |__) |   /  \  |  \| | | | | |__   
//! |  ___/| |  | |  _ < | | |  __| |  _  /   / /\ \ | . ` | | | |  __|  
//! | |    | |__| | |_) || |_| |____| | \ \  / ____ \| |\  |_| |_| |____ 
//! |_|     \____/|____/_____|______|_|  \_\/_/    \_\_| \_|_____|______|
//!                                                                      

CapacitorParams Kondensator::getValues() {
	CapacitorParams data;
	data.type = ComponentType::Kondensator;
	data.solder = getSolderType("Podaj typ montazu (tht/smt)");
	data.manufacturer = getString("Podaj nazwe producenta");
	Manager mng;
	mng.manufacturer().addProducent(Producent{data.manufacturer, "nieznany"});
	data.capacitance = getSIUnit("Podaj pojemnosc");
	data.tolerance = getDouble("Podaj tolerancje (w %)");
	data.working_voltage = getSIUnit("Podaj napiecie pracy");
	return data;
}
CapacitorParams Kondensator::getValues(std::istream& istr){
	CapacitorParams data;
	data.type = ComponentType::Kondensator;
	data.solder = getSolderType(istr);
	data.manufacturer = getString(istr);
	data.capacitance = getSIUnit(istr);
	data.tolerance = getDouble(istr);
	data.working_voltage = getSIUnit(istr);
	return data;
}

//!   ____  _____  ______ _____         _______ ____  _______     __
//!  / __ \|  __ \|  ____|  __ \     /\|__   __/ __ \|  __ \ \   / /
//! | |  | | |__) | |__  | |__) |   /  \  | | | |  | | |__) \ \_/ /
//! | |  | |  ___/|  __| |  _  /   / /\ \ | | | |  | |  _  / \   /
//! | |__| | |    | |____| | \ \  / ____ \| | | |__| | | \ \  | |
//!  \____/|_|    |______|_|  \_\/_/    \_\_|  \____/|_|  \_\ |_|
//!

bool Kondensator::operator==(const Komponent& obj){
	if(Komponent::operator!=(obj)) return false;
	const Kondensator& casted = dynamic_cast<const Kondensator&>(obj);
	const SIUnit default_si = {-1, ""};
	return (pojemnosc == default_si || pojemnosc == casted.pojemnosc) &&
		(tolerancja == -1 || tolerancja == casted.tolerancja) &&
		(napiecie_pracy == default_si || napiecie_pracy == casted.napiecie_pracy);
	return false;
}
std::ostream& Kondensator::operator<<(std::ostream& ostr){
	Komponent::operator<<(ostr);
	ostr << ' ' << pojemnosc.first << pojemnosc.second << ' ' <<
	tolerancja << ' ' <<
	napiecie_pracy.first << napiecie_pracy.second;
	return ostr;
}
void Kondensator::exportData(std::ostream& os){
	Komponent::exportData(os);
	if(pojemnosc.first != -1) os << ' ' << pojemnosc.first << pojemnosc.second << "F";
	if(tolerancja != -1) os << ' ' << tolerancja << '%';
	if(napiecie_pracy.first != -1) os << ' ' << napiecie_pracy.first << napiecie_pracy.second << "V";
}