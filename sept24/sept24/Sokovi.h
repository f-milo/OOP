#pragma once
#include <iostream>
class Sokovi
{
private:
	char* ukus;
	float zapremina;
	int procenat;

public:
	Sokovi();
	Sokovi(const char* _ukus, float _zapremina, int _procenat);
	Sokovi(const Sokovi& s2);
	~Sokovi();

	//
	friend std::ostream& operator<<(std::ostream& out, Sokovi& s);
	friend std::istream& operator>>(std::istream& in, Sokovi& s);

	Sokovi operator+(Sokovi& s2);
	Sokovi& operator=(Sokovi& s2);
	friend float operator+(float _levi, Sokovi& _desni);
	bool operator==(Sokovi& s2);
	bool operator<=(Sokovi& s2);
};

