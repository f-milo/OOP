#include "Voda.h"

Voda::Voda(double _zapreminaAmbalaze) : Pice(_zapreminaAmbalaze)
{
	brojAmbalaza = 1;
}

void Voda::stampaj(std::ostream& out) const
{
	
}

bool Voda::uporedi(const Pice* p) const
{
	const Voda* novaVoda = dynamic_cast<const Voda*>(p);

	if (novaVoda == nullptr)
		return false;

	return(Pice::uporedi(p));

}

