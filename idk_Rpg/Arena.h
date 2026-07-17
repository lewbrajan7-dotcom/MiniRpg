#pragma once
#include <vector>
#include "Potwor.h"
#include "Gracz.h"
#include "Zadania.h"
class Arena{
public:
    void PrzeprowadzWalke(Gracz &gracz, vector<Potwor> &przeciwnicy,Zadanie &zadanie);
};
