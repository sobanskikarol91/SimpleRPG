#include "Postac.h"

Postac::Postac() :nazwa("Bezimienny") {};
// konstruktor z lista inicjalizacyjna sluzacy do tworzenia postaci 
Postac::Postac(string nazwa, Statystyki statystyki) :
	nazwa(nazwa), statystyki(statystyki) {}

void Postac::informacje()
{
	cout << nazwa << endl;
	statystyki.informacja();
}

int Postac::modyfikator_obrazen()
{
	Kostka kostka(1, 3);
	return kostka.losuj();
}