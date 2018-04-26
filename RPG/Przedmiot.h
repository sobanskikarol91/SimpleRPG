#pragma once
#include <iostream>
#include <string>
using namespace std;

class Przedmiot
{
	string opis;
public:
	Przedmiot();
	void podnies();
	void wyrzuc();
	void zaloz();

	void informacja()
	{
		cout << opis << endl;
	}
};

