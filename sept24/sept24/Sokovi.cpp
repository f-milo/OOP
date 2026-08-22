#include "Sokovi.h"

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
