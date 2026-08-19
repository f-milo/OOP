#include "Putnicki.h"

Putnicki::Putnicki(const char* _kod, const char* _nazivAvioKompanije, int _ukupanBrojSedista, int _brojNepopunjenihSedista, int _brojSedistaBiznis, double _masaTereta) : Avion(_kod, _nazivAvioKompanije)
{
	ukupanBrojSedista = _ukupanBrojSedista;
	brojNepopunjenihSedista = _brojNepopunjenihSedista;
	brojSedistaBiznis = _brojSedistaBiznis;
	masaTereta = _masaTereta;
}

void Putnicki::odstampaj(std::ostream& out) const
{
	out << "Ukupan broj sedista: " << this->ukupanBrojSedista << " Broj sedista u biznis klasi: " << this->brojSedistaBiznis << " Broj nepopunjenih sedista: " << this->brojNepopunjenihSedista << " Masa tereta: " << this->masaTereta << std::endl;
}

bool Putnicki::preko95()
{
	if (getPopunjenost() == 0) 
		return false;

	return (getPopunjenost() > 95);
}

double Putnicki::getPopunjenost()
{
	if (ukupanBrojSedista == 0) 
		return false;
	double br = ukupanBrojSedista - brojNepopunjenihSedista;
	return (br / ukupanBrojSedista) * 100;
}
