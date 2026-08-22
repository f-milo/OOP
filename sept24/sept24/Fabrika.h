#pragma once
#include <iostream>
#include <fstream>

template <typename T>
class Fabrika
{
private:
	int tr;
	int maks;
	T* niz;

public:
	Fabrika()
	{
		tr = 0;
		maks = 0;
		niz = nullptr;
	}

	Fabrika(int _maks)
	{
		tr = 0;
		maks = _maks;
		niz = new T[maks];
	}

	~Fabrika()
	{
		delete[] niz;
	}

	Fabrika(const Fabrika& f)
	{
		maks = f.maks;
		tr = f.tr;
		niz = new T[maks];
		for (int i = 0; i < tr; i++)
		{
			niz[i] = f.niz[i];
		}
	}

	// Popravljen operator= sa zaštitom od self-assignment-a
	Fabrika& operator=(const Fabrika& f)
	{
		if (this != &f) // NEOPHODNO: Sprečava f1 = f1 da obriše memoriju
		{
			delete[] niz;

			this->maks = f.maks;
			this->tr = f.tr;

			this->niz = new T[maks];
			for (int i = 0; i < tr; i++)
			{
				this->niz[i] = f.niz[i];
			}
		}
		return *this;
	}

	void Dodaj(T pod)
	{
		if (tr == maks)
			throw("PUNA JE KOLEKCIJA");

		int i = 0;
		while (i < tr&& niz[i] <= pod)
		{
			i++;
		}

		for (int j = tr; j > i; j--)
		{
			niz[j] = niz[j - 1];
		}
		tr++;
		niz[i] = pod;
	}

	void Izbaci(T pod)
	{
		for (int i = 0; i < tr; i++)
		{
			if (niz[i] == pod)
			{
				for (int j = i; j < tr - 1; j++)
					niz[j] = niz[j + 1];
				tr--;
				return;
			}
		}
		throw("Elemenat nije pronadjen!!!");
	}

	float UkupnaZapremina()
	{
		float rez = 0;
		for (int i = 0; i < tr; i++)
		{
			rez = rez + niz[i];
		}
		return rez;
	}

	int UkupniBrojVrednost(T _vrednost, float* _ukupnaVrednost)
	{
		*_ukupnaVrednost = 0;
		int rez = 0;
		for (int i = 0; i < tr; i++)
		{
			if (niz[i] == _vrednost)
			{
				*_ukupnaVrednost = *_ukupnaVrednost + niz[i];
				rez++;
			}
		}
		return rez;
	}

	int NajmanjeAmbalaza(float _vrednost)
	{
		int i = tr - 1;
		float ukupna = 0;
		int br = 0;
		while (i >= 0)
		{
			br++;
			ukupna = ukupna + niz[i];
			i--;
			if (ukupna >= _vrednost)
				return br;
		}
		return 0;
	}

	void Sacuvaj(const char* fname) const
	{
		std::ofstream out(fname);
		if (!out.is_open())
			throw("Greska kod upisa");

		out << this->maks << std::endl;
		out << this->tr << std::endl;

		for (int i = 0; i < tr; i++)
		{
			out << niz[i] << std::endl;
		}
	}

	void Ucitaj(const char* fname)
	{
		std::ifstream in(fname);
		if (!in.is_open())
			throw("Greska kod ucitavanja");

		delete[] niz;

		int ucitanimaks = 0;
		in >> ucitanimaks;

		niz = new T[ucitanimaks];
		maks = ucitanimaks;

		in >> tr;
		for (int i = 0; i < tr; i++)
		{
			in >> niz[i];
		}
	}

	friend std::ostream& operator<<(std::ostream& out, const Fabrika& f)
	{
		out << f.maks << std::endl;
		out << f.tr << std::endl;
		for (int i = 0; i < f.tr; i++)
		{
			out << f.niz[i] << " | ";
		}
		out << std::endl;
		return out;
	}
};