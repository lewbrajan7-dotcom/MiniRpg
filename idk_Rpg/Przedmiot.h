#pragma once
#include <iostream>
using namespace std;
class Przedmiot {
private:
    string Nazwa;
    int BonusAtaku;
    int BonusObrony;
public:
    Przedmiot(string n, int a, int o);
    string PobierzNazwe();
    int PobierzBonusAtaku();
    int PobierzBonusObrony();
    void ZwiekszBonusObrony(int ilosc);
    void ZwiekszBonusAtaku(int ilosc);

};
