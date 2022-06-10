#ifndef REZYSTOR
#define REZYSTOR
#include "komponent.h"

struct ResistorParams : ComponentParams {
	SIUnit resistance;
	double tolerance;
	SIUnit power;
};

class Rezystor : public Komponent {
public:
	//konstrukcja
	Rezystor(const ResistorParams&);
	static compPtr create();
	static compPtr create(std::istream&);
	//operatory
	bool operator==(const Komponent&);
	std::ostream& operator<<(std::ostream&);
	void exportData(std::ostream&) override;
private:
	static ResistorParams getValues();
	static ResistorParams getValues(std::istream&);

	SIUnit rezystancja; //ohm
	double tolerancja; //%
	SIUnit moc; //W
};

#endif