#include "SerwisOsobowy.h"



SerwisOsobowy::SerwisOsobowy()
{
}

Pracownik* SerwisOsobowy::Nowy_pracownik(string im, string naz, string pe, Plec pl, string adr, int zar)
{
	Pracownik* nowy(new Pracownik(im, naz, pe, pl, adr, zar));
	return nowy;
}

Student* SerwisOsobowy::Nowy_student(string im, string naz, string pe, Plec pl, string adr, string nr_i)
{
	Student* nowy(new Student(im, naz, pe, pl, adr, nr_i));
	return nowy;
}


SerwisOsobowy::~SerwisOsobowy()
{
}
