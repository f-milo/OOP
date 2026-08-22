#include "Sokovi.h"

Sokovi::Sokovi()
{
	ukus = nullptr;
	zapremina = 0.0f;
	procenat = 0;
}

Sokovi::Sokovi(const char* _ukus, float _zapremina, int _procenat)
{
	ukus = new char[strlen(_ukus) + 1];
	strcpy(ukus, _ukus);

	zapremina = _zapremina;
	procenat = _procenat;
}

Sokovi::Sokovi(const Sokovi& s2)
{
	zapremina = s2.zapremina;
	procenat = s2.procenat;

	ukus = new char[strlen(s2.ukus) + 1];
	strcpy(ukus, s2.ukus);
}

Sokovi::~Sokovi()
{
	delete[] ukus;
}

Sokovi Sokovi::operator+(Sokovi& s2)
{
	char* noviUkus = new char[strlen(ukus)+1 + 3+ strlen(s2.ukus)];
	strcpy(noviUkus, this->ukus);
	strcat(noviUkus, " i ");
	strcat(noviUkus, s2.ukus);

	int noviProcenat = (procenat + s2.procenat) / 2;
	Sokovi s(noviUkus, s2.zapremina+zapremina, noviProcenat);

	delete[] noviUkus;
	noviUkus = nullptr;
	return s;
}

Sokovi& Sokovi::operator=(Sokovi& s2)
{
	// TODO: insert return statement here
	this->zapremina = s2.zapremina;
	this->procenat = s2.procenat;
	delete[] ukus;
	ukus = new char[strlen(s2.ukus) + 1];
	strcpy(ukus, s2.ukus);
	return *this;
}

bool Sokovi::operator==(Sokovi& s2)
{
	if (zapremina == s2.zapremina && procenat == s2.procenat && strcmp(ukus, s2.ukus)==0)
		return true;
	return false;
}

bool Sokovi::operator<=(Sokovi& s2)
{
	if (zapremina <= s2.zapremina)
		return true;
	return false;
}

std::ostream& operator<<(std::ostream& out, Sokovi& s)
{
	if (s.ukus == nullptr)
		out << "Nema ukusa!";
	else
		out << s.ukus;

	out << " " << " " << s.zapremina << " " << s.procenat;
	//strlen(s.ukus)+1
	return out;
	// TODO: insert return statement here
}

std::istream& operator>>(std::istream& in, Sokovi& s)
{
	char temp[256];
	if (in >> temp >> s.zapremina >> s.procenat)
	{
		delete[] s.ukus; // Obriši ako je nešto postojalo
		s.ukus = new char[strlen(temp) + 1];
		strcpy(s.ukus, temp);
	}
	return in;
}

float operator+(float _levi, Sokovi& _desni)
{
	return _levi + _desni.zapremina;
}

