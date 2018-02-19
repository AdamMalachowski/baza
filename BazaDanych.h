#pragma once
#include <vector>
#include <memory>
#include "Czlowiek.h"
#include "Sortowanie.h"
#include "SerwisOsobowy.h"

using std::vector;
using std::shared_ptr;

class BazaDanych
{
private:
	vector<Czlowiek*> _osoby;
	SerwisOsobowy* _serwis;

	string generujPesel();
public:
	BazaDanych();
	Czlowiek* SzukajPoNazwisku(string nazwisko);
	Czlowiek* SzukajPoPeselu(string pesel);
	void wyswietl();
	vector<Czlowiek*> Sortuj(Sortowanie rodzajSortowania);
	void WypelnijBaze();
	void Wczytaj(string lokalizacjaPliku);
	void Zapisz(string lokalizacjaPliku);
	void Usun(string pesel);
	bool ZmienZarobki(string pesel, int zarobki);
	bool ZmienAdres(string pesel, string adres);
	bool CzyPoprawnyPesel(string pesel); 
};
