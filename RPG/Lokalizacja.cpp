#include "Lokalizacja.h"


Lokalizacja::Lokalizacja() {};
Lokalizacja::Lokalizacja(string nazwa, string opis, Przeciwnik przeciwnik, Przedmiot przedmiot)
	: nazwa(nazwa), opis(opis), przeciwnik(przeciwnik), przedmiot(przedmiot) {}

// wypisujemy nazwe i opis danej lokalizacji
void Lokalizacja::informacja()
{
	cout << nazwa << endl;
	cout << "==========================" << endl;
	cout << opis << endl;
}

// w zaleznosci od podjetego wyboru gracza zwracamy jego decyzje aby pozniej na jej podstawie
// przejsc do innego etapu gry
STAN Lokalizacja::wejdz_do_lokalizacji(Gracz * gracz)
{
	int wybor;
	cout << "Co chcesz zrobic?" << endl;
	cout << "1) Przeszukaj lokalizacje" << endl;
	cout << "2) Walcz " << endl;
	cout << "3) Zawroc " << endl;

	wybor = wybierz_opcje(3, 1);

	switch (wybor)
	{
	case 1:
	{
		Przedmiot  znalezisko = przeszukanie();
		gracz->otrzymuje_przedmiot(znalezisko);
		znalezisko.pobierz_okno().wyswietl();
		cout << "Dodajesz przedmiot do ekwipunku." << endl;
		cout << "Twoje odglosy, zbudzily straznika! " << endl << endl;
		return menu_wyboru_walki(gracz);
	}
	case 2:
		return 	menu_wyboru_walki(gracz);
	default:
		return STAN::UCIECZKA;
	}
}

// zwracamy wskaznik na adres przedmiotu
Przedmiot Lokalizacja::przeszukanie()
{
	cout << "Przeszukujac lokalizacje natrafiasz na przedmiot jest to: " << endl;
	zmien_kolor_txt(ZIELONY);
	przedmiot.informacja(false); // nie chcey informacjo tym czyejst wyposazony wiec false
	zmien_kolor_txt(ZOLTY);
	return przedmiot;
}

bool Lokalizacja::proba_ucieczki(Gracz * gracz)
{
	int zrecznosc_potwora = przeciwnik.pobierz_statystyki().pobierz_zrecznosc();

	// gracz jest wskaznikiem wiec na obiekt klasy Gracz, wykorzystujemy '->' aby dostac sie do pola klasy
	int zrecznosc_gracza = gracz->pobierz_statystyki().pobierz_zrecznosc();

	cout << "==============================================================" << endl;
	zmien_kolor_txt(CZERWONY);
	cout << "Zrecznosc potwora: " << zrecznosc_potwora << endl;

	zmien_kolor_txt(ZIELONY);
	cout << "Zrecznosc gracza:  " << zrecznosc_gracza << endl;
	zmien_kolor_txt(ZOLTY);
	cout << "==============================================================" << endl;

	// gdy gracz ma wiecej zrecznosci zwracamy true
	return zrecznosc_gracza > zrecznosc_potwora;
}


STAN Lokalizacja::walka(Gracz * gracz)
{
	przeciwnik.pobierz_okno().wyswietl();

	int zycie_potwora = przeciwnik.pobierz_statystyki().pobierz_zycie();
	int zycie_gracza = gracz->pobierz_statystyki().pobierz_zycie();

	// wykonuj dopoki jakis nie padnie
	while ( zycie_potwora> 0 && zycie_gracza >0)
	{
		int sila_potwory = przeciwnik.atak();
		int sila_gracza = gracz->atak();

		int obrona_potwora = przeciwnik.pobierz_statystyki().pobierz_obrona();
		int obrona_gracza = gracz->pobierz_statystyki().pobierz_obrona();

		int obrazenia_gracza = sila_gracza - obrona_potwora;
		int obrazenia_potwora = sila_potwory - obrona_gracza;

		cout << "==============================================================" << endl;
		zmien_kolor_txt(CZERWONY);
		cout << "Sila potwora: " << sila_potwory << endl;
		cout << "Obrona potwora: " << obrona_potwora << endl;
		cout << "==============================================================" << endl;

		zmien_kolor_txt(ZIELONY);
		cout << "Sila " << gracz->pobierz_nazwa() << " " << sila_gracza << endl;
		cout << "Obrona " << gracz->pobierz_nazwa() << " " << obrona_gracza << endl;
		zmien_kolor_txt(ZOLTY);

		cout << "==============================================================" << endl;
		zmien_kolor_txt(SELEDYNOWY);

		zycie_potwora -= obrazenia_gracza; 
		zycie_gracza -= obrazenia_gracza;

		cout << "Obrazenia: " << gracz->pobierz_nazwa() << "  " << sila_gracza - obrona_potwora << " vs ";
		cout << obrazenia_potwora << "  Potwor" << endl;

		cout << "Zycie: " << gracz->pobierz_nazwa() << "  " << zycie_gracza << " vs ";
		cout << zycie_potwora << "  Potwor" << endl;

	}


	zmien_kolor_txt(ZOLTY);

	if (zycie_potwora >= zycie_gracza)
		return STAN::PORAZKA;
	else
		return STAN::WYGRANA; // udalo sie wygrac wiec zwracamy taki stan
}

STAN Lokalizacja::menu_wyboru_walki(Gracz * gracz)
{
	cout << "Na Twojej drodze staje: " << endl;

	koloruj_txt(przeciwnik.pobierz_nazwa(), CZERWONY);

	cout << "1) (Walka) Dobadz broni" << endl;
	cout << "2) (Ucieczka) Wycofaj sie" << endl;

	int wybor = wybierz_opcje(2, 1);
	switch (wybor)
	{
	case 1:
	{
		cout << "Postanowiles stanac do walki" << endl;
		return walka(gracz); // zwracamy rezultat walki
	}
	break;
	default:
	{
		if (proba_ucieczki(gracz))
			return STAN::UCIECZKA;
		else
		{
			cout << "Nie udalo Ci sie uciec, musisz stanac do walki " << endl;
			nacisnij_klawisz();
			return	walka(gracz);  // zwracamy rezultat walki
		}
	}
	}
}

void Lokalizacja::zapisz_dane(string nazwa_pliku)
{
	fstream plik;
	string nazwa_laczona = nazwa_pliku + "_" + nazwa;
	plik.open(nazwa_laczona + ".txt", ios::out);

	if (plik.good() == true)
	{
		plik << nazwa << endl;
		plik << przeciwnik.pobierz_nazwa() << endl;
		plik << przedmiot.pobierz_nazwa() << endl;
		plik << opis;
		przeciwnik.zapisz_dane(nazwa_laczona);
		przedmiot.zapisz_dane(nazwa_laczona);
	}

	plik.close();
}

void Lokalizacja::wczytaj_dane(string nazwa_pliku)
{
	fstream plik;
	string nazwa_laczona = nazwa_pliku;
	plik.open(nazwa_laczona + ".txt", ios::in);

	if (plik.good())
	{
		string przeciwnik_nazwa, przedmiot_nazwa;

		plik >> nazwa >> przeciwnik_nazwa >> przedmiot_nazwa;

		string wyraz; // zapamietujemy wyraz

					  // teraz musimy wczytac caly opis lokalizacji, dlatego pobieramy po wyrazie i dodajemy odstep. nastepnie dodajemy w petli do opisu.
					  // wykonujemy to tak dlugo az nie wczytamy wszystkich danych.
		while (plik.good())
		{
			plik >> wyraz;
			opis += wyraz + " ";
		}

		przeciwnik.wczytaj_dane(nazwa_laczona + "_" + przeciwnik_nazwa);
		przedmiot.wczytaj_dane(nazwa_laczona + "_" + przedmiot_nazwa);
	}
	else
		cout << "Lokalizacja blad pliku: " + nazwa_laczona << endl;

	plik.close();
}