#pragma once
#include <string>
using namespace std;
// Klasy abstrakcyjne jako interfejsy
class IPlik
{
public:
	virtual void zapisz_dane(string nazwa_pliku) = 0;
	virtual void wczytaj_dane(string nazwa_pliku) = 0;
};

