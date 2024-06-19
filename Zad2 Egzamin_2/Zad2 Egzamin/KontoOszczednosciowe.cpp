#include "KontoOszczednosciowe.h"

KontoOszczednosciowe::KontoOszczednosciowe(Klient* klient, const char* nrKonta, double stopaOprocentowania)
: KontoBankowe(klient, nrKonta)
{
	this->stopaOprocentowania = stopaOprocentowania;
}

double KontoOszczednosciowe::progoznaZaRok()
{
	return getStan() + (getStan() * stopaOprocentowania);
}