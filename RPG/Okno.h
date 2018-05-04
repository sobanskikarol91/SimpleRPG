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
	Okno();
	Okno(string nazwa_obrazka);

	void wyswietl();
	void draw(RenderTarget & target, RenderStates state) const;
};
