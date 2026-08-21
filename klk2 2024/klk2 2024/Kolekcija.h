#pragma once
#include <iostream>
#include <fstream> //moraaaaa
template<typename T>

class Kolekcija
{
private:
	T* niz = nullptr;
	int maks=0;

	int tr=0;

public:
	Kolekcija(int _maks)
	{
		niz = new T[_maks];
	}
	void DodajPodatak(int _pod)
	{
		niz[tr] = _pod;
		tr++;
		std::cout << "Uspesno dodato" << tr << std::endl;
	}

	friend std::ostream& operator<<(std::ostream& out, Kolekcija& k)
	{
		for (int i = 0; i < k.tr; i++)
		{
			out << i << ". EL NIZA: " << k.niz[i] << std::endl;

		}
		return out;
	}
	void Obrisi(int indeks)
	{
		if (indeks > tr)
			return;
		
		
		
		tr--;
		
		for (int i = indeks; i < tr; i++)
		{
			niz[i] = niz[i + 1];
		}
	}

	float OdrediProsek()
	{
		float rez = 0;

		for (int i = 0; i < tr; i++)
		{
			rez += niz[i];
		}
		return rez/tr;
	}


	int NajveciPodatak()
	{
		if (niz == nullptr)
			return 0;

		int maks = niz[0];

		for (int i = 0; i < tr; i++)
		{
			if (niz[i] > maks)
			{
				maks = niz[i];
			}
		}

		return maks;
	}

	void Sacuvaj(const char* fname)
	{
		std::ofstream out(fname);
		if (!out.is_open())
		{
			return;
		}

		//out << tr << std::endl;
		//out << maks << std::endl;

		//for (int i = 0; i < tr; i++)
		//{
		//	out << niz[i];
		//}

		out << *this;
		std::cout << "Uspesno sacuvano! " << std::endl;

		/*
		
		U kontekstu tvoje funkcije, *this označava sam objekat kolekcije nad kojim je pozvana metoda Sacuvaj.

		1. Šta je this, a šta *this?
		this je skriveni pokazivač koji svaka metoda klase ima. On pokazuje na trenutnu adresu objekta u memoriji (npr. adresa tvoje kolekcijaA).

		*this je dederferencirani pokazivač, što znači da predstavlja sam objekat (stvarnu vrednost/instancu kolekcije, a ne njenu adresu).

		2. Kako C++ tumači liniju out << *this;?
		Kada kompajler vidi operator << između objekta toka (out koji je tipa std::ofstream) i tvoje kolekcije (*this koja je tipa Kolekcija<T>), on potraži odgovarajuću funkciju za preopterećenje operatora.

		On tu liniju koda u pozadini pretvara u ovaj poziv funkcije:

		C++
		operator<<(out, *this);
		To znači da se automatski poziva tvoj friend operator<< koji si prethodno napisao u Kolekcija.h:
		
		*/
	}
};
