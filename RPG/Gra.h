#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream> // do operacji na plikach
#include "Gracz.h"
#include "Lokalizacja.h"
#include "Szkielet.h"
#include "Wilk.h"
#include "Wladca.h"
#include "Zbrojny.h"
#include "Bandyta.h" 
#include "Przedmiot.h"
#include "Stan.h" // pozwala na przeslanie wiadomosci zwrotnej, wyboru gracza z lokalizacji
#include "Dodatki.h"
#include "Statystyki.h"
#include "IPlik.h"
using namespace std;

class Gra : IPlik
{
	Gracz gracz;
	// spis wszystkich lokalizacji w grze
	vector <Lokalizacja> lokalizacje;
public:
	Gra()
	{
		stworz_lokalizacje();
	}

	void stworz_postac()
	{
		string nazwa;
		zmien_kolor_txt(ZOLTY); // kolorujemy tekst od tej pory na zolto
		cout << "Stworz nowa postac" << endl << "Imie Twojego bohatera brzmi: ";
		cin >> nazwa;

		Ekwipunek ekwipunek;
		// dodajemy do ekwipunku miecz z odpowiednimy statysykami
		ekwipunek.dodaj_przedmiot(Przedmiot("Miecz", Statystyki(0, 1, 0, 0, 0)));

		// wywolujemy konstruktor gracza podajac odpowiednie parametry
		gracz = Gracz(nazwa, Statystyki(10, 2, 2, 2, 1), ekwipunek);
		menu_glowne();
	}

	// Tworzymy lokalizacje nadajac im nazwe, opis, i potwora jaki strzerze to miejsce i przedmiot do zdobycia
	void stworz_lokalizacje()
	{
		lokalizacje.push_back(Lokalizacja("Krypta",
			"Na samym srodku sciezki, dostrzegasz schody prowadzace w dol. Wyczuwasz potezna, mroczna, aure bijaca z czelusci tej sciezki. Krzewy i drzewa zdaja sie byc obumarle, a w zasiegu wzroku gesto scieli sie truchlo martwych zwierzat i rozsypane kosci",
			Szkielet("Szkielet", Statystyki(10, 2, 2, 2, 1)),
			Przedmiot("Helm", Statystyki(0, 0, 0, 1, 0))));

				lokalizacje.push_back(Lokalizacja("Trakt kupiecki",
					"Spogladajac na polnocny wschod widzisz martwego czlowieka, ktory lezy we wlasnej krwi, praktycznie bez odzienia. Na trawie dostrzegasz slady walki oraz rozerwany, mieszek zlota. ",
					Bandyta("Bandyta", Statystyki(10, 2, 2, 2, 1)),
					Przedmiot("Zbroja", Statystyki(0, 0, 0, 2, 0))));
				/*
				lokalizacje.push_back(Lokalizacja("Las",
					"Patrzac na polnocny zachod, dostrzegasz gesty las. Drzewa sa poranione i ociekajace zywica. Masz wrazenie jakby ktos niedawno ostrzyl sobie na nich pazury.",
					Wilk("Wilk", Statystyki(10, 2, 2, 2, 1)),
					Przedmiot("Topor", Statystyki(0, 0, 1, 0, 0))));

				lokalizacje.push_back(Lokalizacja("Pole bitwy",
					"Na Zachodzie dostrzegasz wydeptane na drodze glebokie slady po ludzkich butach. Jednego jestes pewien, ktos bardzo obladowany musial udac sie ta droga.",
					Zbrojny("Zbrojny", Statystyki(10, 2, 2, 2, 1)),
					Przedmiot("Naszyjnik", Statystyki(0, 2, 2, 0, 0))));

				lokalizacje.push_back(Lokalizacja("Zamek",
					"Daleko na polnocy dostrzegasz ogromne ruiny, ktore kiedys musialy byc czescia zamku. Choc piekno i potega tego budynku dawno miely, masz wrazenie, ze to miejsce nie jest do konca opustoszale.",
					Wladca("Wladca", Statystyki(10, 2, 2, 2, 1)),
					Przedmiot("Kamien teleportacyjny", Statystyki(0, 0, 0, 0, 0))));
					*/
	}

	void wybierz_droge()
	{
		gracz.pobierz_statystyki();
		for (unsigned int i = 0; i < lokalizacje.size(); i++)
		{
			cout << i << ") ";
			lokalizacje[i].informacja();
			cout << endl << endl;
		}

		cout << "Dotarles do rozwidlenia " << lokalizacje.size() << " sciezek, gdzie tym razem poprowadzi Cie przeznaczenie? " << endl << endl;

		// wykorzystujemy dolaczona funkcje, posylamy maxymalna ilosc lokalizacji do wyboru, funkcja zwraca wybor gracza
		int wybor = wybierz_opcje(lokalizacje.size() - 1);

		STAN wynik = lokalizacje[wybor].wejdz_do_lokalizacji(&gracz);
		wybierz_dzialanie_wyniku(wynik, wybor);
	}

	// przekazujemy jako argumenty; stan oraz wybor lokalizacji gracza aby pozniej moc ja usunac gdy gracz wygral
	void wybierz_dzialanie_wyniku(STAN wynik, int wybor)
	{
		switch (wynik)
		{
		case WYGRANA:
		{
			koloruj_txt("(Wygrana) Ha! Zabijalem juz za mniej!", ZIELONY);

			nacisnij_klawisz();
			// zdobylismy ta lokalizacje juz, wiec usuwamy ja z listy aby wiecej nie pokazywala nam sie
			// przy wyborze sciezki
			lokalizacje.erase(lokalizacje.begin() + wybor);

			// zwiekszamy poziom gracza po wygranej walce
			gracz.zwieksz_poziom();
			koloruj_txt("Wykonano automatyczny zapis!", SELEDYNOWY);
			nacisnij_klawisz();
			sprawdz_warunki_ukonczenia_gry();
			break;
		}
		case UCIECZKA:
		{
			cout << "Udalo Ci sie bezpiecznie zawrocic" << endl;
			nacisnij_klawisz();
			break;
		}
		case PORAZKA:
			koloruj_txt("(Przegrana) Mniam mniam, powiedzial potwor jedzacy Twoje zwloki", CZERWONY);
			nacisnij_klawisz();
			exit(0);
		default:
			break;
		}
		menu_glowne();
	}

	void sprawdz_warunki_ukonczenia_gry()
	{
		if (lokalizacje.size() == 0)
		{
			cout << "Doszedles do konca swojej podrozy udalo Ci sie pokonac wszystkich przeciwnikow oraz wladce wyspy!" << endl;
			nacisnij_klawisz();
			exit(0);
		}
	}

	void menu_glowne()
	{
		system("cls");
		cout << "1) Panel bohatera" << endl;
		cout << "2) Udaj sie w droge" << endl;
		cout << "3) Wyjdz z gry" << endl;

		switch (wybierz_opcje(3, 1))
		{
		case 1:
		{
			gracz.menu();
			break;
		}
		case 2:
		{
			wybierz_droge();
			break;
		}
		case 3:
			exit(0); // definytywnie wychodzimy z gry
		}

		menu_glowne(); // zawsze wracamy do menu glownego, no chyba ze wybierzemy wyjscie z gry
	}

	void rozpocznij_gre()
	{

		cout << "1) Stworz nowa postac" << endl;
		cout << "2) Wczytaj gre" << endl;
		cout << "3) Wyjscie z gry" << endl;

		int wybor = wybierz_opcje(3, 1);
		switch (wybor)
		{
		case 1:
			stworz_postac();
			break;
		case 2:
			wczytaj_dane("gra");
			break;
		default:
			exit(0);
			break;
		}
	}

	void wyjscie()
	{
		cout << "Zegnaj";
		nacisnij_klawisz();
	}

	virtual void zapisz_dane(string nazwa_pliku)
	{
		fstream plik;
		plik.open(nazwa_pliku + "gra.txt", ios::out);

		if (plik.good() == true)
		{
			for (int i = 0; i < lokalizacje.size(); i++)
			{
				plik << lokalizacje[i].pobierz_nazwa() << " ";
				lokalizacje[i].zapisz_dane(nazwa_pliku);
			}

			string nazwa_gracza = gracz.pobierz_nazwa();
			plik << nazwa_gracza << " \n";
			gracz.zapisz_dane(nazwa_pliku);
		}

		plik.close();
	}

	virtual void wczytaj_dane(string nazwa_pliku)
	{
		fstream plik;
		plik.open(nazwa_pliku + "gra.txt", ios::in);

		if (plik.good() == true)
		{
			string nazwa_lokalizacji, nazwa_gracza;
			//plik >> nazwa_gracza;
			//gracz.wczytaj_dane(nazwa_pliku + "_" + nazwa_gracza);

			for (int i = 0; i < lokalizacje.size(); i++)
			{
				plik >> nazwa_lokalizacji;
				lokalizacje[i].wczytaj_dane(nazwa_pliku + "_" + nazwa_lokalizacji);
			}
		}
		else
			cout << "blad pliku: " + nazwa_pliku << endl;

		plik.close();
	}
};
