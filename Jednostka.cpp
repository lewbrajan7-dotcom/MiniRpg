#include <iostream>
#include "Jednostka.h"
using namespace std;
Jednostka::Jednostka(string nazwaBohatera, int hpStartowe, int atakStartowy, int obronaStartowa){
this->Nazwa = nazwaBohatera;
this->MaxPunktyZycia = hpStartowe;
this->SilaAtaku = atakStartowy;
this->Obrona = obronaStartowa;
this->PunktyZycia = hpStartowe;
this->SzansaNaKrytyka = 10;
}
Jednostka::~Jednostka() {
}
int Jednostka::WyprowadzAtak() {
    int los = rand() % 100 + 1;
    if (los <= SzansaNaKrytyka) {
        cout << "KRYTYCZNE UDERZENIE!" << endl;
        return SilaAtaku * 2;
    }
    return SilaAtaku;
}
bool Jednostka::CzyZyje() {
    return PunktyZycia > 0;
}
void Jednostka::PokazStatus() {
    cout << "--- " << Nazwa << " ---" << endl;
    cout << "HP: " << PunktyZycia << " / " << MaxPunktyZycia << endl;
    cout << "Atak: " << SilaAtaku << " | Obrona: " << Obrona << endl;
}
void Jednostka::OtrzymajObrazenia(int obrazenia) {
    int koncoweObrazenia = obrazenia - Obrona;

    if (koncoweObrazenia < 1) {
        koncoweObrazenia = 1;
    }

    PunktyZycia -= koncoweObrazenia;
    cout << Nazwa << " otrzymuje " << koncoweObrazenia << " pkt obrazen!" << endl;

    if (PunktyZycia < 0) {
        PunktyZycia = 0;
    }
}
void Jednostka::Ulecz(int ilosc) {
    PunktyZycia += ilosc;
    if (PunktyZycia > MaxPunktyZycia) PunktyZycia = MaxPunktyZycia;
}

