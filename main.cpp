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

using namespace std;

int main() {
    srand(time(0));
    Gracz gracz("Brajan");
    Arena arena;
    int poziomGry = 1;
	cout << "1. Nowa gra | 2. Wczytaj gre: ";
    int wybor;
    cin >> wybor;
    if (wybor == 2) {
        poziomGry = gracz.WczytajGre();
    }

    while(gracz.CzyZyje()) {
        vector<Potwor> listaPrzeciwnikow;
        cout << "--- POZIOM " << poziomGry << " ---" << endl;

        if (poziomGry % 5 == 0) {
            Potwor boss("Boss", 300 + (poziomGry * 20), 20 + poziomGry, 5, 500, 200);
            listaPrzeciwnikow.push_back(boss);
        } else {
            for(int i = 0; i < poziomGry; i++) {
                listaPrzeciwnikow.push_back(Potwor("Goblin", 50, 10, 2, 50, 50));
            }
        }
        arena.PrzeprowadzWalke(gracz, listaPrzeciwnikow);

        if(gracz.CzyZyje()) {
            gracz.Sklep();
            poziomGry++;
        }
		cout<<"Chcesz zapisac gre i wyjsc ?0-nie /1-tak"<<endl;
		int decyzja;
		cin>>decyzja;
		if (decyzja == 1) {
			gracz.ZapiszGre(poziomGry);
			break;
		}
		
    }
    return 0;
}
