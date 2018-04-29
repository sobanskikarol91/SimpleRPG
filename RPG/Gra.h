#include <iostream>
#include <string>
#include <vector>
#include "Gracz.h"
#include "Bron.h"
#include "Lokalizacja.h"
#include "Szkielet.h"
#include "Wilk.h"
#include "Wladca.h"
#include "Zbrojny.h"
#include "Bandyta.h"
#include "Amulet.h"
#include "Pancerz.h"
#include "Stan.h" // pozwala na przeslanie wiadomosci zwrotnej, wyboru gracza z lokalizacji
#include "Dodatki.h"
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

		cout << "Stworz nowa postac" << endl << "Imie Twojego bohatera brzmi: ";
		cin >> nazwa;

		// wywolujemy konstruktor gracza podajac odpowiednie parametry
		Ekwipunek ekwipunek;
		ekwipunek.dodaj_przedmiot(Bron("Miecz", 5));
		ekwipunek.dodaj_przedmiot(Bron("Topor", 5));
		gracz = Gracz(nazwa, 20, 20, 20, 20, 10, ekwipunek);
	}

	// Tworzymy lokalizacje nadajac im nazwe, opis, i potwora jaki strzerze to miejsce i przedmiot do zdobycia
	void stworz_lokalizacje()
	{
		lokalizacje.push_back(Lokalizacja("Krypta",
			"Na samym srodku sciezki, dostrzegasz schody prowadzace w dol. Wyczuwasz potezna, mroczna, aure bijaca z czelusci tej sciezki. Krzewy i drzewa zdaja sie byc obumarle, a w zasiegu wzroku gesto scieli sie truchlo martwych zwierzat i rozsypane kosci",
			Szkielet("Szkielet", 10, 4, 4, 4, 2),
			Pancerz("Helm", 10)));

		lokalizacje.push_back(Lokalizacja("Trakt kupiecki",
			"Spogladajac na polnocny wschod widzisz martwego czlowieka, ktory lezy we wlasnej krwi, praktycznie bez odzienia. Na trawie dostrzegasz slady walki oraz rozerwany, mieszek zlota. ",
			Bandyta("Bandyta", 10, 4, 4, 4, 2),
			Pancerz("Zbroja", 10)));

		lokalizacje.push_back(Lokalizacja("Las",
			"Patrzac na polnocny zachod, dostrzegasz gesty las. Drzewa sa poranione i ociekajace zywica. Masz wrazenie jakby ktos niedawno ostrzyl sobie na nich pazury.",
			Wilk("Wilk", 10, 4, 4, 4, 2),
			Bron("Miecz", 10)));

		lokalizacje.push_back(Lokalizacja("Pole bitwy",
			"Na Zachodzie dostrzegasz wydeptane na drodze glebokie slady po ludzkich butach. Jednego jestes pewien, ktos bardzo obladowany musial udac sie ta droga.",
			Zbrojny("Zbrojny", 10, 4, 4, 4, 2),
			Amulet("Naszyjnik", 5)));

		lokalizacje.push_back(Lokalizacja("Zamek",
			"Daleko na polnocy dostrzegasz ogromne ruiny, ktore kiedys musialy byc czescia zamku. Choc piekno i potega tego budynku dawno miely, masz wrazenie, z to miejsce nie jest do konca opustoszale.",
			Wladca("Wladca", 10, 4, 4, 4, 2),
			Amulet("Kamien teleportacyjny")));
	}

	void wybierz_droge()
	{
		gracz.statystyki();
		for (int i = 0; i < lokalizacje.size(); i++)
		{
			cout << i << ") ";
			lokalizacje[i].informacja();
			cout << endl << endl;
		}

		cout << "Dotarles do rozwidlenia " << lokalizacje.size() << " sciezek, gdzie tym razem poprowadzi Cie przeznaczenie? " << endl << endl;
		
		// wykorzystujemy dolaczona funkcje, posylamy maxymalna ilosc lokalizacji do wyboru, funkcja zwraca wybor gracza
		int wybor = wybierz_opcje(lokalizacje.size());

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
			cout << "(Wygrana) Ha! Zabijalem juz za mniej!" << endl;

			// zdobylismy ta lokalizacje juz, wiec usuwamy ja z listy aby wiecej nie pokazywala nam sie
			// przy wyborze sciezki
			lokalizacje.erase(lokalizacje.begin() + wybor);

			// zwiekszamy poziom gracza po wygranej walce
			gracz.zwieksz_poziom();
			nacisnij_klawisz();
			wybierz_droge();
			break;
		}
		case UCIECZKA:
		{
			cout << "Udalo Ci sie bezpiecznie zawrocic" << endl;
			nacisnij_klawisz();
			wybierz_droge();
			break;
		}
		case PORAZKA:
			cout << "(Przegrana) Mniam mniam, powiedzial potwor jedzacy Twoje cialo" << endl;
			break;
		default:
			break;
		}
	}

	void menu_glowne()
	{
		system("cls");
		cout << "1) Panel bohatera" << endl;
		cout << "2) Udaj sie w droge" << endl;
		cout << "3) Wyjdz z gry" << endl;

		switch (wybierz_opcje(3,1))
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
		}
	}

	void rozpocznij_gre()
	{
		stworz_postac();
		menu_glowne();
	}
	void zapisz() {};
	void wczytaj() {};

	void wyjscie()
	{
		cout << "Zegnaj";
	}
};
