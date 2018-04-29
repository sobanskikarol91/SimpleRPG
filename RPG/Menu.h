#pragma once
#include "Dodatki.h" // dolaczamy do klasy dodatki, ktore przydadza sie do tworzenia menu

// abstrakcyjna klasa, w  wtkorzystana np. w graczu i ekwipunku, gdzie bedziemy implementowac inaczej virtualna metode menu;

class Menu
{
public:
	virtual void menu() = 0;
};

