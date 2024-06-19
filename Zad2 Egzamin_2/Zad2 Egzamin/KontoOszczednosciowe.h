#pragma once
#include "KontoBankowe.h"

class KontoOszczednosciowe : public KontoBankowe
{
private:
	double stopaOprocentowania;
public:
	KontoOszczednosciowe(Klient* klient, const char* nrKonta, double stopaOprocentowania);
	double progoznaZaRok() override;
};

