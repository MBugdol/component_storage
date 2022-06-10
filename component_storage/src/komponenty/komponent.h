#pragma once
#include <iostream>
#include <memory>
#include "../producenci/producent.h"
class Komponent;

typedef std::shared_ptr<Komponent> compPtr;
typedef std::pair<double, std::string> SIUnit;


enum class ComponentType {
	Undefined = 0,
	Rezystor,
	Kondensator,
	Cewka,
	Tranzystor,
	UkladSc
};
enum class SolderType {
	Undefined = 0,
	THT,
	SMT
};

struct ComponentParams {
	ComponentType type;
	SolderType solder;
	std::string manufacturer;
};

class Komponent {
public:
	//konstrukcja
	Komponent(const ComponentParams&);
	//pobieranie/get
	static ComponentParams getValues();
	std::string getManufacturerName() {return prod;}
	//operatory
	virtual bool operator==(const Komponent&);
	virtual bool operator!=(const Komponent&);
	virtual std::ostream& operator<<(std::ostream&);
	virtual void exportData(std::ostream&);
protected:

	ComponentType rodzaj;
	SolderType montaz;
	std::string prod;
};