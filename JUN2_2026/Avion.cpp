#include "Avion.h"

Avion::Avion(const char* _kod, const char* _nazivAvioKompanije)
{
	kod = new char[strlen(_kod) + 1];
	strcpy(kod, _kod);

	nazivAvioKompanije = new char[strlen(_nazivAvioKompanije) + 1];
	strcpy(nazivAvioKompanije, _nazivAvioKompanije);
}

Avion::~Avion()
{
	delete[] kod;
	delete[] nazivAvioKompanije;
}

std::ostream& operator<<(std::ostream& out, Avion& a)
{
	// TODO: insert return statement here
	out <<"Kod: " << a.kod << " Naziv Kompanije: " << a.nazivAvioKompanije << " ";
	a.odstampaj(out);
	return out;
}

