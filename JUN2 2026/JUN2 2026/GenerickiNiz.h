#pragma once
#include <iostream>
#include <fstream>

template<typename T, int vel=10> //10 je default val, da bi mogli da pozivamo i GenNiz<jedan arg>

class GenerickiNiz
{
private:
	T niz[vel];
	int tr;

public:
	GenerickiNiz()
	{
		tr = 0;
	}
	friend std::istream& operator>>(std::istream& in, GenerickiNiz& gen)
	{
		for (int i = 0; i < vel; i++)
		{
			in >> gen.niz[i];
			gen.tr++;
		}
		return in;
	}

	GenerickiNiz& operator+(GenerickiNiz& gen)
	{

		int manji = 0;
		if()

		for (int i = 0; i < manji; i++)
		{

		}
	}
};