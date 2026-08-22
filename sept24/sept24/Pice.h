#pragma once
#include <iostream>

class Pice
{
protected:
	double zapreminaAmbalaze;
	int brojAmbalaza=0;

public:
	Pice() { zapreminaAmbalaze = 0; brojAmbalaza = 0; }
	Pice(double _zapreminaAmbalaze) { zapreminaAmbalaze = _zapreminaAmbalaze;};
	virtual ~Pice() {};

	int getBrojAmbalaza() const { return brojAmbalaza; }
	void dodajBrojAmbalaza(int _broj) 
	{ 
		brojAmbalaza += _broj;
	}

	virtual void stampaj(std::ostream& out) const = 0;
	friend std::ostream& operator<<(std::ostream& out, const Pice& p);

	bool operator==(const Pice& p) const;
	virtual bool uporedi(const Pice* p) const;
};
