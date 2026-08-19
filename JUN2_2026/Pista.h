#pragma once
#include "Avion.h"

class Pista
{
private:
	Avion** niz;
	int tr;
	int maks;

public:
	Pista(int size);
	~Pista();
	void stampaj(std::ostream& f) const;
	void Dodaj(Avion* a);
	void SacuvajUFajl(const char* fname) const;

	friend std::ostream& operator<<(std::ostream& out, const Pista& p);

	int PopunjeniPreko95();

	void ReorganizujAvioneNaPisti();

};

