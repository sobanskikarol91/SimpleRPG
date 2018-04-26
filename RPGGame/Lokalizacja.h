#include <iostream>
#include "Postac.h"
using namespace std;

#pragma once
class Lokalizacja
{
	Postac przeciwnik;
	string nazwa;
public:
	Lokalizacja() {};
	Lokalizacja(string nazwa, Postac przeciwnik): nazwa(nazwa), przeciwnik(przeciwnik){}

};

