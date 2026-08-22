#include "Ispit.h"

Ispit::Ispit()
{
}

Ispit::Ispit(const char* _nazivIspita, int _ocena, int _brojESPB)
{
	nazivIspita = new char[strlen(_nazivIspita) + 1];
	strcpy(nazivIspita, _nazivIspita);

	ocena = _ocena;
	brojESPB = _brojESPB;
}

Ispit::~Ispit()
{
	delete[] nazivIspita;
	ocena = 0;
	brojESPB = 0;
}

Ispit::Ispit(const Ispit& i)
{
	nazivIspita = new char[strlen(i.nazivIspita) + 1];
	strcpy(nazivIspita, i.nazivIspita);

	ocena = i.ocena;
	brojESPB = i.brojESPB;
}

bool Ispit::operator>(Ispit& i)
{
	if (ocena > i.ocena)
		return true;
	return false;
}

Ispit& Ispit::operator=(const Ispit& i)
{
	nazivIspita = new char[strlen(i.nazivIspita) + 1];
	strcpy(nazivIspita, i.nazivIspita);

	ocena = i.ocena;
	brojESPB = i.brojESPB;

	return *this;
}

std::ostream& operator<<(std::ostream& out, Ispit& i)
{
	out << i.nazivIspita << std::endl;
	out << i.brojESPB << std::endl;
	out << i.ocena << std::endl;

	return out;
}

std::istream& operator>>(std::istream& in, Ispit& i)
{
	in >> i.nazivIspita >> i.brojESPB >> i.ocena;
	return in;
}

float operator+(const float& br, const Ispit& i)
{
	return br+i.ocena;
}
