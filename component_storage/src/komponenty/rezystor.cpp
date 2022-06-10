#include "rezystor.h"
#include "others/funkcje.h"
#include "others/manager.h"

//!  _  ______  _   _  _____ _______ _____  _    _ _  _______     _
//! | |/ / __ \| \ | |/ ____|__   __|  __ \| |  | | |/ / ____|   | |  /\
//! | ' / |  | |  \| | (___    | |  | |__) | |  | | ' / |        | | /  \
//! |  <| |  | | . ` |\___ \   | |  |  _  /| |  | |  <| |    _   | |/ /\ \
//! | . \ |__| | |\  |____) |  | |  | | \ \| |__| | . \ |___| |__| / ____ \
//! |_|\_\____/|_| \_|_____/   |_|  |_|  \_\\____/|_|\_\_____\____/_/    \_\
//!

Rezystor::Rezystor(const ResistorParams& data)
	: Komponent(data),
	rezystancja(data.resistance),
	tolerancja(data.tolerance),
	moc(data.power)  {
}
compPtr Rezystor::create(){
	ResistorParams data = getValues();
	return std::make_shared<Rezystor>(data);
}
compPtr Rezystor::create(std::istream& istr){
	ResistorParams data = getValues(istr);
	return std::make_shared<Rezystor>(data);
}

//!  _____   ____  ____ _____ ______ _____            _   _ _____ ______ 
//! |  __ \ / __ \|  _ \_   _|  ____|  __ \     /\   | \ | |_   _|  ____|
//! | |__) | |  | | |_) || | | |__  | |__) |   /  \  |  \| | | | | |__   
//! |  ___/| |  | |  _ < | | |  __| |  _  /   / /\ \ | . ` | | | |  __|  
//! | |    | |__| | |_) || |_| |____| | \ \  / ____ \| |\  |_| |_| |____ 
//! |_|     \____/|____/_____|______|_|  \_\/_/    \_\_| \_|_____|______|
//!                                                                      

ResistorParams Rezystor::getValues() {
	ResistorParams data;
	data.type = ComponentType::Rezystor;
	data.solder = getSolderType("Podaj typ montazu (tht/smt)");
	data.manufacturer = getString("Podaj nazwe producenta");
	Manager mng;
	mng.manufacturer().addProducent(Producent{data.manufacturer, "nieznany"});
	data.resistance = getSIUnit("Podaj rezystancje");
	data.tolerance = getDouble("Podaj tolerancje (w %)");
	data.power = getSIUnit("Podaj moc");
	return data;
}
ResistorParams Rezystor::getValues(std::istream& istr){
	ResistorParams data;
	data.type = ComponentType::Rezystor;
	data.solder = getSolderType(istr);
	data.manufacturer = getString(istr);
	data.resistance = getSIUnit(istr);
	data.tolerance = getDouble(istr);
	data.power = getSIUnit(istr);
	return data;
}

//!   ____  _____  ______ _____         _______ ____  _______     __
//!  / __ \|  __ \|  ____|  __ \     /\|__   __/ __ \|  __ \ \   / /
//! | |  | | |__) | |__  | |__) |   /  \  | | | |  | | |__) \ \_/ /
//! | |  | |  ___/|  __| |  _  /   / /\ \ | | | |  | |  _  / \   /
//! | |__| | |    | |____| | \ \  / ____ \| | | |__| | | \ \  | |
//!  \____/|_|    |______|_|  \_\/_/    \_\_|  \____/|_|  \_\ |_|
//!

bool Rezystor::operator==(const Komponent& obj){
	if(Komponent::operator!=(obj)) return false;
	const Rezystor& casted = dynamic_cast<const Rezystor&>(obj);
	const SIUnit default_si = {-1, ""};
	return (rezystancja == default_si || rezystancja == casted.rezystancja) &&
		(tolerancja == -1 || tolerancja == casted.tolerancja) &&
		(moc == default_si || moc == casted.moc);
	return false;
}
std::ostream& Rezystor::operator<<(std::ostream& ostr){
	Komponent::operator<<(ostr);
	ostr << ' ' << rezystancja.first << rezystancja.second << ' ' <<
	tolerancja << ' ' <<
	moc.first << moc.second;
	return ostr;
}
void Rezystor::exportData(std::ostream& os){
	Komponent::exportData(os);
	if(rezystancja.first != -1) os << ' ' << rezystancja.first << rezystancja.second << "ohm";
	if(tolerancja != -1) os << ' ' << tolerancja << '%';
	if(moc.first != -1) os << ' ' << moc.first << moc.second << "W";
}