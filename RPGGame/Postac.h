#include <iostream>
#include <string>
using namespace std;

#pragma once
class Postac
{
private:
	string nazwa;
	int zycie;
	int sila;
	int zrecznosc;
	int obrazenia;
	int poziom;

public:
	Postac();
	/*Postac(string nazwa, int min, int max)
	{
		int zycie = 2* losuj_atrybut(min,max);
		int sila = 2 * losuj_atrybut(min, max);
		int zrecznosc = 2 * losuj_atrybut(min, max);
		int obrazenia = 2 * losuj_atrybut(min, max);
		int poziom = 2 * losuj_atrybut(min, max);
		int wylosowana_liczba = 2 * losuj_atrybut(min, max);
	}*/

	int losuj_atrybut(int min, int max)
	{
		(std::rand() % (max - min)) + min;
	}
	Postac(string nazwa, int zycie, int sila, int zrecznosc, int obrazenia, int poziom) :
		nazwa(nazwa), zycie(zycie), sila(sila), zrecznosc(zrecznosc), obrazenia(obrazenia), poziom(poziom) {}

	void informacja()
	{
		cout << "Nazwa: " << nazwa << endl;
		cout << "Zycie: " << zycie << endl;
		cout << "Sila: " << sila << endl;
		cout << "Zrecznosc: " << zrecznosc << endl;
		cout << "Obrazenia: " << obrazenia << endl;
		cout << "Poziom: " << poziom << endl;
	}

	~Postac();
};

