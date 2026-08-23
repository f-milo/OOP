#pragma once
#include <iostream>

class Ispit
{
private:
	char* naziv;
	int ocena;
	int espb;

public:
	Ispit();

	Ispit(const char* _naziv, int _ocena, int _espb);


	//heap error, dodajem cpy cctor
	Ispit(const Ispit& i);
	~Ispit();

	// operator Type = Type
	Ispit& operator=(const Ispit& i);

	////operator float+Type (ocena)
	friend float operator+(float br, const Ispit& i);


	//operator Type < Type (espb)
	bool operator<(const Ispit& i);

	friend std::ostream& operator<<(std::ostream& out, const Ispit& i);

	friend std::istream& operator>>(std::istream& in, Ispit& i);
};
// + = < << >>


