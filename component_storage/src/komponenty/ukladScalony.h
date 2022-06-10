#ifndef UKLADSCALONY
#define UKLADSCALONY
#include "komponent.h"

struct IntegratedCircuitParams : ComponentParams {
	std::string model;
	int pin_count;
    SIUnit working_voltage;
};

class UkladScalony : public Komponent {
public:
	//konstrukcja
	UkladScalony(const IntegratedCircuitParams&);
	static compPtr create();
	static compPtr create(std::istream&);
	//operatory
	bool operator==(const Komponent&);
	std::ostream& operator<<(std::ostream&);
	void exportData(std::ostream&) override;
private:
	static IntegratedCircuitParams getValues();
	static IntegratedCircuitParams getValues(std::istream&);

	std::string model; 
	int piny;
    SIUnit napiecie_pracy;
};

#endif