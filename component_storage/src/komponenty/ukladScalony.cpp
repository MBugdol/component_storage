#include "ukladScalony.h"
#include "others/funkcje.h"
#include "others/manager.h"

//  _  ______  _   _  _____ _______ _____  _    _ _  _______     _
// | |/ / __ \| \ | |/ ____|__   __|  __ \| |  | | |/ / ____|   | |  /\
// | ' / |  | |  \| | (___    | |  | |__) | |  | | ' / |        | | /  \
// |  <| |  | | . ` |\___ \   | |  |  _  /| |  | |  <| |    _   | |/ /\ \
// | . \ |__| | |\  |____) |  | |  | | \ \| |__| | . \ |___| |__| / ____ \
// |_|\_\____/|_| \_|_____/   |_|  |_|  \_\\____/|_|\_\_____\____/_/    \_\
//

UkladScalony::UkladScalony(const IntegratedCircuitParams& data)
	: Komponent(data),
	model(data.model),
	piny(data.pin_count),
	napiecie_pracy(data.working_voltage)  {
}
compPtr UkladScalony::create(){
	IntegratedCircuitParams data = getValues();
	return std::make_shared<UkladScalony>(data);
}
compPtr UkladScalony::create(std::istream& istr){
	IntegratedCircuitParams data = getValues(istr);
	return std::make_shared<UkladScalony>(data);
}

//  _____   ____  ____ _____ ______ _____            _   _ _____ ______ 
// |  __ \ / __ \|  _ \_   _|  ____|  __ \     /\   | \ | |_   _|  ____|
// | |__) | |  | | |_) || | | |__  | |__) |   /  \  |  \| | | | | |__   
// |  ___/| |  | |  _ < | | |  __| |  _  /   / /\ \ | . ` | | | |  __|  
// | |    | |__| | |_) || |_| |____| | \ \  / ____ \| |\  |_| |_| |____ 
// |_|     \____/|____/_____|______|_|  \_\/_/    \_\_| \_|_____|______|
//                                                                      

IntegratedCircuitParams UkladScalony::getValues() {
	IntegratedCircuitParams data;
	data.type = ComponentType::UkladSc;
	data.solder = getSolderType("Podaj typ montazu (tht/smt)");
	data.manufacturer = getString("Podaj nazwe producenta");
	data.model = copyToLower(getString("Podaj nazwe modelu"));
	data.pin_count = getInt("Podaj ilosc pinow");
	data.working_voltage = getSIUnit("Podaj napiecie pracy");
	Manager mng;
	mng.manufacturer().addProducent(Producent{data.manufacturer, "nieznany"});
	return data;
}
IntegratedCircuitParams UkladScalony::getValues(std::istream& istr){
	IntegratedCircuitParams data;
	data.type = ComponentType::UkladSc;
	data.solder = getSolderType(istr);
	data.manufacturer = getString(istr);
	data.model = copyToLower(getString(istr));
	data.pin_count = getInt(istr);
	data.working_voltage = getSIUnit(istr);
	Manager mng;
	mng.manufacturer().addProducent(Producent{data.manufacturer, "nieznany"});
	return data;
}

//   ____  _____  ______ _____         _______ ____  _______     __
//  / __ \|  __ \|  ____|  __ \     /\|__   __/ __ \|  __ \ \   / /
// | |  | | |__) | |__  | |__) |   /  \  | | | |  | | |__) \ \_/ /
// | |  | |  ___/|  __| |  _  /   / /\ \ | | | |  | |  _  / \   /
// | |__| | |    | |____| | \ \  / ____ \| | | |__| | | \ \  | |
//  \____/|_|    |______|_|  \_\/_/    \_\_|  \____/|_|  \_\ |_|
//

bool UkladScalony::operator==(const Komponent& obj){
	if(Komponent::operator!=(obj)) return false;
	const UkladScalony& casted = dynamic_cast<const UkladScalony&>(obj);
	const SIUnit default_si = {-1, ""};
	return (model.empty() || model == casted.model) &&
		(piny == -1 || piny == casted.piny) &&
		(napiecie_pracy == default_si || napiecie_pracy == casted.napiecie_pracy);
	return false;
}
void UkladScalony::saveData(std::ostream& ostr){
	Komponent::saveData(ostr);
	ostr;
    if(!model.empty()) ostr << ';' << model;
    else ostr << ';' << "nieznany";
	ostr  << ';' << piny << ';' <<
	napiecie_pracy.first << napiecie_pracy.second << ';';
}
void UkladScalony::exportData(std::ostream& os){
	Komponent::exportData(os);
	if(!model.empty()) os << ' ' << model;
	if(piny != -1) os << ' ' << piny << "pinow";
	if(napiecie_pracy.first != -1) os << ' ' << napiecie_pracy.first << napiecie_pracy.second << "V";
}