#include <iostream>
#include <string>
#include "Postac.h"
#include "Szkielet.h"
#include "Lokalizacja.h"
#include "Przeciwnik.h"
#include <list>

using namespace std;

#pragma once
class Gra
{
public:
	list<Lokalizacja> lista_lokalizacji;

	void stworz_postac()
	{
		string nazwa;

		cout << "Stworz nowa postac: " << endl;
		cin >> nazwa;
		Postac postac = Postac(nazwa, 2, 2, 2, 2, 0);
		postac.informacja();
	}

	void stworz_lokalizacje()
	{
		lista_lokalizacji.push_back(Lokalizacja("cmentarz", Szkielet("Szkielet", 10, 4, 4, 4, 2)));
	}



	void zapisz() {};
	void wczytaj() {};
	void ruch() {};
};
