#pragma once
#include "Czlowiek.h"

class Student :
	public Czlowiek
{
private:
	string numer_indexu;
public:
	Student();
	Student(string im, string naz, string pe, Plec pl, string adr, string nr_i);
	void Wyswietl() override;
	string Serializuj() override;
	void Deserializuj(vector<string> obiekt) override;
	~Student();
};
