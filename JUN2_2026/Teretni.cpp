#include "Teretni.h"

Teretni::Teretni(const char* _kod, const char* _nazivAvioKompanije, int _maksimalniDoletKM, double _maksTeretT, double _trenutnaMasaTeretaT) : Avion(_kod, _nazivAvioKompanije)
{
	maksimalniDoletKM = _maksimalniDoletKM;
	maksTeretT = _maksTeretT;
	trenutnaMasaTeretaT = _trenutnaMasaTeretaT;
}

void Teretni::odstampaj(std::ostream& out) const
{
	out << "Maksimalni dolet: " << this->maksimalniDoletKM << "km." << " Maksimalni teret: " << this->maksTeretT << "t. " << " Trenutna masa tereta: " << this->trenutnaMasaTeretaT << "t." << std::endl;
}

bool Teretni::preko95()
{
	return (getPopunjenost() > 95);
}

double Teretni::getPopunjenost()
{
	return ((double)trenutnaMasaTeretaT / maksTeretT * 100);
}
