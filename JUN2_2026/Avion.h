#pragma once
#include <iostream>

class Avion
{
protected:
	char* kod;
	char* nazivAvioKompanije;
public:
	Avion(const char* _kod, const char* _nazivAvioKompanije);
	virtual ~Avion();
	virtual void odstampaj(std::ostream& out) const = 0;
	
	virtual bool preko95() = 0;

	virtual double getPopunjenost() = 0;
	//cpy cctor

	friend std::ostream& operator<<(std::ostream& out, Avion& a);
};

