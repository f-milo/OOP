#include <fstream>
#include <iostream>

#include "GenerickiNiz.h"


using namespace std;
void POINTS(int p)
{
	cout << "\033[" << 44 << "m";
	cout << "\t" << p << "\tPOEN(A)" << endl;
	cout << "\033[0m";
}
void main()
{
	/*
	// ------------------------- Zadatak 1 ---------------------------------
	// 1 poen
	POINTS(1);
	Pista* p = new Pista(6);
	// 2 poena
	POINTS(2);
	p->Dodaj(new Putnicki("JU20C", "AirSerbia", 196, 25, 12, 3.56));
	p->Dodaj(new Putnicki("JS10X", "SwissAir", 201, 75, 8, 1.87));
	p->Dodaj(new Putnicki("JU02A", "AirSerbia", 196, 7, 12, 4.85));
	// 2 poena
	POINTS(2);
	p->Dodaj(new Teretni("TS10X", "SwissAir", 7500, 25.00, 24.70));
	p->Dodaj(new Teretni("TE007", "Etihad", 15000, 75.00, 58.70));
	p->Dodaj(new Teretni("TS707", "SwissAir", 9500, 65.00, 64.70));
	// 2 poena
	POINTS(2);
	p->SacuvajUFajl("uzletnapista.txt");
	// 1 poen
	POINTS(1);
	cout << *p;
	// 2 poena
	POINTS(2);
	cout << p->PopunjeniPreko95();
	// 4 poena
	POINTS(4);
	p->ReorganizujAvioneNaPisti();
	cout << *p;
	// 4 poena
	POINTS(4);
	cout << p->AvioKompanijaSaNajvećimStepeonPopunjenostiKapaciteta();
	// 2 poena
	POINTS(2);
	delete p;
	*/
	// ------------------------- Zadatak 2 ---------------------------------
	// 1 poen
	POINTS(1);
	GenerickiNiz<int, 3> a;
	GenerickiNiz<int, 3> b;
	// 1 poen
	POINTS(1);
	cin >> a; //treba mi operator >>
	cin >> b;
	// 1 poen
	POINTS(1);

	GenerickiNiz<int> c = a + b; //treba mi operator +
	cout << c;
	// 1 poen
	POINTS(1);
	cout << c.Max();

	// 2 poena
	POINTS(2);
	c.Sort();
	// 2 poena
	POINTS(2);
	c.SnimiUFajl("int.txt");
	// ------------------- Vagon ---------------
	// 1 poen
	POINTS(1);
	GenerickiNiz<Vagon, 2> v1;
	GenerickiNiz<Vagon, 2> v2;
	// 1 poen
	POINTS(1);
	cin >> v1;
	cin >> v2;
	// 1 poen
	POINTS(1);
	GenerickiNiz<Vagon> v = v1 + v2;
	cout << v;
	// 1 poen
	POINTS(1);
	cout << v.Max();
	// 2 poena
	POINTS(2);
	v.Sort();
	// 2 poena
	POINTS(2);
	v.SnimiUFajl("vagon.txt");
	// Try-catch 4 poena
}