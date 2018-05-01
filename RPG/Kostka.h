#include <cstdlib> // do losowania rand()

#pragma once
class Kostka
{
	int min;
	int max;
public:
	Kostka() {};
	// tutaj mozna zrobic warunek sprawdzajacy czy min to min i max to max
	// bo uzytkownik mogl podac zle, ale nie bedziemy utrudniac.
	Kostka(int min, int max) : min(min), max(max) {};
	
	int losuj()
	{
		return (rand() % max - min ) + min;
	}
};

