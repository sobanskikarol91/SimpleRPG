#pragma once

#define NOMINMAX   // windows.h clashes with the STL, which frankly is a problem with windows.h.
#include <iostream>
#include "Gra.h"
#include <ctime> // do pseudolosowych liczb
using namespace std;

// test
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace sf; // do sfmla

int main()
{
	//srand(time(NULL));	// pozwala na losowanie psueudolosowych liczb, przyda sie przy  rzucie kostka

	RenderWindow window{ VideoMode{800,600}, "RPG" };
	window.setFramerateLimit(60); // 60 klatek na sekunde
	Event event; // interakcja myszy z ekranem

	while (true)
	{
		window.clear(Color::Black); // wypelnij na czarno ekran
		window.pollEvent(event);
		window.display(); // wyswietl narysowane obiekty

	}

	//Gra gra;
	//gra.rozpocznij_gre();
	//system("pause");

	return 0;
}