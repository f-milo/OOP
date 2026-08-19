
#include <fstream>
#include <iostream>

#include "Avion.h"
#include "Pista.h"
#include "Putnicki.h"
#include "Teretni.h"

using namespace std;
void POINTS(int p)
{
	cout << "\033[" << 44 << "m";
	cout << "\t" << p << "\tPOEN(A)" << endl;
	cout << "\033[0m";
}
void main()
{
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
	cout << "Broj aviona popunjenih PREKO 95%: ";
	cout << p->PopunjeniPreko95() << std::endl;
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













	// ------------------------- Zadatak 2 ---------------------------------



	//// 1 poen
	//POINTS(1);
	//GenerickiNiz<int, 3> a;
	//GenerickiNiz<int, 3> b;
	//// 1 poen
	//POINTS(1);
	//cin >> a;
	//cin >> b;
	//// 1 poen
	//POINTS(1);

	//GenerickiNiz<int> c = a + b;
	//cout << c;
	//// 1 poen
	//POINTS(1);
	//cout << c.Max();

	//// 2 poena
	//POINTS(2);
	//c.Sort();
	//// 2 poena
	//POINTS(2);
	//c.SnimiUFajl("int.txt");
	//// ------------------- Vagon ---------------
	//// 1 poen
	//POINTS(1);
	//GenerickiNiz<Vagon, 2> v1;
	//GenerickiNiz<Vagon, 2> v2;
	//// 1 poen
	//POINTS(1);
	//cin >> v1;
	//cin >> v2;
	//// 1 poen
	//POINTS(1);
	//GenerickiNiz<Vagon> v = v1 + v2;
	//cout << v;
	//// 1 poen
	//POINTS(1);
	//cout << v.Max();
	//// 2 poena
	//POINTS(2);
	//v.Sort();
	//// 2 poena
	//POINTS(2);
	//v.SnimiUFajl("vagon.txt");
	//// Try-catch 4 poena
}




//Opšte napomene za sve klase :
//-Atributi ne mogu biti javni.
//- Kreirati sve potrebne javne metode koje će obezbediti da program radi(uključujući konstruktore i
//	destruktor).
//	- Izbeći na svaki način dupliranje koda u celom projektu.
//	- Pridržavati se principa objektno orijentisanog programiranja.
//	- Zabranjena je upotreba ugrađenog tipa string.
//	Zadatak 1:
//Svaka avio kompanija poseduje dva tipa aviona.Svaki avion ima svoj jedinstveni kod(niz karaktera) i naziv
//avio kompanije(niz karaktera).Putnički tip aviona se opsuje ukupnim brojem sedišta, brojem nepopunjenih
//sedišta, brojem sedišta u biznis klasi i masom tereta(masa svih kofera u tonama).Teretni avion se opisuje još
//maksimalnim doletom u kilometrima, maksimalnom masom tereta u tonama koju može da preveze i trenutnom
//masom tereta u tonama.
//U glavnom program omogućiti kreiranje uzletne piste na kojoj poleću putnički i teretni avioni.Program treba
//da omogući sledeće funkcionalnosti :
//-Pamćenje svih aviona na uzletnoj pisti u vidu tekstualnog fajla.
//- Prikaz svih podataka o avionima na uzletnoj pisti.
//- Prikaz svih aviona na uzletnoj pisti čiji je stepen popunjenost veći od 90 % .Stepen popunjenosti
//kapaciteta za putnički avion(float vrednost) se računa kao odnos broja popunjenih sedišta i
//ukupnog broja sedišta.Stepen popunjenosti kapaciteta za teretni avion(float vrednost) računa se
//kao odnos mase trenutnog tereta u avionu i maksimalne mase tereta koji avion može da preveze.
// 
//- Reorganizovati avione na uzletnoj pisti, tako da prvo poleću avioni sa većim kapacitetom
//popunjenosti.
// 
//- Prikazati avio kompaniju koja ima najveći stepen popunjenost kapaciteta svih aviona te kompanije
//na uzletnoj pisti.
//
//Zadatak 2:
//Kreirati klasu GenerickiNiz koja omogućava rad sa objektima proizvoljnog tipa i koja pruža osnovne operacije
//nad nizom.Moguće je učitati niz sa standardnog toka podataka, prikazati niz na standardni tok podataka,
//sabrati dva niza(sabiraju se elementi na istim pozicijama), odrediti maksimalni element niza, sortirati niz u
//rastućem redosledu i upisati sve elemente niza u fajl.
//Kreirati klasu Vagon.Svaki vagon opisan je sopstvenom masom(float) i masom tereta(float).Ukoliko je
//masa tereta veća od mase vagona prijaviti problem.Smatrati da je najveći vagon onaj koji ima najveću masu
//tereta.
//Kreiranu klasu GenerickiNiz i iskoristiti je za rad sa nizom celih brojeva.
//Za testiranje kreirane klase GenerickiNiz u glavnom programu, upotrebiti cele brojeve, a zatim i objekte klase
//Vagon.Kreirati po dve instance klase GenerickiNiz, učitati obe, sabrati, odrediti maksimalne elemente,
//sortirati nizove i zapamtiti elemente niza u odgovarajući fajl.Ponoviti postupak za objekte klase Vagon.
//PREDMETNI NASTAVNICI I ASISTENTI
//
//main.cpp