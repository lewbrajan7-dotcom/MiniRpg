#pragma once
#include <iostream>
#include "Jednostka.h"
#include "Przedmiot.h"
using namespace std;
class Potwor :public Jednostka{
private :
    int NagrodaXP;
    int NagrodaZloto;
public:
    Potwor(string NazwaPotwora,int PunktyZyciaPotwora,int AtakPotwora,int ObronaPotwora, int NagrodaXP,int NagrodaZloto );
    int PobierzNagrode();
    Przedmiot DropItemu();
    int PobierzZloto();


};
