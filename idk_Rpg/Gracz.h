#pragma once
#include <iostream>
#include "Jednostka.h"
#include <vector>
#include "Przedmiot.h"
#include "Zadania.h"
using namespace std;
class Gracz : public Jednostka{
private:
    int Doswiadczenie;
    int Poziom;
    int Portfel;
    int mikstura;
    vector<Przedmiot> Ekwipunek;
    Przedmiot Helm = Przedmiot("Brak", 0, 0);
    Przedmiot Klata = Przedmiot("Brak", 0, 0);
    Przedmiot Spodnie = Przedmiot("Brak", 0, 0);
    Przedmiot Buty = Przedmiot("Brak", 0, 0);
    Przedmiot Miecz = Przedmiot("Brak", 0, 0);
public:
    Gracz(string NazwaGracza);
    void ZyskajDoswiadczenie(int ilosc);
    void Awansuj();
    void PokazStatus() override;
    void DodajPrzedmiot(Przedmiot p);
    void PokazEkwipunek();
    void ZalozPrzedmiot();
    void Sklep();
    void ZyskajZloto(int ilosc);
    void UzyjMikstury();
    void ZapiszGre(int poziomGry,Zadanie &zadanie);
    int WczytajGre(Zadanie &zadanie);
    bool ProbaUcieczki();


} ;
