#pragma once
#include <iostream>
#include <string>
using namespace std;

class Przedmiot
{
private:
	string nazwa;
public:
	Przedmiot() {};
	Przedmiot(string nazwa): nazwa(nazwa) {};

	void zaloz();

	string informacja()
	{
		return nazwa;
	}
};


