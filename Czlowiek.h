#pragma once
#include <string>
#include "Plec.h"
#include <vector>
#include "RodzajCzlowieka.h"

using std::string;
using std::vector;

class Czlowiek
{
protected:
	string imie;
	string nazwisko;
	string adres;
	string pesel;
	Plec plec;
	RodzajCzlowieka rodzaj;

public:
	Czlowiek();
	Czlowiek(string im, string naz, string adr, string pe, Plec pl);
	string Nazwisko();
	string Pesel();
	virtual void Wyswietl();
	virtual int Zarobki();
	void ZmienAdres(string nowyAdres);
	RodzajCzlowieka Rodzaj();
	virtual string Serializuj();
	virtual void Deserializuj(vector<string> obiekt);
	~Czlowiek();
};
