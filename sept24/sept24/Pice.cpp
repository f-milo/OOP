#include "Pice.h"

std::ostream& operator<<(std::ostream& out, const Pice& p)
{
	out << "Broj Ambalaza: " << p.brojAmbalaza << std::endl;
	out << "Zapremina Ambalaze: " << p.zapreminaAmbalaze << std::endl;
	p.stampaj(out);
	return out;
}
