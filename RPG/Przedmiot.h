#pragma once
#include <iostream>
#include <string>
using namespace std;

class Przedmiot
{
private:
	string nazwa;
	bool wyposazony; // czy gracz aktualnie wykorzystuje przedmiot
public:
	Przedmiot() {};
	Przedmiot(string nazwa): nazwa(nazwa) {};

	void zaloz();

	string informacja()
	{
		return nazwa;
	}

	bool sprawdz_czy_wyposazony() { return wyposazony; }
	void ustaw_wyposazony(bool stan) { wyposazony = stan; }	
};


