#pragma once
#include <iostream>
#include <fstream>

template <typename T>
//gde god je float tu je T
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
			niz[i] = f.niz[i]; //operator = ???
		}
	}
	//неопадајући редослед по запремини. Уколико је колекција пуна пријавити проблем.
	void Dodaj(T pod)// problem mi je, ne znam kada je float a kada je T??? //kaze uvek je T u template class
	{
		if (tr == maks)
			throw("PUNA JE KOLEKCIJA");

		int i = 0;
		while (i < tr && niz[i] <= pod)
		{
			i++;
		}
		if (i == tr)
		{
			tr++;
			niz[i] = pod;
			//dodaje se na kraj;
			//inace na niz[i]
		}
		else
		{
			for (int j =tr; j > i; j--)
			{
				niz[j] = niz[j - 1];
			}
			tr++;
			niz[i] = pod;
		}
	}


	friend std::ostream& operator<<(std::ostream& out, const Fabrika& f)
	{
		out << f.maks << f.tr << std::endl;
		for (int i = 0; i < f.tr; i++)
		{
			out << f.niz[i] << " | ";
		}
		out<<std::endl;
		return out;
	}

	void Izbaci(T pod)
	{
		//for (int i = 0; i < tr; i++)
		//{
		//	if (niz[i] < pod) //operator <
		//	{
		//		tr++;
		//		for (int j = tr; j > i; j--)
		//			niz[j] = niz[j - 1];
		//		niz[i] = pod;
		//		break;
		//	}
		//}

		for (int i = 0; i < tr; i++)
		{
			if (niz[i] == pod) //operator ==
			{
				for (int j = i; j<tr-1; j++)
					niz[j] = niz[j +1];
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
			rez= rez+ niz[i];//oeprator + operator =
		}
		return rez;
	}
	int vrednost = 1; float ukupnaVrednost = 0;
	int UkupniBrojVrednost(T _vrednost, float* _ukupnaVrednost)
	{
		//nadji mi sve elemente koji imaju vrednost _vrednost i saberi ih u _ukupnaVrednost
		//vrati koliko komada ima takvih koji odgocaraju.
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
		//posto najmanje ambalaza, krecemo od pozadi, jer su tu najvece;
		int i = tr-1;
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
		ofstream out(fname);
		if (out == nullptr)
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


		ifstream in(fname);
		if (!in) //!in.is_open()
			throw("Greska kod upisa");
		int ucitanimaks = 0;
		in >> ucitanimaks;

		delete[] niz;
		niz = nullptr;
		niz = new T[ucitanimaks];
		maks = ucitanimaks; //verovatno preko kontruktora vec raid;

		in >> tr;
		for (int i = 0; i < tr; i++)
		{
			in >> niz[i];
		}
	}
};