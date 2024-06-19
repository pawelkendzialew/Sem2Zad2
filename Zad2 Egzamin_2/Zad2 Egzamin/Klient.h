#pragma once

using namespace std;
class KontoBankowe;//deklaracja (naglowek) klasy

class Klient
{
private:
	char nazwa[30];
public:
	Klient(const char* nazwa);
	char* getNazwa();
	void setNazwa(const char* nazwa);
	KontoBankowe zamienNaKontoBankowe();
};

