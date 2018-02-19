#pragma once
#include "Pracownik.h"
#include "Student.h"
#include <memory>

using std::shared_ptr;

class SerwisOsobowy
{
public:
	SerwisOsobowy();
	Pracownik* Nowy_pracownik(string im, string naz, string pe, Plec pl, string adr, int zar);
	Student* Nowy_student(string im, string naz, string pe, Plec pl, string adr, string nr_i);
	~SerwisOsobowy();
};
