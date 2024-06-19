#define _CRT_SECURE_NO_WARNINGS
#include "KontoBankowe.h"
#include <cstring>

int KontoBankowe::iloscKont = 0;

KontoBankowe::KontoBankowe(Klient* klient, const char* nrKonta)
{
	this->klient = klient;
	setAktywnosc(true);
	setNrKonta(nrKonta);
	stan = 0;
}
KontoBankowe::~KontoBankowe()
{
	if (!this->aktywnosc)
	{
		iloscKont--;
	}
}

char* KontoBankowe::getNrKonta()
{
	return nrKonta;
}

void KontoBankowe::setNrKonta(const char* nrKonta)
{
	if (strlen(nrKonta) > 26)
	{
		strncpy(this->nrKonta, nrKonta, 26);
	}
	else
	{
		strcpy(this->nrKonta, nrKonta);
	}

}


double KontoBankowe::getStan()
{
	return stan;
}
void KontoBankowe::setStan(double stan)
{
	if (stan < 0)
	{
		stan = 0;
	}
	else
	{
		this->stan = stan;
	}
	
}
bool KontoBankowe::getAktywnosc()
{
	return aktywnosc;
}
void KontoBankowe::setAktywnosc(bool aktywnosc)
{

	if (!this->aktywnosc && aktywnosc)
	{
		iloscKont++;
	}
	else if (this->aktywnosc && !aktywnosc)
	{
		iloscKont--;
	}

	this->aktywnosc = aktywnosc;
}
Klient* KontoBankowe::getKlient()
{
	return klient;
}
void KontoBankowe::setKlient(Klient* klient)
{
	this->klient = klient;
}

int KontoBankowe::getIloscKont()
{
	return iloscKont;
}

double  KontoBankowe::progoznaZaRok()
{
	return stan;
}

KontoBankowe::operator double() {
	return stan;
}

KontoBankowe& KontoBankowe::operator+=(double amount) {
	stan += amount;
	return *this;
}

bool KontoBankowe::operator==(const KontoBankowe& other) const {
	return stan == other.stan;
}

ostream& operator<<(ostream& strumien, const KontoBankowe& konto) {
	if (konto.aktywnosc)
	{
		strumien << "[" << konto.nrKonta << "][" << konto.klient->getNazwa() << "]:[" << konto.stan << "]";
	}
	else
	{
		strumien << "[" << konto.nrKonta << "] NIEAKTYWNE";
	}
	return strumien;
}