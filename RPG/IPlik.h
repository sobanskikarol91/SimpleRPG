#pragma once
#include <string>
// interfejs, posiada tylko czysto wirtualne metody do implementacji
class IPlik
{
public:
	virtual void wczytaj_dane(std::string nazwa_pliku) = 0;
	virtual void zapisz_dane(std::string nazwa_pliku) = 0;
};

