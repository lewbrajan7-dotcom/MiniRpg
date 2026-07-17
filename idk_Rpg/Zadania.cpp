#include "Zadania.h"
#include "Potwor.h"
#include "Gracz.h"
#include <iostream>

using namespace std;

Zadanie::Zadanie( int wymagane)
{
    this->WymaganeZabojstwa = wymagane;
    this->AktualneZabojstwa = 0;
}

void Zadanie::ObecneZadanie()
{
    cout << Opis << " " << WymaganeZabojstwa << " wrogow" << endl; // Poprawione spacje i strumień <<
}

void Zadanie::ZarejestrujZabojstwo()
{
    if (AktualneZabojstwa < WymaganeZabojstwa)
    {
        AktualneZabojstwa++;
        cout << "Postep zadania: " << AktualneZabojstwa << "/" << WymaganeZabojstwa << endl;
    }
}

bool Zadanie::CzyUkonczone()
{
    if (WymaganeZabojstwa == AktualneZabojstwa)
    {   
        cout << "Ukonczyles zadanie " << endl;
        return true;
    } else{
        return false;
    }
}

void Zadanie::ZresetujZabojstwa()
{
    AktualneZabojstwa = 0;
}

void Zadanie::ZwiekszWymagania()
{
    WymaganeZabojstwa *= 2; 
}