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
using namespace std;

#pragma once
class Gra
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
		gracz = Gracz(nazwa, Statystyki(10,2,2,2,1), ekwipunek);
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
			koloruj_txt("(Wygrana)Ha!Zabijalem juz za mniej!", ZIELONY);

			nacisnij_klawisz();
			// zdobylismy ta lokalizacje juz, wiec usuwamy ja z listy aby wiecej nie pokazywala nam sie
			// przy wyborze sciezki
			lokalizacje.erase(lokalizacje.begin() + wybor);

			// zwiekszamy poziom gracza po wygranej walce
			gracz.zwieksz_poziom();
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
			koloruj_txt("(Przegrana) Mniam mniam, powiedzial potwor jedzacy Twoje cialo",CZERWONY);
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
		stworz_postac();
		menu_glowne();
	}

	void zapisz() 
	{
		fstream plik("zapis.txt", std::ios::out);

		if (plik.good()) // sprawdzenie czy udalo sie uzyskac dostep do pliku
		{
			for (int i = 1; i <= 100; i++)
			{
				plik << i << ", ";
				plik.flush();
			}
			plik.close();
		}
	}

	void wczytaj() {};

	void wyjscie()
	{
		cout << "Zegnaj";
		nacisnij_klawisz();
	}
};
