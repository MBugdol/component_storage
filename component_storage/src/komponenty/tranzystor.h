#ifndef TRANZYSTOR
#define TRANZYSTOR
#include "komponent.h"

struct TransistorParams : ComponentParams {
	std::string model;
	double beta;
	SIUnit collector_current;
};

class Tranzystor : public Komponent {
public:
	//konstrukcja
	Tranzystor(const TransistorParams&);
	static compPtr create();
	static compPtr create(std::istream&);
	//operatory
	bool operator==(const Komponent&);
	std::ostream& operator<<(std::ostream&);
	void exportData(std::ostream&) override;
private:
	static TransistorParams getValues();
	static TransistorParams getValues(std::istream&);

    std::string model;
	double beta; //mnoznik x
	SIUnit prad_kolektora; //A
};

#endif