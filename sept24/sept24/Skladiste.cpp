#include "Skladiste.h"

Skladiste::Skladiste(int _maks)
{
	maks = _maks;
	niz = new Pice * [maks];
	tr = 0;
}

Skladiste::~Skladiste()
{
	for (int i = 0; i < tr; i++)
	{
		delete niz[i];
	}
	delete[] niz;
}

void Skladiste::Dodaj(Pice* p)
{
	if (tr < maks)
	{
		niz[tr] = p;
		tr++;
		std::cout << "uspesno" << std::endl;
	}
	else
		std::cout << "neuspesno" << std::endl;

}
