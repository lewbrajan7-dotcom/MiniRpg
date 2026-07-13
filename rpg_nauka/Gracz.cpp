#include <iostream>
#include "Jednostka.h"
#include "Gracz.h"
#include "Przedmiot.h"
using namespace std;
Gracz::Gracz(string nazwaBohatera) : Jednostka(nazwaBohatera, 100, 15, 5) {
Poziom =1;
Doswiadczenie=0;
Portfel=0;
mikstura=0;
}
void Gracz::ZyskajDoswiadczenie(int ilosc){
    Doswiadczenie+=ilosc;
}
void Gracz::ZyskajZloto(int ilosc){
    Portfel+=ilosc;
}
void Gracz::Awansuj() {
    int wymaganeXP = Poziom * 100;
    while (Doswiadczenie >= wymaganeXP && Poziom < 5) {
        Doswiadczenie -= wymaganeXP;
        Poziom++;
        MaxPunktyZycia += 20;
        SilaAtaku += 5;
        Obrona += 2;
        PunktyZycia = MaxPunktyZycia;
        cout << "AWANS! Twój poziom to teraz: " << Poziom << endl;
        wymaganeXP = Poziom * 100;
    }
    if (Poziom == 5 && Doswiadczenie >= 500) {
        cout << "Osi¹gniêto maksymalny poziom 5!" << endl;
    }
}
void Gracz::PokazStatus(){
    Jednostka::PokazStatus();
    cout<<"Doswiadczenie : " <<Doswiadczenie<<endl;
    cout<<"Poziom : " <<Poziom<<endl;
}
void Gracz::DodajPrzedmiot(Przedmiot p) {
    Ekwipunek.push_back(p);
    cout << "Dodano przedmiot: " << p.PobierzNazwe() << endl;
}
void Gracz::PokazEkwipunek() {
    cout << "--- Ekwipunek ---" << endl;
    for (int i =0 ; i<Ekwipunek.size(); i++) {
        cout << i+1 << Ekwipunek[i].PobierzNazwe() << " ( Atak: " << Ekwipunek[i].PobierzBonusAtaku() << ", Obrona: " << Ekwipunek[i].PobierzBonusObrony() << ")" << endl;
    }
}
void Gracz::ZalozPrzedmiot(){
    if (Ekwipunek.empty()) {
        cout << "Ekwipunek jest pusty." << endl;
        return;
    }
    PokazEkwipunek();
    cout << "Wybierz indeks przedmiotu: ";
    int indeks;
    cin >> indeks;
    if (indeks < 0 || indeks >= Ekwipunek.size()) {
        cout << "Niepoprawny indeks." << endl;
        return;
    }
    Przedmiot p = Ekwipunek[indeks];
    string nazwa = p.PobierzNazwe();
    if (nazwa == "Miecz" && Miecz.PobierzNazwe() == "Brak") {
        Miecz = p;
        SilaAtaku += Miecz.PobierzBonusAtaku();
        Obrona += Miecz.PobierzBonusObrony();
        Ekwipunek.erase(Ekwipunek.begin() + indeks);
        cout << "Zalozono przedmiot: " << nazwa << endl;
    } else if (nazwa == "Helm" && Helm.PobierzNazwe() == "Brak") {
        Helm = p;
        SilaAtaku += Helm.PobierzBonusAtaku();
        Obrona += Helm.PobierzBonusObrony();
        Ekwipunek.erase(Ekwipunek.begin() + indeks);
        cout << "Zalozono przedmiot: " << nazwa << endl;
    } else if (nazwa == "Klata" && Klata.PobierzNazwe() == "Brak") {
        Klata = p;
        SilaAtaku += Klata.PobierzBonusAtaku();
        Obrona += Klata.PobierzBonusObrony();
        Ekwipunek.erase(Ekwipunek.begin() + indeks);
        cout << "Zalozono przedmiot: " << nazwa << endl;
    } else if (nazwa == "Spodnie" && Spodnie.PobierzNazwe() == "Brak") {
        Spodnie = p;
        SilaAtaku += Spodnie.PobierzBonusAtaku();
        Obrona += Spodnie.PobierzBonusObrony();
        Ekwipunek.erase(Ekwipunek.begin() + indeks);
        cout << "Zalozono przedmiot: " << nazwa << endl;
    } else if (nazwa == "Buty" && Buty.PobierzNazwe() == "Brak") {
        Buty = p;
        SilaAtaku += Buty.PobierzBonusAtaku();
        Obrona += Buty.PobierzBonusObrony();
        Ekwipunek.erase(Ekwipunek.begin() + indeks);
        cout << "Zalozono przedmiot: " << nazwa << endl;
    } else {
        cout << "NIE MOZNA ZALOZYC PRZEDMIOTU" << endl;
    }
}
void Gracz::Sklep() {
    int wybor = 0;
    while (wybor != 7) {
        cout << "=====SKLEP=====" << endl;
        cout << "1 : Kup miksture zdrowia : cena 50 zlota" << endl;
        cout << "2 : Kup ulepszenie helmu : cena 100 zlota" << endl;
        cout << "3 : Kup ulepszenie klaty : cena 100 zlota" << endl;
        cout << "4 : Kup ulepszenie spodni : cena 100 zlota" << endl;
        cout << "5 : Kup ulepszenie butow : cena 100 zlota" << endl;
        cout << "6 : Kup ulepszenie miecza : cena 150 zlota" << endl;
        cout << "7 : Wyjdz" << endl;

        cin >> wybor;

        switch (wybor) {
            case 1:
                if (Portfel >= 50) {
                    Portfel -= 50;
                    mikstura++;
                    cout << "Kupiono miksture!" << endl;
                    cout << " Pozostale zloto: " << Portfel << endl;
                } else {
                    cout << "Za malo zlota!" << endl;
                }
                break;
            case 2:
                if (Portfel >= 100&& Helm.PobierzNazwe()!="Brak") {
                    Portfel -= 100;
                    Obrona +=5;
                    Helm.ZwiekszBonusObrony(5);
                    cout << "Ulepszono helm!" << endl;
                    cout << " Pozostale zloto: " << Portfel << endl;
                } else {
                    cout << "Nie udalo sie ulepszyc!" << endl;
                }
                break;
            case 3:
                if (Portfel >= 100&& Klata.PobierzNazwe()!="Brak") {
                    Portfel -= 100;
                    Obrona +=5;
                    Klata.ZwiekszBonusObrony(5);
                    cout << "Ulepszono klate!" << endl;
                    cout << " Pozostale zloto: " << Portfel << endl;
                } else {
                    cout << "Nie udalo sie ulepszyc!" << endl;
                }
                break;
            case 4:
                if (Portfel >= 100 && Spodnie.PobierzNazwe()!="Brak") {
                    Portfel -= 100;
                    Obrona +=5;
                    Spodnie.ZwiekszBonusObrony(5);
                    cout << "Ulepszono spodnie!" << endl;
                    cout << " Pozostale zloto: " << Portfel << endl;
                } else {
                    cout << "Nie udalo sie ulepszyc!" << endl;
                }
                break;
            case 5:
                if (Portfel >= 100 && Buty.PobierzNazwe()!="Brak") {
                    Portfel -= 100;
                    Obrona +=5;
                    Buty.ZwiekszBonusObrony(5);
                    cout << "Ulepszono buty!" << endl;
                    cout << " Pozostale zloto: " << Portfel << endl;
                } else {
                    cout << "Nie udalo sie ulepszyc!" << endl;
                }
                break;
            case 6:
                if (Portfel >= 150 && Miecz.PobierzNazwe()!="Brak") {
                    Portfel -= 150;
                    SilaAtaku +=10;
                    Miecz.ZwiekszBonusAtaku(10) ;
                    cout << "Ulepszono miecz!" << endl;
                    cout << "Kupiono miksture! Pozostale zloto: " << Portfel << endl;
                } else {
                    cout << "Nie udalo sie ulepszyc!" << endl;
                }
                break;
            default:
                cout << "Niepoprawny wybor." << endl;
                break;
        }
    }
}
void Gracz::UzyjMikstury() {
    if (mikstura > 0) {
        Ulecz(50); // Zak³adaj¹c, ¿e mikstura leczy 50 HP
        mikstura--;
        cout << "Uzyto mikstury. Twoje HP: " << PunktyZycia << endl;
    } else {
        cout << "Brak mikstur!" << endl;
    }
}
