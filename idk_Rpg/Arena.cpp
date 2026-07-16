#include <iostream>
#include "Jednostka.h"
#include "Gracz.h"
#include "Potwor.h"
#include "Arena.h"
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Gracz.h"
#include "Przedmiot.h"
#include "Jednostka.h"

void Arena::PrzeprowadzWalke(Gracz &gracz, vector<Potwor> &przeciwnicy) {
    while (gracz.CzyZyje() && !przeciwnicy.empty()) {

        cout << "\n--- TURA GRACZA ---" << endl;
        cout << "1. Ulecz sie | 2. Zatakuj | 3.Proba Ucieczki" << endl;
        int JakaTura;
        cin >> JakaTura;


        if (JakaTura == 1) {
            gracz.UzyjMikstury();
        }

        else if (JakaTura == 2) {
            int wybor = -1;
            while (true) {
                cout << "Wybierz cel (0 - " << przeciwnicy.size() - 1 << "): ";
                cin >> wybor;
                if (wybor >= 0 && wybor < przeciwnicy.size()) break;
                cout << "Nieprawidlowy wybor." << endl;
            }

            przeciwnicy[wybor].OtrzymajObrazenia(gracz.WyprowadzAtak());

            if (!przeciwnicy[wybor].CzyZyje()) {
                cout << "Pokonales przeciwnika!" << endl;
                gracz.ZyskajDoswiadczenie(przeciwnicy[wybor].PobierzNagrode());
                gracz.ZyskajZloto(przeciwnicy[wybor].PobierzZloto());
                gracz.DodajPrzedmiot(przeciwnicy[wybor].DropItemu());
                przeciwnicy.erase(przeciwnicy.begin() + wybor);
                gracz.Awansuj();
            }
        }else if(JakaTura==3)
        {
            if (gracz.ProbaUcieczki())
            {
                przeciwnicy.clear();
                break;
            }
        }
        else {
            cout << "Niepoprawny wybor!" << endl;
            continue;
        }
        if (!przeciwnicy.empty()) {
            cout << "\n--- TURA POTWOROW ---" << endl;
            int atakujacyIndex = rand() % przeciwnicy.size();
            gracz.OtrzymajObrazenia(przeciwnicy[atakujacyIndex].WyprowadzAtak());
        }
    }
}
