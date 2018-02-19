#pragma once
#include "Czlowiek.h"

class Pracownik : public Czlowiek
{
private:
	int zarobki;
public:
	Pracownik();
	Pracownik(string im, string naz, string pe, Plec pl, string adr, int zar);
	void Wyswietl() override;
	int Zarobki() override;
	void ZmienZarobki(int nowa_wartosc);
	string Serializuj() override;
	void Deserializuj(vector<string> obiekt) override;
};
