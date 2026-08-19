#include "Pista.h"
#include <fstream>
void Pista::stampaj(std::ostream& f) const
{
	f << "Stampanje piste" << std::endl;
	f << "Maksimalan broj aviona na pisti: " << this->maks << std::endl;
	f << "Trenutni broj aviona na pisti: " << this->tr << std::endl;
	f << "Stampa aviona koji su na pisti: " << std::endl << std::endl;
	for (int i = 0; i < tr; i++)
	{
		f << i << ". Avion:" << std::endl;
		//niz[i]->odstampaj(f); // treba se pozove operator << iz avion, koji ce da odstampa i child detalje
		f << *niz[i];
		f << std::endl;
	}
}
Pista::Pista(int size)
{
	niz = new Avion * [size];
	tr = 0;
	maks = size;
}

Pista::~Pista()
{
	for (int i = 0; i < tr; i++)
	{
		delete niz[i];
	}
	delete[] niz;
}

void Pista::Dodaj(Avion* a)
{
	if (tr < maks)
	{
		std::cout << "dodato" << std::endl;
		niz[tr] = a;
		tr++;
	}
	else
	{
		std::cout << "Neuspesno, popunjeno je!" << std::endl;
	}
}

void Pista::SacuvajUFajl(const char* fname) const
{
	//std::ofstream f(fname, std::ios::out);
	std::ofstream f(fname); //isto je kao i gore;
	stampaj(f);
}

int Pista::PopunjeniPreko95()
{
	int br = 0;
	for (int i = 0; i < tr; i++)
	{
		if (niz[i]->preko95())
		{
			br++;
		}
	}
	return br;
}

void Pista::ReorganizujAvioneNaPisti()
{
	Avion* pom = nullptr;

	for (int i = 0; i < tr; i++)
	{
		for (int j = i; j < tr; j++)
		{
			if (niz[i]->getPopunjenost() < niz[j]->getPopunjenost())
			{
				pom = niz[i];
				niz[i] = niz[j];
				niz[j] = pom;
			}
		}
	}
}

char* Pista::AvioKompanijaSaNajvecimStepenomPopunjenostiKapaciteta()
{
	return nullptr;
}


std::ostream& operator<<(std::ostream& out, const Pista& p)
{
	p.stampaj(out);

	return out;
}
