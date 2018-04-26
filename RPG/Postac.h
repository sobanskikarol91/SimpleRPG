#include <iostream>
#include <string>
using namespace std;

#pragma once
class Postac
{
private:
	string nazwa;
	int zycie, sila, zrecznosc, obrazenia, poziom;

public:
	Postac() {};
	// konstruktor z lista inicjalizacyjna sluzacy do tworzenia postaci 
	Postac(string nazwa, int zycie, int sila, int zrecznosc, int obrazenia, int poziom) :
		nazwa(nazwa), zycie(zycie), sila(sila), zrecznosc(zrecznosc), obrazenia(obrazenia), poziom(poziom) {}

	void informacja()
	{
		cout << "=======================================================================================================================" << endl;
		cout << nazwa << "   ";
		cout << "Poziom: " << poziom << "   ";
		cout << "Hp: " << zycie << "   ";
		cout << "Sila: " << sila << "   ";
		cout << "Zrecznosc: " << zrecznosc << "   ";
		cout << "Obrazenia: " << obrazenia << "   " << endl;
		cout << "=======================================================================================================================" << endl;
	}
};