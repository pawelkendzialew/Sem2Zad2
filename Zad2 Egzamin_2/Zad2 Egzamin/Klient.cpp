#define _CRT_SECURE_NO_WARNINGS
#include "Klient.h"
#include "KontoBankowe.h"
#include <cstring>
#include <stdlib.h>     /* srand, rand */
using namespace std;

Klient::Klient(const char* nazwa)
{
	setNazwa(nazwa);
}
char* Klient::getNazwa()
{
	return nazwa;
}
void Klient::setNazwa(const char* nazwa)
{
	if (strlen(nazwa)>30)
	{
		strncpy(this->nazwa, nazwa,30);
	}
	else
	{
		strcpy(this->nazwa, nazwa);
	}
	
}

int losuj(int min, int max)
{
	int przedzial = max - min + 1;
	return rand() % przedzial + min;
}

//konwersja nie formalna
KontoBankowe Klient::zamienNaKontoBankowe()
{
	char konto[27];
	konto[26] = 0;
	for (int i = 0; i < 26; i++)
	{
		konto[i] = losuj('0', '9');
	}
	return KontoBankowe(this, konto);
}

