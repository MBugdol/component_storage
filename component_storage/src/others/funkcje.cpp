#include "funkcje.h"
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <algorithm>

//  ____           _____ _____ _____ 
// |  _ \   /\    / ____|_   _/ ____|
// | |_) | /  \  | (___   | || |     
// |  _ < / /\ \  \___ \  | || |     
// | |_) / ____ \ ____) |_| || |____ 
// |____/_/    \_\_____/|_____\_____|
//                                  

int getInt(const std::string& msg, int default_val){
	while(true){
		try{
			std::string input = getString(msg);
			if(input.empty()) return default_val;

			int val = std::stoi(input);
			if(val < 0) {
				std::cout << "Wejscie ujemne - przyjeto wartosc domyslna..." << std::endl;
				return default_val;
			}

			return val;
		}

		catch(std::string msg){
			std::cout << msg << std::endl;
		}
		catch(std::invalid_argument){
			std::cout << "Podano bledne wejscie! Sprobuj ponownie..." << std::endl;
		}
		catch(std::out_of_range){
			std::cout << "Podano zbyt duza liczbe! Sprobuj ponownie..." << std::endl;
		}
	}
}
int getInt(std::istream& istr){
	try{
		std::string input = getString(istr);
		int val = std::stoi(input);
		if(val < 0) return -1;
		return val;
	}
	catch(std::invalid_argument){
		throw std::string{"Oczekiwano liczby calkowitej! Pomijanie komponentu..."};
	}
	catch(std::out_of_range){
		throw std::string{"Liczba jest zbyt duza! Pomijanie komponentu..."};
	}
}
double getDouble(const std::string& msg, double default_val) {
	while(true){
		try{
			std::string input = getString(msg);
			if(input.empty()) return default_val;

			double val = std::stod(input);
			if(val < 0) {
				std::cout << "Wejscie ujemne - przyjeto wartosc domyslna..." << std::endl;
				return default_val;
			}
			
			return val;
		}
		catch(std::invalid_argument){
			std::cout << "Podano bledne wejscie! Sprobuj ponownie..." << std::endl;
		}
		catch(std::out_of_range){
			std::cout << "Podano zbyt duza liczbe! Sprobuj ponownie..." << std::endl;
		}
	}
}
double getDouble(std::istream& istr){
	try{
		std::string input = getString(istr);
		double val = std::stod(input);
		if(val < 0) return -1;
		return val;
	}
	catch(std::invalid_argument){
		throw std::string{"Oczekiwano liczby zmiennoprzecinkowej! Pomijanie komponentu..."};
	}
	catch(std::out_of_range){
		throw std::string{"Liczba jest zbyt duza! Pomijanie komponentu..."};
	}
}

//   _____ _______ _____  _____ _   _  _____ 
//  / ____|__   __|  __ \|_   _| \ | |/ ____|
// | (___    | |  | |__) | | | |  \| | |  __ 
//  \___ \   | |  |  _  /  | | | . ` | | |_ |
//  ____) |  | |  | | \ \ _| |_| |\  | |__| |
// |_____/   |_|  |_|  \_\_____|_| \_|\_____|
//

std::string getString(const std::string& msg, std::string default_val){
	std::cout << msg << ": " ;
	std::string input;
	std::getline(std::cin, input);
	removeWhiteSpace(input);
	if(input.empty()) return default_val; //wartosc domyslna
	return input;
}
std::string getString(std::istream& istr){
	std::string input;
	if(!(istr >> input)) throw std::string("Nie udalo sie pobrac wartosci typu string ze strumienia!");
	if(input == "nieznany") return "";
	return input;
}
std::string convertToString(ComponentType type) {
	std::unordered_map<ComponentType, std::string> convert = {
		{ComponentType::Rezystor, "rezystor"},
		{ComponentType::Kondensator, "kondensator"},
		{ComponentType::Cewka, "cewka"},
		{ComponentType::Tranzystor, "tranzystor"},
		{ComponentType::UkladSc, "ukladscalony"}
	};
	if(convert.find(type) == convert.end()) throw std::string("Nie mozna dokonac konwersji - komponent nie znajduje sie w bazie danych!");
	return convert[type]; 
}
std::string convertToString(SolderType type) {
	std::unordered_map<SolderType, std::string> convert = {
		{SolderType::Undefined, "nieznany"},
		{SolderType::THT, "tht"},
		{SolderType::SMT, "smt"}
	};
	if(convert.find(type) == convert.end()) throw std::string("Nie mozna dokonac konwersji - typ montazu nie znajduje sie w bazie danych!");
	return convert[type]; 
}
inline void removeWhiteSpace(std::string& str){
	str.erase(std::remove_if(str.begin(), str.end(), [](char ch){return std::isspace(ch);}), str.end());
}
inline void convertToLower(std::string& str){
	std::transform(str.begin(), str.end(), str.begin(), [](char ch){return std::tolower(ch);});
}

//   _____ _____ _    _ _   _ _____ _______ 
//  / ____|_   _| |  | | \ | |_   _|__   __|
// | (___   | | | |  | |  \| | | |    | |   
//  \___ \  | | | |  | | . ` | | |    | |   
//  ____) |_| |_| |__| | |\  |_| |_   | |   
// |_____/|_____|\____/|_| \_|_____|  |_|   
//                                          

SIUnit getSIUnit(const std::string& msg, SIUnit default_value){
	while(true){
		try {
			std::string input = getString(msg);
			if(input.empty()) return default_value;
			SIUnit result = convertToSI(input);
			result = standardiseSI(result);
			return result;
		}
		catch(std::string errormsg){
			std::cout << errormsg << std::endl;
		}
	}
}
SIUnit getSIUnit(std::istream& istr){
	try {
		std::string input = getString(istr);
		SIUnit result = convertToSI(input);
		result = standardiseSI(result);
		return result;
	}
	catch(std::string errormsg){
		std::cout << errormsg;
		throw std::string{"Nie udalo sie pobrac komponentu!"};
	}
}
SIUnit convertToSI(const std::string& input){
	std::istringstream iss(input);
	double value;
	std::string unit;
	if(iss >> value) {
		if(value < 0){
			value = -1;
			std::cout << "Podano wartosc ujemna - przyjeto wartosc domyslna!" << std::endl;
		}
		if(iss >> unit)
			return std::make_pair(value, unit);
		else
			return std::make_pair(value, "");
	}		
	else {
		throw std::string("Podano bledne wejscie! Sprobuj ponownie...");
	}
}
SIUnit standardiseSI(SIUnit& SI) {
	std::vector<std::string>prefix_order = {"p", "n", "u", "m", "", "k", "M", "G", "T"};
	double value = SI.first;
	std::string prefix = SI.second;
	auto prefix_pos = std::find(prefix_order.begin(), prefix_order.end(), prefix);
	//sprawdz, czy prefix jest obslugiwany
	if(prefix_pos == prefix_order.end()){
		if(prefix[0] == ',') throw std::string("Do zapisu liczb zmiennoprzecinoowych uzywaj kropki! Sprobuj ponownie...");
		std::string errormsg = "Podany mnoznik (" + prefix + ") nie jest obslugiwany przez program lub nie istnieje! Liste mnoznikow obslugiwanych przez program "
		"znajdziesz w pliku mnozniki.info. Sprobuj ponownie...";
		throw errormsg;
	}
	while(value >= 1000 && prefix_pos < prefix_order.end()-1){
		value /= 1000;
		prefix_pos++;
	}
	while(0 < value && value < 1 && prefix_pos > prefix_order.begin()){
		value *= 1000;
		prefix_pos--;
	}
	return std::make_pair(value, *prefix_pos);
}

//   _____ ____  __  __ _____   ____  _   _ ______ _   _ _______ _________     _______  ______ 
//  / ____/ __ \|  \/  |  __ \ / __ \| \ | |  ____| \ | |__   __|__   __\ \   / /  __ \|  ____|
// | |   | |  | | \  / | |__) | |  | |  \| | |__  |  \| |  | |     | |   \ \_/ /| |__) | |__   
// | |   | |  | | |\/| |  ___/| |  | | . ` |  __| | . ` |  | |     | |    \   / |  ___/|  __|  
// | |___| |__| | |  | | |    | |__| | |\  | |____| |\  |  | |     | |     | |  | |    | |____ 
//  \_____\____/|_|  |_|_|     \____/|_| \_|______|_| \_|  |_|     |_|     |_|  |_|    |______|
//

ComponentType getComponentType(const std::string& msg, ComponentType default_value){
	while(true){
		try {
			std::string input = getString(msg);
			if(input.empty()) return default_value;
			ComponentType result = convertToComponentType(input);
			return result;
		}
		catch(std::string errormsg){
			std::cout << errormsg << std::endl;
		}
	}
}
ComponentType getComponentType(std::istream& istr){
	try{
		std::string input = getString(istr);
		ComponentType result = convertToComponentType(input);
		return result;
	}
	catch(std::string errormsg){
		throw std::string("Bledny typ komponentu! Przechodzenie do kolejnej linii...");
	}
}
ComponentType convertToComponentType(std::string& str) {
	std::unordered_map<std::string, ComponentType> convert = {
		{"nieznany", ComponentType::Undefined},
		{"rezystor", ComponentType::Rezystor},
		{"kondensator", ComponentType::Kondensator},
		{"cewka", ComponentType::Cewka},
		{"tranzystor", ComponentType::Tranzystor},
		{"ukladscalony", ComponentType::UkladSc}
	};
	convertToLower(str);
	if(convert.find(str) == convert.end()) throw std::string("Podano bledny typ komponentu!");
	return convert[str];
}
ComponentType convertToComponentType(int n){
	//obecnie enumerator obsluguje liczby od 1-4 z 0 jako undefined
	if(n < 1 || n > 5) throw std::string("Podano bledny typ komponentu!");
	return ComponentType(n);
}

//   _____  ____  _      _____  ______ _____ _________     _______  ______ 
//  / ____|/ __ \| |    |  __ \|  ____|  __ \__   __\ \   / /  __ \|  ____|
// | (___ | |  | | |    | |  | | |__  | |__) | | |   \ \_/ /| |__) | |__   
//  \___ \| |  | | |    | |  | |  __| |  _  /  | |    \   / |  ___/|  __|  
//  ____) | |__| | |____| |__| | |____| | \ \  | |     | |  | |    | |____ 
// |_____/ \____/|______|_____/|______|_|  \_\ |_|     |_|  |_|    |______|
//                                                                         
                                                                         
SolderType getSolderType(const std::string& msg, SolderType default_value) {
	while(true) {
		try {
			std::string input = getString(msg);
			if(input.empty()) return default_value;
			return convertToSolderType(input);
		}
		catch(std::string errormsg){
			std::cout << errormsg; 
			std::cout << "Sprobuj ponownie..." << std::endl;
		}
	}
}
SolderType getSolderType(std::istream& istr){
	try {
		std::string input = getString(istr);
		return convertToSolderType(input);
	}
	catch(std::string errormsg){
		throw std::string("Bledny typ montazu! Pomijanie komponentu...");
	}
}
SolderType convertToSolderType(std::string& str) {
	std::unordered_map<std::string, SolderType> convert = {
		{"nieznany", SolderType::Undefined},
		{"tht", SolderType::THT},
		{"smt", SolderType::SMT},
		{"smd", SolderType::SMT}
	};
	convertToLower(str);
	if(convert.find(str) == convert.end()) throw std::string("Podano bledny typ montazu! ");
	return convert[str];
}

//  _____  _____   ____  _____  _    _  _____ ______ _   _ _______ 
// |  __ \|  __ \ / __ \|  __ \| |  | |/ ____|  ____| \ | |__   __|
// | |__) | |__) | |  | | |  | | |  | | |    | |__  |  \| |  | |   
// |  ___/|  _  /| |  | | |  | | |  | | |    |  __| | . ` |  | |   
// | |    | | \ \| |__| | |__| | |__| | |____| |____| |\  |  | |   
// |_|    |_|  \_\\____/|_____/ \____/ \_____|______|_| \_|  |_|   
//                                                                 
                                                                 
Producent getProducent(){
	std::string nazwa = getString("Podaj nazwe producenta");
	std::string adres = getString("Podaj adres producenta", "nieznany");
	return Producent(nazwa, adres);
}