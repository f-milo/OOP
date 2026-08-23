#include "Sokovi.h"

Sokovi::Sokovi()
{
	ukus = nullptr;
	zapremina = 0;
	procenat = 0;
}

Sokovi::Sokovi(const char* _ukus, float _zapremina, int _procenat)
{
	ukus = new char[strlen(_ukus) + 1];
	strcpy(ukus, _ukus);

	zapremina = _zapremina;
	procenat = _procenat;
}

Sokovi::~Sokovi()
{
	delete[] ukus;
}

Sokovi::Sokovi(const Sokovi& s)
{
	ukus = new char[strlen(s.ukus) + 1];
	strcpy(ukus, s.ukus);
	zapremina = s.zapremina;
	procenat = s.procenat;
}

//Sokovi Sokovi::operator+(const Sokovi& s)
//{
//	Sokovi* sok = new Sokovi();
//	sok->ukus = new char[strlen(s.ukus) + 3 + strlen(ukus) + 1];
//	strcpy(sok->ukus, ukus);
//	strcat(sok->ukus, " i ");
//	strcat(sok->ukus, s.ukus);
//
//	sok->zapremina = zapremina + s.zapremina;
//	sok->procenat = (procenat + s.procenat) / 2;
//
//	return *sok;
//	// TODO: insert return statement here
//}
Sokovi& Sokovi::operator=(const Sokovi& s)
{
	if (this == &s)
		return *this;

	delete[] ukus;

	if (s.ukus != nullptr)
	{
		ukus = nullptr;
		ukus = new char[strlen(s.ukus)+ 1];
		strcpy(ukus, s.ukus);
	}
	else
	{
		ukus = nullptr;
	}
	zapremina = s.zapremina;
	procenat = s.procenat;

	return *this;
	// TODO: insert return statement here
}

bool Sokovi::operator==(const Sokovi& s)
{
	if (strcmp(ukus, s.ukus) == 0 && zapremina == s.zapremina && procenat == s.procenat)
		return true;
	return false;
}

bool Sokovi::operator>=(const Sokovi& s)
{
	return zapremina >= s.zapremina;
}

float Sokovi::operator<(const Sokovi& s)
{
	return this->zapremina < s.zapremina;
}

bool operator>=(const float br, const Sokovi& s)
{

	return br>=s.zapremina;
}

std::ostream& operator<<(std::ostream& out, const Sokovi& s)
{
	out << s.ukus << " " << s.procenat << " " << s.zapremina << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in, Sokovi& s)
{
	char* buf = new char[100];
	in >> buf;
	in >> s.procenat;
	in >> s.zapremina;
	
	delete[] s.ukus;
	s.ukus = new char[strlen(buf) + 1];
	strcpy(s.ukus, buf);
	delete[] buf;

	return in;
}

float operator+(const float broj, const Sokovi& s)
{
	return broj+s.zapremina;
}

