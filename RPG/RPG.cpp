#pragma once

#include <iostream>
#include "Gra.h"
#include <ctime> // do pseudolosowych liczb
using namespace std;

// test
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Przedmiot.h"
using namespace sf; // do sfmla




int main()
{
	srand(time(NULL));	// pozwala na losowanie psueudolosowych liczb, przyda sie przy rzucie kostka

	Gra gra;
	gra.rozpocznij_gre();
	system("pause");

	return 0;
}