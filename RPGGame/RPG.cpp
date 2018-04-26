#include <iostream>
#include "Gra.h"
#include <ctime> // do pseudolosowych liczb
using namespace std;


void menu()
{
	cout << "1) Nowa gra" << endl;
	cout << "2) Wczytaj grê" << endl;
	cout << "3) Exit" << endl;

	int wybor;
	cin >> wybor;

	switch (wybor)
	{
	default:
		break;
	}
}

void rozpocznij_gre()
{
	// TODO Sleep

}

void sprawdzenie_ekwipunku()
{

}

void wybor_drogi_txt()
{
	int wybor;

	cout << "Dotarles do rozwidlenia 5 sciezek, gdzie tym razem poprowadzi Cie przeznaczenie? " << endl;
	cout << "1) Na samym srodku dostrzegasz schody prowadzace w dol. Wyczuwasz potezna, mroczna, aure bijaca z czelusci tej sciezki. Krzewy i drzewa zdaja sie byc obumarle, a w zasiegu wzroku gesto scieli sie truchlo martwych zwierzat" << endl;
	cout << "2) Na Polnocy dostrzegasz na drodze glebokie slady po ludzkich butach. Jednego jestes pewien, ktos bardzo obladowany musial udac sie ta droga." << endl;
	cout << "3) Patrzac na polnocny zachod, dostrzegasz gesty las. Drzewa sa poranione i ociekajace zywica. Masz wrazenie jakby ktos niedawno ostrzyl sobie na nich pazury." << endl;
	cout << "4) Spogladajac na polnocny wschod widzisz martwego czlowieka, ktory lezy we wlasnej krwi, praktycznie bez odzienia. Na trawie dostrzegasz slady walki oraz rozerwany, mieszek zlota. " << endl;
	cout << "5) Krypta" << endl;
}

int main()
{
	wybor_drogi_txt();
	//Gra  gra_rpg;
	//gra_rpg.stworz_postac();

	srand(time(NULL));	// pozwala na losowanie psueudolosowych liczb, przyda sie przy losowaniu statystyk
	system("pause");
	return 0;
}