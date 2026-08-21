#include <iostream>
#include "Kolekcija.h"
#include "Ispit.h"
using namespace std;

void main() {
	int maxPodataka = 8, brojPodataka = 5;
	int test[] = { 23, 37, 28, 31, 34 };
	const char* naziv[] = { "AIP", "UUR", "FIZ", "MAT", "EKM" };
	int ocena[] = { 10, 10, 6, 7, 8 };
	int espb[] = { 3, 5, 6, 5, 5 };

	try {
		// 1 bod
		Kolekcija<int> kolekcijaA(maxPodataka);

		// 1 bod
		for (int i = 0; i < brojPodataka; i++)
			kolekcijaA.DodajPodatak(test[i]);

		// 1 bod
		cout << kolekcijaA << endl; // kolekcijaA.Ispisi(cout);
		// 1 bod
		kolekcijaA.Obrisi(4);
		cout << kolekcijaA << endl; // kolekcijaA.Ispisi(cout);

		// 1 bod
		float prosecnaOcena = kolekcijaA.OdrediProsek();
		cout << prosecnaOcena << endl;
/*

		// 1 bod
		int najveciPodatak = kolekcijaA.NajveciPodatak();
		cout << najveciPodatak << endl;

		// 1 bod
		kolekcijaA.Sacuvaj("KolekcijaA.txt");

		// 2 boda
		Kolekcija<int> kolekcijaATest(maxPodataka);
		kolekcijaATest.Ucitaj("KolekcijaA.txt");
		cout << kolekcijaATest << endl; // kolekcijaATest.Ispisi(cout);

	*/
	}
	catch (const char* poruka) {
		cout << poruka << endl;
	}
	/*
	try {
		// 1 bod
		Kolekcija<Ispit> kolIspit(maxPodataka);

		// 1 bod
		for (int i = 0; i < brojPodataka; i++) {
			Ispit tmp(naziv[i], ocena[i], espb[i]);
			kolIspit.DodajPodatak(tmp);
		}

		// 1 bod
		cout << kolIspit << endl; // kolIspit.Ispisi(cout);

		// 0 bodova
		kolIspit.Obrisi(4);
		cout << kolIspit << endl; // kolIspit.Ispisi(cout);

		// 2 boda
		float prosecnaOcena2 = kolIspit.OdrediProsek();
		cout << prosecnaOcena2 << endl;

		// 2 boda
		Ispit najveci = kolIspit.NajveciPodatak();
		cout << najveci << endl;

		// 0 bod
		kolIspit.Sacuvaj("Ispiti.txt");

		// 1 bod
		Kolekcija<Ispit> kolIspitTest(maxPodataka);
		kolIspitTest.Ucitaj("Ispiti.txt");
		cout << kolIspitTest << endl; // kolIspitTest.Ispisi(cout);
	}
	catch (const char* porukica) {
		cout << porukica << endl;
	}
*/
}




	/*

	Потребно је направити апликацију која ће помоћи рад студентске службе. Студентска служба
	за сваког студента води евиденцију о положеним испитима.
	 Кориснику ове апликације потребно је омогућити додавање новог податка на крају
	колекције (* уколико је колекција пуна пријавити проблем).
	 Могуће је обрисати постојећи податак из колекције на основу његовог редног броја у
	колекцији (* уколико не постоји податак са задатим редним бројем пријавити
	проблем).
	 Омогућити враћање просечне вредности свих елемената из колекције.
	 Омогућити враћање кључног податка из целе колекције.
	 Апликација треба да обезбеди снимање свих података из колекције у датотеку задатог
	назива (* уколико дође до проблема при снимању колекције у датотеку пријавити
	исти).
	 Сачуване податке могуће је учитати из датотеке задатог назива и наставити даљи рад
	(* уколико дође до проблема приликом учитавања података из датотеке у колекцију
	пријавити исти).
	Рад апликације потребно је проверити за тип int али и за ентитет Испит који је описан
	следећим својствима: назив испита (char *), оцена (int) и број остварених ЕСПБ поена
	(int). За рачунање просечне вредности користи се податак о оцени, а за одређивање
	кључног податка из колекције користи се информација о ЕСПБ поенима и он представља
	суму свих ЕСПБ поена са свих испита које је студент положио.
	Проверити рад апликације за оба скупа података са максимално 8 података у колекцији. За
	оба тестирања додати барем 5 података, обрисати један податак на основу редног броја,
	одредити и приказати просечну вредност и вредност кључног податка, издвојити и приказати
	највећи податак из колекције, сачувати податке из колекције у датотеку, учитати их у другу
	колекцију. Приказати све податке из колекције након додавања и брисања, као и након
	учитавања у нову колекцију. Проширити главни програм тако да обезбеди обраду изузетака.

*/