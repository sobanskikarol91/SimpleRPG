#include <iostream>
#include <string>
#include "Gracz.h"
#include "Lokalizacja.h"
#include "Szkielet.h"
#include "Wilk.h"
#include "Wladca.h"
#include "Zbrojny.h"
#include "Bandyta.h"
#include <vector>
using namespace std;

#pragma once
class Gra
{
public:
	// spis wszystkich lokalizacji w grze
	vector <Lokalizacja> lokalizacje;

	void stworz_postac()
	{
		string nazwa;

		cout << "Stworz nowa postac" << endl << "Imie Twojego bohatera brzmi: ";
		cin >> nazwa;
		Gracz gracz = Gracz(nazwa, 2, 2, 2, 2, 1);
		gracz.informacja();
	}

	// Tworzymy lokalizacje nadajac im nazwe, opis, i potwora jaki strzerze to miejsce
	void stworz_lokalizacje()
	{
		lokalizacje.push_back(Lokalizacja("krypta",
			"Na samym srodku scie¿ki, dostrzegasz schody prowadzace w dol. Wyczuwasz potezna, mroczna, aure bijaca z czelusci tej sciezki. Krzewy i drzewa zdaja sie byc obumarle, a w zasiegu wzroku gesto scieli sie truchlo martwych zwierzat i rozsypane kosci",
			Szkielet("Szkielet", 10, 4, 4, 4, 2)));

		lokalizacje.push_back(Lokalizacja("las",
			"Patrzac na polnocny zachod, dostrzegasz gesty las. Drzewa sa poranione i ociekajace zywica. Masz wrazenie jakby ktos niedawno ostrzyl sobie na nich pazury.",
			Wilk("Wilk", 10, 4, 4, 4, 2)));

		lokalizacje.push_back(Lokalizacja("zamek",
			"Daleko na pó³nocy dostrzegasz ogromne ruiny, które kiedyœ musia³y byæ czescia zamku. Choæ piêkno i potêga tego budynku dawno miely, masz wrazenie, z to miejsce nie jest do konca opustoszale.",
			Wladca("Wilk", 10, 4, 4, 4, 2)));

		lokalizacje.push_back(Lokalizacja("zamek",
			"Spogladajac na polnocny wschod widzisz martwego czlowieka, ktory lezy we wlasnej krwi, praktycznie bez odzienia. Na trawie dostrzegasz slady walki oraz rozerwany, mieszek zlota. ",
			Bandyta("Wilk", 10, 4, 4, 4, 2)));

		lokalizacje.push_back(Lokalizacja("zamek",
			"Na Zachodzie dostrzegasz wydeptane na drodze glebokie slady po ludzkich butach. Jednego jestes pewien, ktos bardzo obladowany musial udac sie ta droga.",
			Zbrojny("Zbrojny", 10, 4, 4, 4, 2)));
	}

	void zapisz() {};
	void wczytaj() {};
	void ruch() {};
};
