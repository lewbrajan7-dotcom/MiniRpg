#include <iostream>
#include "Jednostka.h"
#include "Gracz.h"
#include "Przedmiot.h"
#include <fstream>
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
    int wymaganeXP;
    wymaganeXP = Poziom * 100;
    while (Doswiadczenie >= wymaganeXP && Poziom < 5) {
        Doswiadczenie -= wymaganeXP;
        Poziom++;
        MaxPunktyZycia += 20;
        SilaAtaku += 5;
        Obrona += 2;
        PunktyZycia = MaxPunktyZycia;
        cout << "AWANS! Tw�j poziom to teraz: " << Poziom << endl;
        wymaganeXP = Poziom * 100;
    }
    if (Poziom == 5 && Doswiadczenie >= 500) {
        cout << "Osi�gni�to maksymalny poziom 5!" << endl;
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
        Ulecz(50); 
        mikstura--;
        cout << "Uzyto mikstury. Twoje HP: " << PunktyZycia << endl;
    } else {
        cout << "Brak mikstur!" << endl;
    }
}
void Gracz::ZapiszGre(int poziomGry) {
    ofstream plik("zapis.txt");
    if (plik.is_open()) {
        plik << Poziom << " " << PunktyZycia << " " << Portfel << " " << mikstura << " " << Doswiadczenie << " " << poziomGry << endl;
        
        plik << Miecz.PobierzNazwe() << " " << Miecz.PobierzBonusAtaku() << " " << Miecz.PobierzBonusObrony() << endl;
        plik << Helm.PobierzNazwe() << " " << Helm.PobierzBonusAtaku() << " " << Helm.PobierzBonusObrony() << endl;
        plik << Klata.PobierzNazwe() << " " << Klata.PobierzBonusAtaku() << " " << Klata.PobierzBonusObrony() << endl;
        plik << Spodnie.PobierzNazwe() << " " << Spodnie.PobierzBonusAtaku() << " " << Spodnie.PobierzBonusObrony() << endl;
        plik << Buty.PobierzNazwe() << " " << Buty.PobierzBonusAtaku() << " " << Buty.PobierzBonusObrony() << endl;
        
        plik << Ekwipunek.size() << endl;
        for (int i = 0; i < Ekwipunek.size(); i++) {
            plik << Ekwipunek[i].PobierzNazwe() << " " 
                 << Ekwipunek[i].PobierzBonusAtaku() << " " 
                 << Ekwipunek[i].PobierzBonusObrony() << endl;
        }
        
        plik.close();
    }
}


int Gracz::WczytajGre() {
    ifstream plik("zapis.txt");
    int wczytanyPoziomGry = 1;

    if (plik.is_open()) {
        // 1. Najpierw wczytujemy dane (w tym aktualny Poziom!)
        plik >> Poziom >> PunktyZycia >> Portfel >> mikstura >> Doswiadczenie >> wczytanyPoziomGry;

        // 2. Dopiero teraz ustawiamy statystyki bazowe na podstawie wczytanego poziomu
        MaxPunktyZycia = 100 + ((Poziom - 1) * 20);
        SilaAtaku = 15 + ((Poziom - 1) * 5);
        Obrona = 5 + ((Poziom - 1) * 2);

        string nazwa;
        int atak, obrona;

        // 3. Wczytujemy ekwipunek i dodajemy bonusy
        plik >> nazwa >> atak >> obrona;
        Miecz = Przedmiot(nazwa, atak, obrona);
        SilaAtaku += Miecz.PobierzBonusAtaku();
        Obrona += Miecz.PobierzBonusObrony();

        plik >> nazwa >> atak >> obrona;
        Helm = Przedmiot(nazwa, atak, obrona);
        SilaAtaku += Helm.PobierzBonusAtaku();
        Obrona += Helm.PobierzBonusObrony();

        plik >> nazwa >> atak >> obrona;
        Klata = Przedmiot(nazwa, atak, obrona);
        SilaAtaku += Klata.PobierzBonusAtaku();
        Obrona += Klata.PobierzBonusObrony();

        plik >> nazwa >> atak >> obrona;
        Spodnie = Przedmiot(nazwa, atak, obrona);
        SilaAtaku += Spodnie.PobierzBonusAtaku();
        Obrona += Spodnie.PobierzBonusObrony();

        plik >> nazwa >> atak >> obrona;
        Buty = Przedmiot(nazwa, atak, obrona);
        SilaAtaku += Buty.PobierzBonusAtaku();
        Obrona += Buty.PobierzBonusObrony();

        Ekwipunek.clear();
        int rozmiarEkwipunku;
        plik >> rozmiarEkwipunku;
        for (int i = 0; i < rozmiarEkwipunku; i++) {
            plik >> nazwa >> atak >> obrona;
            Ekwipunek.push_back(Przedmiot(nazwa, atak, obrona));
        }

        plik.close();
        cout << "Wczytano zapis gry!" << endl;
    } else {
        cout << "Brak pliku zapisu! Rozpoczynasz nowa gre." << endl;
    }

    return wczytanyPoziomGry;
}
bool Gracz::ProbaUcieczki()
{   
    int los = rand()%100+1;
    if(los<60){
        cout<<"udalo sie uciec"<<endl;
        return true;
    }else{
        cout<<"Nie udalo sie uciec "<<endl;
        return false;
    }
}