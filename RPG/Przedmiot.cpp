#include "Przedmiot.h"

Przedmiot::Przedmiot() :nazwa("Brak"), wyposazony(false) {};
Przedmiot::Przedmiot(string nazwa, Statystyki statystyki) : okno(Okno(nazwa)), nazwa(nazwa), statystyki(statystyki), wyposazony(false) {}

void Przedmiot::informacja(bool wyposazony_informacja)
{
	cout << nazwa << "  ";

	if (wyposazony_informacja)
	{
		if (wyposazony)	koloruj_txt(" (Wyposazony)", ZIELONY);
		else	koloruj_txt(" (Nie wyposazony)", CZERWONY);
	}

	statystyki.informacja();
}

void Przedmiot::zapisz_dane(string nazwa_pliku)
{
	fstream plik;
	string nazwa_laczona = nazwa_pliku + "_" + nazwa;
	plik.open(nazwa_laczona + ".txt", ios::out);

	if (plik.good() == true)
	{
		plik << nazwa << " " << wyposazony;
		statystyki.zapisz_dane(nazwa_laczona);
	}

	plik.close();
}

void Przedmiot::wczytaj_dane(string nazwa_pliku)
{
	fstream plik;
	string nazwa_laczona = nazwa_pliku;
	plik.open(nazwa_laczona + ".txt", ios::in);

	if (plik.good() == true)
	{
		plik >> nazwa >> wyposazony;
		statystyki.wczytaj_dane(nazwa_laczona);
		okno = Okno(nazwa); // tworzymy nowy obiekt okno ze sciezka;
	}
	else
		cout << "Przedmiot blad pliku: " + nazwa_laczona << endl;

	plik.close();
}