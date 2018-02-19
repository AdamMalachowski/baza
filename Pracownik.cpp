#include "Pracownik.h"
#include <iostream>

using std::cout;
using std::endl;
using std::to_string;
using std::stoi;

Pracownik::Pracownik()
{
}

Pracownik::Pracownik(string im, string naz, string pe, Plec pl, string adr, int zar):
	Czlowiek(im, naz, adr, pe, pl),
	zarobki(zar)
{
	Czlowiek::rodzaj = PRACOWNIK;
}

void Pracownik::Wyswietl()
{
	Czlowiek::Wyswietl();
	cout << " ZAROBKI: " << zarobki << " " << endl;
}

int Pracownik::Zarobki()
{
	return zarobki;
}

void Pracownik::ZmienZarobki(int nowa_wartosc)
{
	zarobki = nowa_wartosc;
}

string Pracownik::Serializuj()
{
	string obiekt = "<pracownik>\n" + Czlowiek::Serializuj();
	obiekt += to_string(zarobki) + "\n";
	return obiekt;
}

void Pracownik::Deserializuj(vector<string> obiekt)
{
	Czlowiek::Deserializuj(obiekt);
	zarobki = stoi(obiekt.at(5));
}
