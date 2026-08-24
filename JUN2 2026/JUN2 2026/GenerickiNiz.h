#pragma once

#include <iostream>
#include <fstream>

template<typename Type, int N=10>

class GenerickiNiz
{
private:
	Type* niz;
	int brel;

public:
	GenerickiNiz()
	{
		brel = N;
		niz = new Type[brel];
	}
	GenerickiNiz(int br)
	{
		brel = br;
		if (brel == 0)
			niz = nullptr;
		else
			niz = new Type[brel];
	}
	~GenerickiNiz()
	{
		delete[] niz;
	}
	GenerickiNiz(const GenerickiNiz& drugi)
	{
		brel = drugi.brel;
		niz = new Type[drugi.brel];
		for (int i = 0; i < drugi.brel; i++)
		{
			niz[i] = drugi.niz[i];
		}
	}
	GenerickiNiz& operator=(const GenerickiNiz& drugi)
	{
		brel = drugi.brel;

		delete[] niz;
		niz = nullptr;
		niz = new Type[brel];

		for (int i = 0; i < brel; i++)
		{
			niz[i] = drugi.niz[i];
		}

		return *this;
	}
	friend std::ostream& operator<<(std::ostream& out, GenerickiNiz& g)
	{
		out << g.brel << std::endl;

		for (int i = 0; i < g.brel; i++)
		{
			out << g.niz[i] << std::endl;
		}
		return out;
	}
	friend std::istream& operator>>(std::istream& in, GenerickiNiz& g)
	{
		in >> g.brel;

		for (int i = 0; i < g.brel; i++)
		{
			in >> g.niz[i];
		}
		return in;
	}
	GenerickiNiz<Type> operator+(const GenerickiNiz<Type, N>&g) const
	{
		if (brel != g.brel)
			throw("Nizovi nisu iste duz!");
		int  vecibrel = 0, manjibrel=0;

		if (brel > g.brel)
		{
			vecibrel = this->brel;
			manjibrel = g.brel;
		}
		else
		{
			vecibrel = g.brel;
			manjibrel = brel;
		}


		GenerickiNiz<Type> rezNiz = new GenerickiNiz(vecibrel);

		for (int i = 0; i < manjibrel; i++)
		{
			rezNiz.niz[i] = niz[i] + g.niz[i];
		}
		return rezNiz;

	}

	Type& Max()
	{
		int maksind = 0;
		for (int i = 1; i < brel; i++)
		{
			if (niz[i] > niz[maksind])
			{
				maksind = i;
			}
		}
		return niz[maksind];
	}
	void Sort()
	{
		//u rastucem redosledu...
		for (int i = 0; i < brel; i++)
		{
			for (int j = i; j < brel; j++)
			{
				if (niz[i] > niz[j])
				{
					Type tmp = niz[i];
					niz[i] = niz[j];
					niz[j] = tmp;
				}
			}
		}
	}

	void SnimiUFajl(const char* fname)
	{
		std::ofstream out(fname);
		if (!out)
			return;

		out << *this;
	}

};



