#pragma once
#include <iostream>
class Sokovi
{
	float zapremina;
	int procenat;
	char* ukus;

public:
	Sokovi();
	Sokovi(const char* _ukus, float _zapremina, int _procenat);
	~Sokovi();
	Sokovi(const Sokovi& s);
	Sokovi& operator=(const Sokovi& s);
	Sokovi operator+(const Sokovi& s);
	bool operator==(const Sokovi& s);
	friend bool operator>=(const float br, const Sokovi& s);
	bool operator>=(const Sokovi& s);
	friend std::ostream& operator<<(std::ostream& out, const Sokovi& s);
	friend std::istream& operator>>(std::istream& in, Sokovi& s);
	
	friend float operator+(const float broj, const Sokovi& s);
	float operator<(const Sokovi& s);

};

