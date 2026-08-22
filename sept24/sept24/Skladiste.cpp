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
	for (int i = 0; i < tr; i++)
	{
		if (*niz[i] == *p)
		{
			niz[i]->dodajBrojAmbalaza(1);
			delete p;
			return;
		}
	}
	if (tr < maks)
	{
		niz[tr] = p;
		tr++;
		std::cout << "uspesno" << std::endl;
		return;
	}
	else
		std::cout << "neuspesno" << std::endl;
	return;

}

void Skladiste::Izdvoji(const Pice & p, int brKom)
{
	for (int i = 0; i < tr; i++)
	{
		if (*niz[i] == p)//operator koji uporedjuje *p sa *p
		{
			std::cout << "metoda radi..." << std::endl;

			if (niz[i]->getBrojAmbalaza() > brKom)
			{

				niz[i]->dodajBrojAmbalaza(-brKom);
				std::cout << "Uspesno uzeto " << brKom << " pica iz lagera." << std::endl;
				
				return;
			}
			else if (niz[i]->getBrojAmbalaza() == brKom)
			{
				niz[i]->dodajBrojAmbalaza(-brKom);
				delete niz[i];
				std::cout << "Uspesno uzeto " << brKom << " pica iz lagera." << std::endl;
				std::cout << "REZERVE SU PRAZNE" << std::endl;

				for (int j = i; j < tr-1; j++)
				{
					niz[j] = niz[j + 1];
					//shiftujrmo ostala pica;
				}
				tr--;
				return;
			}
			else
			{
				std::cout << "NEMA DOVOLJNO PICA U LAGERU" << std::endl;
				return;
			}


		}
	}
}

std::ostream& operator<<(std::ostream& out, const Skladiste& s)
{
	out << "Maksimalni kapacitet: " << s.maks << std::endl;
	out << "Trenutna popunjenost: " << s.tr << std::endl;
	for (int i = 0; i < s.tr; i++)
	{
		out << i << ". Pice u Lageru: " << std::endl;
		out << *s.niz[i] << std::endl;
		out << std::endl << std::endl;
	}
	return out;
}
