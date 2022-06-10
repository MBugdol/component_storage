#ifndef CEWKA
#define CEWKA
#include "komponent.h"

struct InductorParams : ComponentParams {
	SIUnit inductance;
	double tolerance;
	SIUnit saturation_current;
};

class Cewka : public Komponent {
public:
	//konstrukcja
	Cewka(const InductorParams&);
	static compPtr create();
	static compPtr create(std::istream&);
	//operatory
	bool operator==(const Komponent&);
	void saveData(std::ostream&);
	void exportData(std::ostream&) override;
private:
	static InductorParams getValues();
	static InductorParams getValues(std::istream&);

	SIUnit induktancja; //Henr
	double tolerancja; //%
	SIUnit prad_nasycenia; //Amper
};

#endif