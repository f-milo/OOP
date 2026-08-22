#include "Pice.h"

std::ostream& operator<<(std::ostream& out, const Pice& p)
{
	out << "Broj Ambalaza: " << p.brojAmbalaza << std::endl;
	out << "Zapremina Ambalaze: " << p.zapreminaAmbalaze << std::endl;
	p.stampaj(out);
	return out;
}

bool Pice::operator==(const Pice& p) const
{
	if(uporedi(&p))
		return true;

	return false;
}

bool Pice::uporedi(const Pice* p) const
{
	if (p == nullptr)
		return false;

	return(zapreminaAmbalaze == p->zapreminaAmbalaze);
}
