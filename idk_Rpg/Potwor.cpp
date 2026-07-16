#include <iostream>
#include "Jednostka.h"
#include "Potwor.h"
#include <vector>
#include "Przedmiot.h"
using namespace std;
Potwor::Potwor(string NazwaPotwora, int PunktyZyciaPotwora, int AtakPotwora, int ObronaPotwora, int NagrodaXP1, int NagrodaZloto1)
    : Jednostka(NazwaPotwora, PunktyZyciaPotwora, AtakPotwora, ObronaPotwora) {
    this->NagrodaXP = NagrodaXP1;
    this->NagrodaZloto = NagrodaZloto1;
}
int Potwor::PobierzNagrode(){
    return NagrodaXP;
}
int Potwor::PobierzZloto(){
    return NagrodaZloto;
}
Przedmiot Potwor::DropItemu(){
    if(!CzyZyje()){
        int Los = rand() % 100 + 1;
        if(Los >= 33){
            vector<Przedmiot> ListaDropu = {
                Przedmiot("Miecz", 10, 0),
                Przedmiot("Helm", 0, 10),
                Przedmiot("Klata", 0, 10),
                Przedmiot("Spodnie", 0, 10),
                Przedmiot("Buty", 0, 10)
            };
            int LosowyItem = rand() % ListaDropu.size();
            return ListaDropu[LosowyItem];
        } else {
            cout << "Nie wydropilo przedmiotu" << endl;
        }
    }
    return Przedmiot("Brak", 0, 0);
}
