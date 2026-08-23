#pragma once
#include <iostream>
#include <fstream>

template <typename Type>
class Kolekcija
{
private:
	Type* niz;
	int tr;
	int maks;

public:
	Kolekcija(int _maks)
	{
		niz = new Type[_maks];
		maks = _maks;
		tr = 0;
	}
	~Kolekcija()
	{
		delete[] niz;
	}

	void DodajPodatak(Type pod)
	{
		if (tr >= maks)
			throw("ne mogu da dodam, prepun je niz!");

		niz[tr] = pod; //operator Type = Type
		tr++;
	}
	friend std::ostream& operator<<(std::ostream& out, const Kolekcija& k)
	{
		out << k.maks << std::endl;
		out << k.tr << std::endl;
		for (int i = 0; i < k.tr; i++)
		{
			out << k.niz[i] << std::endl;
		}
		return out;
	}

	friend std::istream& operator>>(std::istream& in, Kolekcija& k)
	{
		in >> k.maks;
		in >> k.tr;
		delete[] k.niz;
		k.niz = nullptr;
		k.niz = new Type[k.maks];
		for (int i = 0; i < k.tr; i++)
		{
			in >> k.niz[i];
		}
		return in;
	}

	void Obrisi(int indeks)
	{
		if (indeks >= tr || indeks < 0)
			throw("ne mogu da obrisem sa te pozicije, jer nema te pozicije");
		
		for (int i = indeks; i < tr - 1; i++)
		{
			niz[i] = niz[i + 1]; //operator Type = Type
		}
		tr--;

	}

	float OdrediProsek()
	{
		float rez = 0;
		for (int i = 0; i < tr; i++)
		{
			rez = rez + niz[i];  //operator float+Type

		}
		return rez/tr;
	}
	
	Type& NajveciPodatak()
	{
		int maksind = 0;
		for (int i = 0; i < tr; i++)
		{
			if (niz[maksind] < niz[i])//operator Type < Type
			{
				maksind = i;
			}
		}
		return niz[maksind];
	}

	void Sacuvaj(const char* fname)
	{
		std::ofstream out(fname);
		if (!out)
			throw("Greska kod otvaranja fajla za save!");

		out << *this;
	}
	void Ucitaj(const char* fname)
	{
		std::ifstream in(fname);
		if (!in)
			throw("Greska kod otvaranja fajla za load!");

		in >> *this;
		
	}
};