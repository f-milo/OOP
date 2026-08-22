#include "Sok.h"

Sok::Sok(double _zapreminaAmbalaze, const char* _ukus, double _procenatVoca, double _odnosCene) : Pice(_zapreminaAmbalaze)
{
	ukus = new char[strlen(_ukus) + 1];
	strcpy(ukus, _ukus);

	procenatVoca = _procenatVoca;
	odnosCene = _odnosCene;

}

Sok::~Sok()
{
	delete[] ukus;
}

void Sok::stampaj(std::ostream& out) const
{
	out << "Ukus: " << ukus << std::endl;
	out << "Procenat Voca: " << procenatVoca << std::endl;
	out << "Odnos cene: " << odnosCene << std::endl;
}
