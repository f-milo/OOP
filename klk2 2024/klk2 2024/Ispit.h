#pragma once
#include <iostream>


class Ispit
{
private:
	char* nazivIspita;
	int ocena;
	int brojESPB;
public:
	Ispit();
	Ispit(const char* _, int _ocena, int _brojESPB);
	~Ispit();
	Ispit(const Ispit& i);
	double vratiProsek();
	int vratiSumuESPB();



	
};