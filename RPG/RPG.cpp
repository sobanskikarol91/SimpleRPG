#pragma once
#include <iostream>
#include "Gra.h"
#include <ctime> // do pseudolosowych liczb
using namespace std;



int main()
{
	srand(time(NULL));	// pozwala na losowanie psueudolosowych liczb, przyda sie przy  rzucie kostka

	Gra gra;
	gra.rozpocznij_gre();
	system("pause");

	return 0;
}