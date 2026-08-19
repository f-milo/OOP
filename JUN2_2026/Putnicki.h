#pragma once
#include "Avion.h"
class Putnicki : public Avion
{
private:
	int ukupanBrojSedista;
	int brojNepopunjenihSedista;
	int brojSedistaBiznis;
	double masaTereta;

public:
	Putnicki(const char* _kod, const char* _nazivAvioKompanije, int _ukupanBrojSedista, int _brojNepopunjenihSedista, int _brojSedistaBiznis, double _masaTereta);
	~Putnicki() {};

	void odstampaj(std::ostream& out) const override;

	bool preko95() override;
	double getPopunjenost() override;
};

