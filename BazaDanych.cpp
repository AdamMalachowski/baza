#include "BazaDanych.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using std::cout;
using std::to_string;
using std::sort;
using std::find;
using std::getline;
using std::string;
using std::fstream;
using std::ofstream;
using std::ifstream;

string BazaDanych::generujPesel()
{
	string pesel = "";
	for (unsigned i = 0; i < 11; i++)
	{
		auto cyfra = to_string(rand() % 10);
		pesel.append(cyfra);
	}
	return pesel;
}

BazaDanych::BazaDanych()
{
	srand(time(NULL));
	_osoby = vector<Czlowiek*>();
	_serwis = new SerwisOsobowy();
}

Czlowiek* BazaDanych::SzukajPoNazwisku(string nazwisko)
{
	for (unsigned i = 0; i < _osoby.size(); i++)
	{
		if (_osoby.at(i)->Nazwisko() == nazwisko)
		{
			return _osoby.at(i);
		}
	}
	Czlowiek* brak(new Czlowiek);
	return brak;
}

Czlowiek* BazaDanych::SzukajPoPeselu(string pesel)
{
	for (unsigned i = 0; i < _osoby.size(); i++)
	{
		if (_osoby.at(i)->Pesel() == pesel)
		{
			return _osoby.at(i);
		}
	}
	Czlowiek* brak(new Czlowiek);
	return brak;
}

void BazaDanych::wyswietl()
{
	for (unsigned i = 0; i < _osoby.size(); i++)
	{
		_osoby.at(i)->Wyswietl();
	}
}

bool static PorownajPesel(Czlowiek* i, Czlowiek* j)
{
	return i->Pesel().compare(j->Pesel()) < 0;
}

bool static PorownajZarobki(Czlowiek* i, Czlowiek* j)
{
	return i->Zarobki() < j->Zarobki();
}

bool static PorownajNazwisko(Czlowiek* i, Czlowiek* j)
{
	return i->Nazwisko().compare(j->Nazwisko()) < 0;
}

vector<Czlowiek*> BazaDanych::Sortuj(Sortowanie rodzajSortowania)
{
	switch (rodzajSortowania)
	{
	case NAZWISKO:
		sort(_osoby.begin(), _osoby.end(), PorownajNazwisko);
		break;
	case PESEL:
		sort(_osoby.begin(), _osoby.end(), PorownajPesel);
		break;
	case ZAROBKI:
		sort(_osoby.begin(), _osoby.end(), PorownajZarobki);
		break;
	}
	return _osoby;
}

void BazaDanych::WypelnijBaze()
{
	for (auto i = 0; i < 100; i++)
	{
		if (i % 2 == 0)
		{
			_osoby.push_back(_serwis->Nowy_pracownik("pracownik " + to_string(i), "nazwisko_pracownika", generujPesel(),
			                                         Plec::MEZCZYZNA, "adres", i * 10 + 50));
		}
		else
		{
			_osoby.push_back(_serwis->Nowy_student("student " + to_string(i), "nazwisko_studenta", generujPesel(),
			                                       Plec::MEZCZYZNA,
			                                       "adres", "index"));
		}
	}
	_osoby.push_back(_serwis->Nowy_pracownik("pracownik " + to_string(1111), "nazwisko_pracownika", "72958257106",
	                                         Plec::MEZCZYZNA, "adres", 222));
}

void BazaDanych::Wczytaj(string lokalizacjaPliku)
{
	ifstream file(lokalizacjaPliku + "BAZA.cor");
	string line;
	while (getline(file, line))
	{
		string rodzajOsoby = line;
		string pole;
		vector<string> pola;

		for (unsigned i = 0; i < 6; i++)
		{
			getline(file, pole);
			pola.push_back(pole);
		}

		if (rodzajOsoby.find("<student>") != string::npos)
		{
			Student* nowy_student(new Student());
			nowy_student->Deserializuj(pola);
			_osoby.push_back(nowy_student);
		}
		if (rodzajOsoby.find("<pracownik>") != string::npos)
		{
			Pracownik* nowy_pracownik(new Pracownik());
			nowy_pracownik->Deserializuj(pola);
			_osoby.push_back(nowy_pracownik);
		}
	}
}

void BazaDanych::Zapisz(string lokalizacjaPliku)
{
	ofstream bazaPlik;
	bazaPlik.open(lokalizacjaPliku + "BAZA.cor");
	for (unsigned i = 0; i < _osoby.size(); i++)
	{
		bazaPlik << _osoby.at(i)->Serializuj();
	}
	bazaPlik.close();
}

void BazaDanych::Usun(string pesel)
{
	for (auto it = _osoby.begin(); it != _osoby.end(); ++it)
	{
		Czlowiek* osoba(*it);
		if (osoba->Pesel() == pesel)
		{
			_osoby.erase(it);
			break;
		}
	}
}

bool BazaDanych::ZmienZarobki(string pesel, int zarobki)
{
	Czlowiek* znaleziony = SzukajPoPeselu(pesel);
	if (znaleziony->Nazwisko().length() > 0)
	{
		if (znaleziony->Rodzaj() == PRACOWNIK)
		{
			((Pracownik*)znaleziony)->ZmienZarobki(zarobki);
			return true;
		}
	}
	return false;
}

bool BazaDanych::ZmienAdres(string pesel, string adres)
{
	Czlowiek* znaleziony = SzukajPoPeselu(pesel);
	if (znaleziony->Nazwisko().length() > 0)
	{
		znaleziony->ZmienAdres(adres);
		return true;
	}
	return false;
}

bool BazaDanych::CzyPoprawnyPesel(string pesel)
{
	if (pesel.length() != 11)
	{
		return false;
	}

	for (unsigned i = 0; i < pesel.length(); i++)
	{
		if (isdigit(pesel[i]) == 0)
		{
			return false;
		}
	}

	return true;
}
