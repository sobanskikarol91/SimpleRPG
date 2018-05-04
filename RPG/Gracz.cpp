#include "Gracz.h"

// domyslny konstruktor wywolujemy rowniez na liscie inicjalizacyjej konstruktor klasy bazowej
Gracz::Gracz() : Postac() {};

// konstruktor z lista inicjalizacyjna sluzacy do tworzenia postaci gracza
Gracz::Gracz(string nazwa, Statystyki statystyki, Ekwipunek ekwipunek)
	: Postac(nazwa, statystyki), ekwipunek(ekwipunek) {};

void  Gracz::otrzymuje_przedmiot(Przedmiot  przedmiot)
{
	ekwipunek.dodaj_przedmiot(przedmiot);
}


void  Gracz::zwieksz_poziom(int sila, int zrecznosc, int zycie)
{
	zmien_kolor_txt(ZIELONY);
	cout << "********************************************" << endl;
	cout << "NOWY POZIOM!" << endl;
	cout << "sila  +" << sila << "   zrecznosc  +" << zrecznosc << "   zycie  +" << zycie << endl;
	cout << "********************************************" << endl;
	zmien_kolor_txt(ZOLTY);

	statystyki.dodaj_zrecznosc(zrecznosc);
	statystyki.dodaj_sila(sila);
	statystyki.dodaj_zycie(zycie);
	statystyki.dodaj_poziom();
}

// metoda ta bierze pod uwage rowniez bonusy wszystkich przedmiotow w ekwipunku a dokladnie ich atrybutu sily
int  Gracz::atak()
{
	return statystyki.pobierz_sila() + modyfikator_obrazen() + ekwipunek.oblicz_bonusy_przedmiotow().pobierz_sila();
}

// wypisujemy wszystkie informacje o graczu
void  Gracz::informacje()
{
	zmien_kolor_txt(ZIELONY);
	Postac::informacje();   // informacje z klasy bazowej
	zmien_kolor_txt(ZOLTY);

	vector<Przedmiot> aktywne_przedmioty = ekwipunek.spis_aktywnych_przedmiotow();

	// jezeli sa jakies aktywne przedmioty
	if (aktywne_przedmioty.size())
	{
		// to wypisujemy o nich informacje
		for (unsigned int i = 0; i < aktywne_przedmioty.size(); i++)
		{
			cout << "=======================================================================================================================" << endl;
			aktywne_przedmioty[i].informacja();
		}
		Statystyki statystyki_gracza_przedmiotow = ekwipunek.oblicz_bonusy_przedmiotow() + statystyki;

		cout << "=======================================================================================================================" << endl;
		cout << endl << "Statystyki gracza wraz z bonusem przedmiotow " << endl;
		zmien_kolor_txt(KOLOR::SELEDYNOWY);
		statystyki_gracza_przedmiotow.informacja();
		zmien_kolor_txt(KOLOR::ZOLTY);
	}
	else // jezeli nie ma aktywnych przedmiotow to  wypisujemy informacje na czerwono
		koloruj_txt("Brak  aktywnych przedmiotow", CZERWONY);

}

void  Gracz::menu()
{
	cout << "1) Statystyki gracza" << endl;
	cout << "2) Przegladaj ekwipunek" << endl;
	cout << "3) Powrot" << endl;

	int wybor = wybierz_opcje(3, 1);

	switch (wybor)
	{
	case 1:
	{
		informacje();
		nacisnij_klawisz();
	}
	break;
	case 2:
		ekwipunek.menu();
		break;
	case 3:
		break;
	}
}

void  Gracz::zapisz_dane(string nazwa_pliku)
{
	fstream plik;
	string nazwa_laczona = nazwa_pliku + "_" + nazwa;
	plik.open(nazwa_laczona + ".txt", ios::out);

	if (plik.good() == true)
	{
		plik << nazwa;
		statystyki.zapisz_dane(nazwa_laczona);
		ekwipunek.zapisz_dane(nazwa_laczona);
	}

	plik.close();
}

void  Gracz::wczytaj_dane(string nazwa_pliku)
{
	fstream plik;
	string nazwa_laczona = nazwa_pliku;
	plik.open(nazwa_laczona + ".txt", ios::in);


	if (plik.good() == true)
	{
		plik >> nazwa;
		ekwipunek.wczytaj_dane(nazwa_laczona);
		statystyki.wczytaj_dane(nazwa_laczona);
	}
	else
		cout << "Gracz blad pliku: " + nazwa_laczona << endl;

	plik.close();
}

