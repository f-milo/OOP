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
	Kolekcija()
	{

	}

	Kolekcija(int _maks)
	{
		niz = new T[_maks];
		maks = _maks;
	}

	~Kolekcija()
	{
		delete[] niz;
	}
	// int getVal()
	//?

	void DodajPodatak(T _pod)
	{
		if (tr >= maks)
			throw("Niz je napunjen");
		niz[tr] = _pod;
		tr++;
		std::cout << "Uspesno dodato" << tr << std::endl;
	}

	void Obrisi(int indeks)
	{
		if (indeks < 0 || indeks >= tr) // tr je int, ne mora...
			return;
		
		
		
	
		
		for (int i = indeks; i < tr-1; i++)
		{
			niz[i] = niz[i + 1]; //operator =
		}
		tr--;
	}

	float OdrediProsek()
	{
		float rez = 0;

		if (tr == 0) //ako je prazan nema svrhe da se ista radi...
			return 0;

		for (int i = 0; i < tr; i++)
		{
			rez = rez + niz[i]; //oeprator +
		}


		return rez/tr;
	}


	T& NajveciPodatak()
	{
		if (niz != nullptr)
		{

		int maksIndeks = 0;

		for (int i = 0; i < tr; i++)
		{
			if (niz[i] > niz[maksIndeks])//operaotr >
			{
				maksIndeks = i;
			}
		}

		return niz[maksIndeks];
		}
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



	void Ucitaj(const char* fname)
	{
		std::ifstream in(fname);

		if (!in.is_open())
			throw("FAJL NIJE ORVOREN ZA CITANJE ");
		int nmaks = -1;
		int ntr = -1;

		in >> nmaks;
		in >> ntr;




		if (niz != nullptr)
			delete[] niz;

		maks = nmaks;
		niz = new T[maks];
		tr = 0;

		T temp;
		for (int i = 0; i < ntr; i++)
		{
			in >> temp;     // operator>>
			DodajPodatak(temp);
		}

	}

	friend std::ostream& operator<<(std::ostream& out, const Kolekcija & k)
	{
		out << k.maks <<std::endl;
		out << k.tr << std::endl;
		for (int i = 0; i < k.tr; i++)
		{
			out << k.niz[i] << std::endl;
		}
		return out;
	}

	Kolekcija& operator=(const Kolekcija& k)
	{
		if (this == &k)
			return *this;
		maks = k.maks;
		tr = k.tr;
		delete[] niz; //zasto?


			//objasnjenje:
			/*
			
			Pre dodele: Objekat A već ima svoj pokazivač niz koji pokazuje na dinamičku memoriju od 10 elemenata (koju je napravio njegov konstruktor na početku).

Ako NE staviš delete[] niz;:
Kada napišeš A.niz = new int[20], pokazivač u A dobija novu adresu na RAM-u. Stara adresa (onih 10 elemenata) se zaboravlja, ali ta memorija ostaje zauzeta na računaru! Program više ne može da joj pristupi niti da je oslobodi – napravio si curenje memorije (memory leak).

Zato mora delete[] niz;:
Pre nego što u A dodeliš novi niz veličine 20, moraš prvo osloboditi onih starih 10 elemenata koje je A nosio sa sobom.
			
			
			*/



		niz = new T[maks];
		for (int i = 0; i < tr; i++)
		{
			niz[i] = k.niz[i];
		}
		return *this;
	}
		
	
	Kolekcija operator+(const Kolekcija& k)
	{
		int vecitr = 0;
		int manjitr = 0;
		int vecimaks = 0;

		if (k.tr > tr)
		{
			vecitr = k.tr;
			manjitr = tr;
		}
		else
		{
			vecitr = tr;
			manjitr = k.tr;
		}

		if (k.maks > maks)
			vecimaks = k.maks;
		else
			vecimaks = maks;


		Kolekcija k1(vecimaks);
		k1.tr = vecitr;


		for (int i = 0; i < vecitr; i++)
		{
			if (vecitr == k.tr)
				k1.niz[i] = k.niz[i];
			else
				k1.niz[i] = niz[i];
		}

		for (int i = 0; i < manjitr; i++)
		{
			if (manjitr == k.tr)
				k1.niz[i] = k1.niz[i] + k.niz[i];
			else
				k1.niz[i] = k1.niz[i] + niz[i];
		}
		return k1;
	}
		
		//bool operator>(const Kolekcija& k1) const //prvi parametar je this//drgui je k1
		//{
		//	if (this.niz[i].getVal() > k1.niz[i].getVal())
		//		return true;
		//	else
		//		return false;
		//}

	//friend std::istream& operator>>(std::istream& in, Kolekcija& k)
	//{
	//	in >> k.maks >> k.tr;
	//	
	//	for (int i = 0; i < k.tr; i++)
	//	{
	//		in >> k.niz[i];
	//	}

	//	return in;
	//}


	friend std::istream& operator>>(std::istream& in, Kolekcija& k)
	{
		int nmaks, ntr;
		if (in >> nmaks >> ntr)
		{
			delete[] k.niz;
			k.maks = nmaks;
			k.tr = 0; // OBAVEZNO reset na 0 pre ucitavanja!
			k.niz = new T[k.maks];

			T temp;
			for (int i = 0; i < ntr; i++)
			{
				in >> temp;
				k.DodajPodatak(temp);
			}
		}
		return in;
	}



};
