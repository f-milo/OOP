#include <iostream>
#include <fstream>

#include "Fabrika.h"
#include "Sokovi.h"

using namespace std;



void main()
{
	int maxPodataka = 8, brojPodataka = 7;
	// 3 boda
	// postavljanje i prihvatanje izuzetaka
	try
	{
		float voda[] = { 1, 0.2, 0.5, 1, 0.5, 0.2, 0.2 };
		Fabrika<float> fv(maxPodataka);
		// 1 bod
		for (int i = 0; i < brojPodataka; i++)
			fv.Dodaj(voda[i]);
		cout << fv << endl; // fv.Ispisi(cout);
		// 1 bod
		fv.Izbaci(voda[1]);
		cout << fv << endl; //fv.Ispisi(cout);

		// 1 bod
		float ukupno = fv.Ukupno();
		cout << ukupno << endl; //
		// 1 bod
		int vrednost = 1; float ukupnaVrednost = 0;
		int broj = fv.UkupniBrojVrednost(vrednost, &ukupnaVrednost);
		cout << broj << " " << ukupnaVrednost << endl; // 2 2
		// 1 bod
		int najmanjeAmbalaza = fv.NajmanjeAmbalaza(2.8);
		cout << najmanjeAmbalaza << endl; // 4
		// 1 bod
		fv.Sacuvaj("NovaFabrikaVode.txt");
		// 1 boda
		Fabrika<float> novaUcitana(maxPodataka);
		novaUcitana.Ucitaj("NovaFabrikaVode.txt");
		cout << novaUcitana << endl; // novaUcitana.Ispisi(cout);
	}
	catch (const char* msg)
	{
		std::cout << "Greska " << msg;
	}
	try
	{
		char ukus[][7] = { "jagoda", "jabuka", "jagoda", "jagoda", "jagoda", "jabuka",

		"jagoda" };

		float zap[] = { 1, 0.2, 0.5, 1, 0.5, 0.2, 0.2 };
		int procenat[] = { 50, 70, 50, 50, 50, 70, 50 };
		Fabrika<Sokovi> fs(maxPodataka);
		// 1 bod
		for (int i = 0; i < brojPodataka; i++) {
			fs.Dodaj(Sokovi(ukus[i], zap[i], procenat[i]));
		}
		// 1 bod
		cout << fs << endl; //fs.Ispisi(cout);
		// 1 bod
		fs.Izbaci(Sokovi(ukus[1], zap[1], procenat[1]));
		cout << fs << endl; //fs.Ispisi(cout);
		// 2 boda
		float ukupno = fs.Ukupno();
		cout << ukupno << endl;
		// 2 boda
		Sokovi vr(ukus[0], zap[0], procenat[0]);
		float ukupnaVrednost = 0;
		int broj = fs.UkupniBrojVrednost(vr, &ukupnaVrednost);
		cout << broj << " " << ukupnaVrednost << endl; // 2 2
		// 2 boda
		int najmanjeAmbalaza = fs.NajmanjeAmbalaza(2.5);
		cout << najmanjeAmbalaza << endl; // 3
		// 0 bodova
		fs.Sacuvaj("NovaFabrikaSokova.txt");
		// 1 bod
		Fabrika<Sokovi> novaUcS(maxPodataka);
		novaUcS.Ucitaj("NovaFabrikaSokova.txt");
		cout << novaUcS << endl; // novaUcS.Ispisi(cout);
	}
	catch (const char* msg)
	{
		std::cout << "Greska " << msg;
	}
	
}
/*
Задатак 2:
Написати програм о вођењу евиденције у фабрици пића. Програм треба да подржи рад са
различитим типовима података који описују пиће и да обезбеди чување произвољног броја
ових података.

Могуће је додавање новог пића у колекцију која представља фабрику, али је неопходно да она
остане уређена у неопадајући редослед по запремини. Уколико је колекција пуна пријавити
проблем.

Могуће је избацивање пића из колекције на основу задате запремине. Ако не постоји такво
пиће пријавити проблем.

Омогућити одређивање и враћање укупне запремине пића у складишту.

Омогућити и враћање укупног броја амбалажа задате запремине и укупне запремине пића у
тој амбалажи, једним проласком кроз колекцију.

Омогућити одређивање и враћање најмањег броја амбалажа којим је могуће испунити захтев
за траженом количином пића (запремина пића може бити већа или једнака траженој
количини), ако није могуће вратити 0.

Апликација може сачувати колекцију у датотеку за каснију анализу, а могуће је и учитати
запамћене податке и наставити рад са њима.

Рад апликације треба проверити за случај фабрике која производи воду и за случај фабрике
сокова. Фабрика воде за сваку амбалажу памти само запремину у литрима, тачније памти само
реалне податке. Фабрика сокова памти назив воћа (низ карактера), запремину амбалаже и
проценат воћа.

Проверити рад апликације функцијом zadatak2 која се налази у наставку. Проширити програм
тако да обезбеди обраду изузетака.

*/