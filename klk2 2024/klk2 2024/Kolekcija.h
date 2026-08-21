#pragma once
#include <iostream>

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
		if(niz == nullptr)
		int maks = niz[0];

		for (int i = 0; i < tr; i++)
		{

		}
	}
};
