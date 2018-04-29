#include <iostream>
#include "Gra.h"
#include <ctime> // do pseudolosowych liczb
using namespace std;

int main()
{
	Gra gra;
	gra.stworz_postac();
	gra.menu_glowne();
	srand(time(NULL));	// pozwala na losowanie psueudolosowych liczb, przyda sie przy  rzucie kostka
	system("pause");
	return 0;
}