#pragma once
#include <iostream>
#include <string>
using namespace std;
class Jednostka{
protected:
    string Nazwa;
    int PunktyZycia;
    int MaxPunktyZycia;
    int SilaAtaku;
    int Obrona;
    int SzansaNaKrytyka;
public:
    Jednostka(string nazwaBohatera, int hpStartowe, int atakStartowy, int obronaStartowa);
    virtual ~Jednostka();
    virtual void OtrzymajObrazenia(int obrazenia);
    int WyprowadzAtak();
    bool CzyZyje();
    virtual void PokazStatus();
    void Ulecz(int ilosc);
};
