#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf; // do sfmla
using namespace std;


class Okno : public Drawable // dziedziczymy po interfejsie rysowania
{
	Texture texture;
	Sprite sprite;
	string nazwa_obrazka;

public:
	Okno() : nazwa_obrazka("Nieznana") {};
	Okno(string nazwa_obrazka) :nazwa_obrazka(nazwa_obrazka){}

	void wyswietl()
	{
		if (!texture.loadFromFile("grafika/" + nazwa_obrazka + ".png")) // wczytaj teksture o danej nazwie z folderu grafika
			cout << "Nie udalo sie wczytac tekstury " << nazwa_obrazka;

		sprite.setTexture(texture);
		
		
		RenderWindow window{ VideoMode{ texture.getSize().x,texture.getSize().y }, "RPG" };
		window.setFramerateLimit(60); // 60 klatek na sekunde
		Event event; // interakcja myszy z ekranem

		while (true)
		{
			window.clear(Color::Black); // wypelnij na czarno ekran
			window.draw(*this);   // rysujemy obecny obiekt tak jak to zaimplementowalismy w metodzie draw
			window.pollEvent(event);

			// gdy gracz nacisnal zamkniecie okna, albo nacisnal jakis klawisz
			if (event.type == Event::Closed || event.type == Event::KeyPressed)
			{
				window.close();
				break;
			}
			window.display(); // wyswietl narysowane obiekty
		}
	}


	void draw(RenderTarget & target, RenderStates state) const
	{
		// rysuj sprite
		target.draw(this->sprite, state);
	}
};
