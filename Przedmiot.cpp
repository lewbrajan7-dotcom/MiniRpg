#include "Przedmiot.h"
#include <iostream>
Przedmiot::Przedmiot(string n, int a, int o) {
    this->Nazwa = n;
    this->BonusAtaku = a;
    this->BonusObrony = o;
}

string Przedmiot::PobierzNazwe() {
    return Nazwa;
}

int Przedmiot::PobierzBonusAtaku() {
    return BonusAtaku;
}

int Przedmiot::PobierzBonusObrony() {
    return BonusObrony;
}
void Przedmiot::ZwiekszBonusAtaku(int wartosc) {
     BonusAtaku+= wartosc;
}
void Przedmiot::ZwiekszBonusObrony(int wartosc) {
    BonusObrony += wartosc;
}
