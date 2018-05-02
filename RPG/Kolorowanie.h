#pragma once
#include <Windows.h> // pozwala kolorowac skladnie
#include <string>
#include <iostream>
using namespace std;

// enum przyda sie jako kolor, ktory bedziemy chcieli wybrac do kolorowania skladni dla ponizszej funkcji
enum KOLOR { ZIELONY = 10, SELEDYNOWY = 11, CZERWONY = 12, ZOLTY = 14 };

// sluzy do kolorowania i wypisywania tekstu jaki wysylamy jako parametr domyslnie zawsze ebdzie enter po tekscie
static void koloruj_txt(string tekst, KOLOR kolor, bool enter = true)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolor); // koloruj  
	cout << tekst;

	if (enter)  cout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ZOLTY);    // koloruj  na zolto
}

// od tego czasu skladnia w konsoli bedize koloowana wedlug wybranego koloru
static void zmien_kolor_txt(KOLOR kolor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolor); // koloruj  na  wybrany kolor
}

// kolorujemy tylko dodatnie wartosci przyda sie przy statystykach przedmiotow aby wyroznic te wieksze od 0
static void koloruj_dodatnie(int wartosc, KOLOR kolor = ZIELONY)
{
	if (wartosc > 0)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolor); // koloruj  na zielono

	cout << wartosc << " ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ZOLTY);    // koloruj  na zolto
}

