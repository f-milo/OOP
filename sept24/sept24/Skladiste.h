#pragma once
#include <iostream>
#include "Pice.h"

class Skladiste
{
private:
	Pice** niz;
	int tr;
	int maks;

public:
	Skladiste() {};
	Skladiste(int _maks);
	~Skladiste();
	void Dodaj(Pice* p);

	friend std::ostream& operator<<(std::ostream& out, const Skladiste& s);
	
	void Izdvoji(const Pice& p, int brKom);

	void Presipaj(Pice& voda2, Pice& voda1);

	bool DovoljnaKolicina(int kol);

	void VratiNaj(Pice*& piceMin, Pice*& piceMax);
};

