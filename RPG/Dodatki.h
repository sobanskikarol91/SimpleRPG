#pragma once
#include<iostream>
using namespace std;

// metoda ma jedynie za zadanie zatrzymac ekran do momentu az gracz wcisnie klawisz
// uzywamy jej w wielu klasach dlatego jest statyczna 
static void nacisnij_klawisz()
{
	int wybor;
	cout << "nacisnij klawisz aby przejsc dalej" << endl;
	cin >> wybor;
	system("cls"); // czyscimy ekran
}

// bedziemy czesto wybierac rozne opcje z menu dlatego tworzymy jedna funkcje statyczna
// zwracamy wybrana opcje
static bool wybierz_opcje(int max, int min = 0)
{
	int wybor;

	// nieskonczona petla wykonuje sie dopoki gracz wprowadza bledne dane
	while (1)
	{
		int wybor;
		cin >> wybor;

		if (wybor < min || wybor >= max) 	// wykonujemy program do chwli az gracz poda poprawna wartosc
			cout << "Wybrales bledna opcje! Wprowadz dane jeszcze raz! " << endl;
		else
		{
			system("cls");
			return wybor; // gracz wprowadzil poprawnie dane zwroc je
		}
	}
}
