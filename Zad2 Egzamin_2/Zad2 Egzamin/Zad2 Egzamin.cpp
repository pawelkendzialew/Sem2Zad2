#include <iostream>
#include "KontoBankowe.h"
#include "KontoOszczednosciowe.h"

using namespace std;

void wypiszPrognoze(KontoBankowe* konto)
{
    cout << "prognoza konta za rok to:" << konto->progoznaZaRok() << "PLN" << endl;
}

int main()
{
    cout << "ilosc kont:" << KontoBankowe::getIloscKont() << endl;
    Klient klient("Jan Kowalski");
    
    KontoBankowe kb(&klient, "1234551232334121233123123");
    KontoOszczednosciowe ko(&klient, "1234551232334121233123123",0.02);
    kb.setStan(100);
    ko.setStan(100);
    cout << kb.progoznaZaRok() << endl;
    cout << ko.progoznaZaRok() << endl;
    wypiszPrognoze(&kb);
    wypiszPrognoze(&ko);

    kb += 33;
    kb.operator+=(33);
    cout << kb << endl;

    KontoBankowe kb2(&klient, "1234551232334121233123123");
    if (kb == kb2)
    {
        cout << "stany kont takie same" << endl;
    }

    cout << "ilosc kont:" << KontoBankowe::getIloscKont() << endl;

    {
        KontoOszczednosciowe ko(&klient, "1234551232334121233123123", 0.02);
        cout << "ilosc kont:" << KontoBankowe::getIloscKont() << endl;
    }
    cout << "ilosc kont:" << KontoBankowe::getIloscKont() << endl;
}

