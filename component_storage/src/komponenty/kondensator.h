#ifndef KONDENSATOR
#define KONDENSATOR
#include "komponent.h"

struct CapacitorParams : ComponentParams {
    SIUnit capacitance;
    double tolerance;
    SIUnit working_voltage;
};

class Kondensator : public Komponent {
public:
    //konstrukcja
    Kondensator(const CapacitorParams&);
	static compPtr create();
	static compPtr create(std::istream&);
	//operatory
	bool operator==(const Komponent&);
	void saveData(std::ostream&);
	void exportData(std::ostream&) override;
private:
	static CapacitorParams getValues();
	static CapacitorParams getValues(std::istream&);

	SIUnit pojemnosc; //farad
	double tolerancja; //%
	SIUnit napiecie_pracy; //volt
};

#endif