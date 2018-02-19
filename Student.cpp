#include "Student.h"
#include <iostream>

using std::cout;
using std::endl;

Student::Student()
{
}

Student::Student(string im, string naz, string pe, Plec pl, string adr, string nr_i):
	Czlowiek(im, naz, adr, pe, pl),
	numer_indexu(nr_i)
{
	Czlowiek::rodzaj = STUDENT;
}

void Student::Wyswietl()
{
	Czlowiek::Wyswietl();
	cout << " INDEX: " << numer_indexu << " " << endl;
}

string Student::Serializuj()
{
	string obiekt = "<student>\n" + Czlowiek::Serializuj();
	obiekt+= numer_indexu + "\n";
	return obiekt;
}

void Student::Deserializuj(vector<string> obiekt)
{
	Czlowiek::Deserializuj(obiekt);
	numer_indexu = obiekt.at(5);
}

Student::~Student()
{
}
