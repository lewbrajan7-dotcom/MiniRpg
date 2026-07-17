#pragma once
#include <iostream>
#include <string>

using namespace std;

class Zadanie {
private:
    const string Opis="Zabij";
    int WymaganeZabojstwa;
    int AktualneZabojstwa;
public:
    Zadanie(int wymagane);
    void ObecneZadanie();
    void ZarejestrujZabojstwo();
    bool CzyUkonczone();
    void ZresetujZabojstwa();
    void ZwiekszWymagania();
};