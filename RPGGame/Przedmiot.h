#pragma once
class Przedmiot
{
	enum TYP { Helm, Zbroja, Miecz, Topor, Amulet };
	TYP typ;
public:
	Przedmiot();
	void podnies();
	void wyrzuc();
	void zaloz();
};

