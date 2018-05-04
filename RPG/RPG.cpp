#pragma once

#include <iostream>
#include "Gra.h"
#include <ctime> // do pseudolosowych liczb
using namespace std;

// test
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace sf; // do sfmla



void rysuj()
{
	RenderWindow window{ VideoMode{ 1000,1000 }, "RPG" };
	window.setFramerateLimit(60); // 60 klatek na sekunde
	Event event; // interakcja myszy z ekranem
	Texture wilk;

	cout << "s";
	if (!wilk.loadFromFile("grafika/wilk.jpg"))
		cout << "Nie udalo sie wczytac obrazka";
	Sprite wilkSprite;
	wilkSprite.setTexture(wilk);



	while (true)
	{
		window.clear(Color::Black); // wypelnij na czarno ekran
		window.draw(wilkSprite);
		window.pollEvent(event);

		// gdy gracz nacisnal zamkniecie okna
		if (event.type == Event::Closed)
		{
			window.close();
			break;
		}
		window.display(); // wyswietl narysowane obiekty
	}
}

int main()
{
	srand(time(NULL));	// pozwala na losowanie psueudolosowych liczb, przyda sie przy rzucie kostka

	rysuj();

	Gra gra;
	gra.rozpocznij_gre();
	system("pause");

	return 0;
}