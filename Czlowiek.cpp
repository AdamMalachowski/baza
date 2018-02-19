#include "Czlowiek.h"
#include <iostream>

using std::cout;

Czlowiek::Czlowiek()
{
}

Czlowiek::Czlowiek(string im, string naz, string adr, string pe, Plec pl):
	imie(im),
	nazwisko(naz),
	adres(adr),
	pesel(pe),
	plec(pl)
{
}

string Czlowiek::Nazwisko()
{
	return nazwisko;
}

string Czlowiek::Pesel()
{
	return pesel;
}

void Czlowiek::Wyswietl()
{
	cout << "IMIE: " << imie << " NAZWISKO: " << nazwisko << " ADRES: ";
	cout << adres << " PESEL: " << pesel << " PLEC: ";
	if (plec == MEZCZYZNA)
	{
		cout << "M" << " ";
	}
	else
	{
		cout << "K" << " ";
	}
}

int Czlowiek::Zarobki()
{
	return 0;
}

void Czlowiek::ZmienAdres(string nowyAdres)
{
	adres = nowyAdres;
}

RodzajCzlowieka Czlowiek::Rodzaj()
{
	return rodzaj;
}

string Czlowiek::Serializuj()
{
	string obiekt = "";
	obiekt += imie + "\n";
	obiekt += nazwisko + "\n";
	obiekt += adres + "\n";
	obiekt += pesel + "\n";
	if (plec == KOBIETA)
	{
		obiekt += "K\n";
	}
	else
	{
		obiekt += "M\n";
	}
	return obiekt;
}

void Czlowiek::Deserializuj(vector<string> obiekt)
{
	imie = obiekt.at(0);
	nazwisko = obiekt.at(1);
	adres = obiekt.at(2);
	pesel = obiekt.at(3);
	if (obiekt.at(4) == "M")
	{
		plec = MEZCZYZNA;
	}
	else
	{
		plec = KOBIETA;
	}
}


Czlowiek::~Czlowiek()
{
}
