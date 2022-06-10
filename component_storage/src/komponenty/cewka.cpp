#include "cewka.h"
#include "others/funkcje.h"
#include "others/manager.h"

//!  _  ______  _   _  _____ _______ _____  _    _ _  _______     _
//! | |/ / __ \| \ | |/ ____|__   __|  __ \| |  | | |/ / ____|   | |  /\
//! | ' / |  | |  \| | (___    | |  | |__) | |  | | ' / |        | | /  \
//! |  <| |  | | . ` |\___ \   | |  |  _  /| |  | |  <| |    _   | |/ /\ \
//! | . \ |__| | |\  |____) |  | |  | | \ \| |__| | . \ |___| |__| / ____ \
//! |_|\_\____/|_| \_|_____/   |_|  |_|  \_\\____/|_|\_\_____\____/_/    \_\
//!

Cewka::Cewka(const InductorParams& data)
	: Komponent(data),
	induktancja(data.inductance),
	tolerancja(data.tolerance),
	prad_nasycenia(data.saturation_current) {
}
compPtr Cewka::create(){
	InductorParams data = getValues();
	return std::make_shared<Cewka>(data);
}
compPtr Cewka::create(std::istream& istr){
	InductorParams data = getValues(istr);
	return std::make_shared<Cewka>(data);
}

//!  _____   ____  ____ _____ ______ _____            _   _ _____ ______ 
//! |  __ \ / __ \|  _ \_   _|  ____|  __ \     /\   | \ | |_   _|  ____|
//! | |__) | |  | | |_) || | | |__  | |__) |   /  \  |  \| | | | | |__   
//! |  ___/| |  | |  _ < | | |  __| |  _  /   / /\ \ | . ` | | | |  __|  
//! | |    | |__| | |_) || |_| |____| | \ \  / ____ \| |\  |_| |_| |____ 
//! |_|     \____/|____/_____|______|_|  \_\/_/    \_\_| \_|_____|______|
//!                                                                      

InductorParams Cewka::getValues() {
	InductorParams data;
	data.type = ComponentType::Cewka;
	data.solder = getSolderType("Podaj typ montazu (tht/smt)");
	data.manufacturer = getString("Podaj nazwe producenta");
	Manager mng;
	mng.manufacturer().addProducent(Producent{data.manufacturer, "nieznany"});
	data.inductance = getSIUnit("Podaj induktancje");
	data.tolerance = getDouble("Podaj tolerancje (w %)");
	data.saturation_current = getSIUnit("Podaj wartosc pradu nasycenia");
	return data;
}
InductorParams Cewka::getValues(std::istream& istr){
	InductorParams data;
	data.type = ComponentType::Cewka;
	data.solder = getSolderType(istr);
	data.manufacturer = getString(istr);
	data.inductance = getSIUnit(istr);
	data.tolerance = getDouble(istr);
	data.saturation_current = getSIUnit(istr);
	return data;
}

//!   ____  _____  ______ _____         _______ ____  _______     __
//!  / __ \|  __ \|  ____|  __ \     /\|__   __/ __ \|  __ \ \   / /
//! | |  | | |__) | |__  | |__) |   /  \  | | | |  | | |__) \ \_/ /
//! | |  | |  ___/|  __| |  _  /   / /\ \ | | | |  | |  _  / \   /
//! | |__| | |    | |____| | \ \  / ____ \| | | |__| | | \ \  | |
//!  \____/|_|    |______|_|  \_\/_/    \_\_|  \____/|_|  \_\ |_|
//!

bool Cewka::operator==(const Komponent& obj){
	if(Komponent::operator!=(obj)) return false;
	const Cewka& casted = dynamic_cast<const Cewka&>(obj);
	const SIUnit default_si = {-1, ""};
	return (induktancja == default_si || induktancja == casted.induktancja) &&
		(tolerancja == -1 || tolerancja == casted.tolerancja) &&
		(prad_nasycenia == default_si || prad_nasycenia == casted.prad_nasycenia);
	return false;
}
std::ostream& Cewka::operator<<(std::ostream& ostr){
	Komponent::operator<<(ostr);
	ostr << ' ' << induktancja.first << induktancja.second << ' ' <<
	tolerancja << ' ' <<
	prad_nasycenia.first << prad_nasycenia.second;
	return ostr;
}
void Cewka::exportData(std::ostream& os){
	Komponent::exportData(os);
	if(induktancja.first != -1) os << ' ' << induktancja.first << induktancja.second << "H";
	if(tolerancja != -1) os << ' ' << tolerancja << '%';
	if(prad_nasycenia.first != -1) os << ' ' << prad_nasycenia.first << prad_nasycenia.second << "A";
}