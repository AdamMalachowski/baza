#include <iostream>
#include <vector>
#include "Czlowiek.h"
#include "BazaDanych.h"

int main()
{
	BazaDanych* baza = new BazaDanych();
	//baza->WypelnijBaze();
	//baza->wyswietl();

	//auto szukaj = baza->SzukajPoPeselu("72958257106");
	//baza->Usun("72958257106");
	//baza->wyswietl();
	//baza->Zapisz("E:\\");
	baza->Wczytaj("E:\\");
	baza->wyswietl();
	baza->ZmienZarobki("79058814371", 120);
	baza->Sortuj(PESEL);
	baza->wyswietl();
	system("pause");
	return 0;
}
