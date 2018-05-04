#include "Przeciwnik.h"

Przeciwnik::Przeciwnik() : Postac() {};
// konstruktur z lista inicjalizacyjna, w ktorej wywolujemy konstruktor klasy bazowej
Przeciwnik::Przeciwnik(string nazwa, Statystyki statystyki)
	: Postac(nazwa, statystyki), okno(Okno(nazwa)) {};


int Przeciwnik::atak()
{
	return statystyki.pobierz_sila() + modyfikator_obrazen();
}

void Przeciwnik::zapisz_dane(string nazwa_pliku)
{
	fstream plik;
	string nazwa_laczona = nazwa_pliku + "_" + nazwa;
	plik.open(nazwa_laczona + ".txt", ios::out);

	if (plik.good() == true)
	{
		plik << nazwa;
		statystyki.zapisz_dane(nazwa_laczona);
	}

	plik.close();
}

void Przeciwnik::wczytaj_dane(string nazwa_pliku)
{
	fstream plik;
	string nazwa_laczona = nazwa_pliku;
	plik.open(nazwa_laczona + ".txt", ios::in);

	if (plik.good() == true)
	{
		plik >> nazwa;
		statystyki.wczytaj_dane(nazwa_laczona);
		okno = Okno(nazwa); // tworzymy nowy obiekt okno ze sciezka;
	}
	else
		cout << "Przeciwnik blad pliku: " + nazwa_pliku << endl;

	plik.close();
}