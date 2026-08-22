#include "Skladiste.h"
#include "Voda.h"
#include "Sok.h"

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
				//niz[i]->dodajBrojAmbalaza(-brKom); //ne mora jer kao brisemo, ali logicki bi trebalo ovako, not a big deal verovatno... (nepotrebna komplikacija)
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

void Skladiste::Presipaj(Pice& voda2, Pice& voda1)
{
	double KolTecnosti = voda2.getBrojAmbalaza() * voda2.getZapremina();

	if (KolTecnosti == 0 || KolTecnosti < voda1.getZapremina())
		return;//ne moze posto ima premalo tecnosti i za jednu flasu...

	int brNovihAMB = (int)(KolTecnosti / voda1.getZapremina());

	for (int i = 0; i < tr; i++)
	{
		if (*niz[i] == voda2)
		{
			delete niz[i];

			//shiftovanje
			for(int j=i; j<tr-1; j++)
			{
				niz[j] = niz[j + 1];
			}
			tr--;
			break;
		}
	}

	for (int i = 0; i < tr; i++)
	{
		if (*niz[i] == voda1)
		{
			niz[i]->dodajBrojAmbalaza(brNovihAMB);
			return;
		}
	}
	//nema nijedne voda1 i mora pravimo novo u lager
	Pice* NovoPice = new Voda(voda1.getZapremina());
	NovoPice->dodajBrojAmbalaza(brNovihAMB- 1);
	this->Dodaj(NovoPice);
	
}

bool Skladiste::DovoljnaKolicina(int kol)
{
	double ukupnoTecnosti = 0;
	for (int i = 0; i < tr; i++)
	{
		ukupnoTecnosti += niz[i]->getZapremina() * niz[i]->getBrojAmbalaza();
	}
	if (ukupnoTecnosti >= kol)
		return true;

	return false;
}

void Skladiste::VratiNaj(Pice*& piceMin, Pice*& piceMax)
{
	if (tr == 0)
	{
		piceMin = nullptr;
		piceMax = nullptr;
		return;
	}

	double maks = -1;
	double min = niz[0]->getBrojAmbalaza() * niz[0]->getZapremina();
	int maksind, minind;
	for (int i = 0; i < tr; i++)
	{
		double trvr = niz[i]->getBrojAmbalaza() * niz[i]->getZapremina();
		if (trvr > maks)
			maksind = i;
		if (trvr < min)
			minind = i;
	}
	piceMin = niz[minind];
	piceMax = niz[maksind];
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
