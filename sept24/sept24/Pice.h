#pragma once
#include <iostream>

class Pice
{
protected:
	double zapreminaAmbalaze;
	int brojAmbalaza;

public:
	Pice() {};
	Pice(double _zapreminaAmbalaze) { zapreminaAmbalaze = _zapreminaAmbalaze;};
	virtual ~Pice() {};

	virtual void stampaj(std::ostream& out) const = 0;
	friend std::ostream& operator<<(std::ostream& out, const Pice& p);

};
