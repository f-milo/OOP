#pragma once
#include<iostream>
#include <fstream>

template<typename Type>

class Fabrika
{
private:
	Type* niz;
	int tr;
	int maks;

public:
	Fabrika(int _maks)
	{
		niz = new Type[_maks];
		maks = _maks;
		tr = 0;
	}
	/*
	Могуће је додавање новог пића у колекцију
	која представља фабрику,
	али је неопходно да она
	остане уређена у неопадајући
	редослед по запремини.
	Уколико је колекција пуна пријавити
	проблем.
	*/
	void Dodaj(Type pod)
	{
		if (tr >= maks)
			throw ("Niz je pun!");
		for (int i = 0; i < tr; i++)
		{
			if (niz[i] >= pod) //operator >= type type
			{
				for (int j = tr; j > i; j--)
				{
					niz[j] = niz[j-1];
				}
				niz[i] = pod;
				tr++;
				return;
			}
		}
		niz[tr] = pod;
		tr++;
	}
	friend std::ostream& operator<<(std::ostream& out, const Fabrika& f)
	{
		out << f.maks << std::endl;
		out << f.tr << std::endl;
		for (int i = 0; i < f.tr; i++)
		{
			out << f.niz[i] << std::endl;
		}
		return out;
	}
	void Izbaci(const Type& pod)
	{
		int i = 0;
		for (i; i < tr; i++)
		{
			if (niz[i] == pod) //type == type
			{
				//delete niz[i];
				for (int j = i; j < tr-1; j++)
				{
					niz[j] = niz[j + 1]; //operator type=type
				}
				tr--;
				break;
			}
		}
	}

	//ukupna V pica
	float Ukupno()
	{
		float rez = 0;
		for (int i = 0; i < tr; i++)
		{
			rez = rez + niz[i];
		}
		return rez;
	}
	int UkupniBrojVrednost(Type _vrednost, float* _ukupnaVrednost)
	{
		int rez = 0;
		for (int i = 0; i < tr; i++)
		{
			if (niz[i] == _vrednost)
			{
				rez++;
				*_ukupnaVrednost = *_ukupnaVrednost + niz[i];
			}
		}
			return rez;
		//tekst nije najjasniji sta se trazi kako...
	}
	int NajmanjeAmbalaza(float broj)
	{
		float zbir=0;
		int br = 0;
		for (int i = tr; i > 0; i--)
		{
			if (zbir >= broj) //>=
			{
				return br;
			}
			zbir = zbir + niz[i];// float+Type
			br++;
		}

		if (zbir >= broj) //>=
		{
			return br;
		}
		return 0;
	}

	void Sacuvaj(const char* fname)
	{
		std::ofstream out(fname);
		if (!out)
			throw("Sacuvaj tok nije lepo otvoren!");

		out << maks << std::endl;
		out << tr << std::endl;
		for (int i = 0; i < tr; i++)
		{
			out << niz[i] << std::endl; //<<
		}
	}

	void Ucitaj(const char* fname)
	{
		std::ifstream in(fname);
		if (!in)
			throw("Greska kod ifstream Ucitaj fja");

		in >> this->maks;
		in >> this->tr;
		for (int i = 0; i < tr; i++)
		{
			in >> niz[i]; //>> operator
		}
	}


};