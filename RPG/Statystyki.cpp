#include "Statystyki.h"

// domyslny konstruktor ustawia wszystkie wartosci nazero
Statystyki::Statystyki() : zycie(0), sila(0), zrecznosc(0), obrona(0), poziom(0) {};
Statystyki::Statystyki(int zycie, int sila, int zrecznosc, int obrona, int poziom) : zycie(zycie), sila(sila), zrecznosc(zrecznosc), obrona(obrona), poziom(poziom) {};

void Statystyki::informacja()
{
	zmien_kolor_txt(ZOLTY); // kolorujemy na zolto
	cout << "Poziom: "; koloruj_dodatnie(poziom);
	cout << "HP: "; koloruj_dodatnie(zycie);
	cout << "Sila: "; koloruj_dodatnie(sila);
	cout << "Obrona: "; koloruj_dodatnie(obrona);
	cout << "Zrecznosc: "; koloruj_dodatnie(zrecznosc);
	cout << endl;
}

// operator +=, definiuje jak mamy dodac do jednego skladnika drugi
Statystyki& Statystyki::operator+= (Statystyki const& s)
{
	// dodajemy poszczegolne skladowe statystyk do siebie i zwracamy rezultat jako nowy obiekt
	zycie += s.zycie;
	sila += s.sila;
	zrecznosc += s.zrecznosc;
	obrona += s.obrona;
	// poziomu nie dodajemy
	return *this;
}

// operator dodawania opisuje jak mamy dodawac dwa skladniki
Statystyki Statystyki::operator+ (Statystyki const& s)
{
	return Statystyki(zycie + s.zycie, sila + s.sila, zrecznosc + s.zrecznosc, obrona + s.obrona, 0); // poziomu nie dodajemy
}

void Statystyki::zapisz_dane(string nazwa_pliku)
{
	fstream plik;
	plik.open(nazwa_pliku + "_statystyki" + ".txt", ios::out);

	if (plik.good() == true)
		plik << zycie << " " << sila << " " << zrecznosc << " " << obrona << " " << poziom;

	plik.close();
}

void Statystyki::wczytaj_dane(string nazwa_pliku)
{
	fstream plik;
	plik.open(nazwa_pliku + "_statystyki" + ".txt", ios::in);

	if (plik.good() == true)
	{
		plik >> zycie >> sila >> zrecznosc >> obrona >> poziom;
	}
	else
		cout << "blad pliku: " + nazwa_pliku << endl;

	plik.close();
}