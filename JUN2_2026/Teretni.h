#pragma once
#include "Avion.h"
class Teretni : public Avion
{
private:
	int maksimalniDoletKM;
	double maksTeretT;
	double trenutnaMasaTeretaT;

public:
	Teretni(const char* _kod, const char* _nazivAvioKompanije, int _maksimalniDoletKM, double _maksTeretT, double _trenutnaMasaTeretaT);
	~Teretni() {};

	void odstampaj(std::ostream& out) const override;

	bool preko95() override;
};

