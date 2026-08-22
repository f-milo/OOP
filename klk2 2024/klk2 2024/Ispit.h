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
	Ispit(const char* _nazivIspita, int _ocena, int _brojESPB);
	~Ispit();
	Ispit(const Ispit& i);
	//double vratiProsek();
	//int vratiSumuESPB();

	friend std::ostream& operator<<(std::ostream& out, Ispit& i);

	friend std::istream& operator>>(std::istream& in, Ispit& i);

	bool operator>(Ispit& i);

	//Ispit operator+(Ispit& i); //ovo je operator za ISPIT + ISPIT // NE treba nam
	
	//treba nam operator + koji sabira 			rez = rez + niz[i]; //oeprator +, tj, float = float + ispit, a kako je left operand uvek this, a nama trbea da je float, preko frienda cemo...

	friend float operator+(const float& br, const Ispit& i);

	Ispit& operator=(const Ispit& i);
};