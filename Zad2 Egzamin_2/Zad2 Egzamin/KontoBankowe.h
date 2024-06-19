#pragma once
#include <iostream>
#include "Klient.h"

using namespace std;

class KontoBankowe
{
private:
	char nrKonta[27];
	double stan;
	bool aktywnosc;
	Klient* klient;
	static int iloscKont;
public:
	KontoBankowe(Klient* klient, const char* nrKonta);
	virtual ~KontoBankowe();
	
	char* getNrKonta();
	void setNrKonta(const char* nrKonta);
	double getStan();
	void setStan(double stanKonta);
	bool getAktywnosc();
	void setAktywnosc(bool aktywnosc);
	Klient* getKlient();
	void setKlient(Klient* klient);

	static int getIloscKont();

	virtual double progoznaZaRok();

	KontoBankowe& operator+=(double amount);
	bool operator==(const KontoBankowe& other) const;

	//formalny mechanizm konwersji
	operator double() ;

	friend ostream& operator<<(ostream& strumien, const KontoBankowe& konto);
};

