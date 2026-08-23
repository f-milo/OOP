#include "Ispit.h"

Ispit::Ispit()
{
	naziv = nullptr;
	ocena = 0;
	espb = 0;
}

Ispit::Ispit(const char* _naziv, int _ocena, int _espb)

{
	naziv = new char[strlen(_naziv) + 1];
	strcpy(naziv, _naziv);
	ocena = _ocena;
	espb = _espb;
}

Ispit::Ispit(const Ispit& i)
{
	//vrlo bitno
	//delete[] naziv;
	//Ne sme da stoji jer objekat this jos nije napravljen i ne postoji da bih ja brisao naziv;
	//Dolazi do heap corruption.
	naziv = new char[strlen(i.naziv) + 1];
	strcpy(naziv, i.naziv);

	ocena = i.ocena;
	espb = i.espb;
}

Ispit::~Ispit()
{
	delete[] naziv;
}

Ispit& Ispit::operator=(const Ispit& i)
{
	//this je left operand, i je right operand...
	if (this == &i) //Da li this i i predstavljaju isti objekat, tj. da li imaju istu adresu?
	{
		return *this;
	}
	delete[] naziv;
	naziv = new char[strlen(i.naziv) + 1];
	strcpy(naziv, i.naziv);

	ocena = i.ocena;
	espb = i.espb;

	return *this;
}

bool Ispit::operator<(const Ispit& i)
{
	return (this->espb < i.espb);
}

float operator+(float br, const Ispit& i)
{
	return br + i.ocena;
}

std::ostream& operator<<(std::ostream& out, const Ispit& i)
{
	out << i.naziv << std::endl;
	out << i.espb << std::endl;
	out << i.ocena << std::endl;

	return out;
}

std::istream& operator>>(std::istream& in, Ispit& i)
{
	char* buf = new char[100];
	in >> buf;
	in >> i.espb;
	in >> i.ocena;

	delete[] i.naziv;
	i.naziv = new char[strlen(buf) + 1];
	strcpy(i.naziv, buf);
	delete[] buf;
	return in;
}
