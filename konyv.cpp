#include <iostream>
#include <sstream>
#include <fstream>

#include "konyv.h"
#include "memtrace.h"

using std::cin;
using std::cout;

void Konyv::adatrogzites(const Szemely& szemely) {
    // Új tömb létrehozása a meglévő méret + 1 elemmel
    Szemely* ujTomb = new Szemely[meret + 1];
    // Az aktuális elemek másolása az új tömbbe
    for (size_t i = 0; i < meret; i++) {
        ujTomb[i] = tomb[i];
    }
    // Az új elem hozzáadása az új tömbhöz
    ujTomb[meret] = szemely;
    // A régi tömb felszabadítása
    delete[] tomb;
    // Az új tömb beállítása a 'tomb' mutatóra
    tomb = ujTomb;
    // A tömb méretének növelése
    meret++;
}

void Konyv::adatrogzites() {
    // Új személy objektum létrehozása és beolvasása
    Szemely uj;
    uj = uj.szemely_beolvas();
    // Új tömb létrehozása a meglévő méret + 1 elemmel
    Szemely* ujTomb = new Szemely[meret + 1];
    // Az aktuális elemek másolása az új tömbbe
    for (size_t i = 0; i < meret; i++) {
        ujTomb[i] = tomb[i];
    }
    // Az új elem hozzáadása az új tömbhöz
    ujTomb[meret] = uj;
    // A régi tömb felszabadítása
    delete[] tomb;
    // Az új tömb beállítása a 'tomb' mutatóra
    tomb = ujTomb;
    // A tömb méretének növelése
    meret++;
}

std::ostream& Konyv::listazas(std::ostream& os){
    // Új sor a kimeneten
    os<<"\n";
    // Minden elem kiírása a tömbből
    for(size_t i = 0; i<meret;i++)
        tomb[i].szemely_kiir(os);
    // Új sor a kimeneten
    os<<"\n";
    return os;
}

std::ostream& Konyv::kereses(std::ostream& os){
    // Felhasználói bemenet fogadása a keresés típusához
    cout<<"\n\t[P] - Privat szam\n\t[M] - Munkahelyi szam\n\t[N] - Nev\n";
    char bemenet;
    cin>>bemenet;
    bemenet= tolower(bemenet);
    bool talalat = false;
    String p;
    String m;
    Nev n;
    switch(bemenet){
    case 'p':
        cout<<"Privat szam: ";
        cin>>p;
        // A találatok kiírása, ha megtalálható a privat szám a tömbben
        for(size_t i = 0; i<meret;i++)
            if(tomb[i].getTeljesSzam().getPrivat()==p){
                tomb[i].szemely_kiir(os);
                talalat =true;
            }
        break;
    case 'm':
        cout<<"Munkahelyi szam: ";
        cin>>m;
        // A találatok kiírása, ha megtalálható a munkahelyi szám a tömbben
        for(size_t i = 0; i<meret;i++)
            if(tomb[i].getTeljesSzam().getMunkahelyi()==m){
                tomb[i].szemely_kiir(os);
                talalat =true;
            }
        break;

    case 'n':
        n=n.nev_beolvas();
        // A találatok kiírása, ha megtalálható a név a tömbben
        for(size_t i = 0; i<meret;i++)
            if(tomb[i].getTeljesNev().getKeresztnev()==n.getKeresztnev() && tomb[i].getTeljesNev().getVezetektnev()==n.getVezetektnev()){
                tomb[i].szemely_kiir(os);
                talalat =true;
            }
        break;
    }
    // Ha nincs találat, kiírás
    if(!talalat)
        os<<"\nNincs talalat.\n";
    return os;
}

std::ostream& Konyv::kereses_nev(std::ostream& os,Nev& n){
    bool talalat = false;
    // A találatok kiírása, ha megtalálható a név a tömbben
    for(size_t i = 0; i<meret;i++)
        if(tomb[i].getTeljesNev().getKeresztnev()==n.getKeresztnev() && tomb[i].getTeljesNev().getVezetektnev()==n.getVezetektnev()){
            // Az első találatnál kiírás, hogy talált sorok vannak
            if(!talalat)
                os<<"\nTalalt sor(ok):\n";
            tomb[i].szemely_kiir(os);
            talalat =true;
        }
    // Ha nincs találat, kiírás
    if(!talalat)
        os<<"\nNincs talalat.\n";
    return os;
}

size_t Konyv::elso_talalat(){
    // Felhasználói bemenet fogadása a keresés típusához
    cout<<"\n\t[P] - Privat szam\n\t[M] - Munkahelyi szam\n\t[N] - Nev\n";
    char bemenet; cin>>bemenet;
    bemenet = tolower(bemenet);
    String p;
    String m;
    Nev n;
    switch(bemenet){
    case 'p':
        cout<<"Privat szam: ";
        cin>>p;
        // Az első találat sorszáma visszaadása, ha megtalálható a privat szám a tömbben
        for(size_t i = 0; i<meret;i++)
            if(tomb[i].getTeljesSzam().getPrivat()==p)
                return i;
        break;
    case 'm':
        cout<<"Munkahelyi szam: ";
        cin>>m;
        // Az első találat sorszáma visszaadása, ha megtalálható a munkahelyi szám a tömbben
        for(size_t i = 0; i<meret;i++)
            if(tomb[i].getTeljesSzam().getMunkahelyi()==m )
                return i;
        break;
    case 'n':
        n=n.nev_beolvas();
        // Az első találat sorszáma visszaadása, ha megtalálható a név a tömbben
        for(size_t i = 0; i<meret;i++)
            if(tomb[i].getTeljesNev().getKeresztnev()==n.getKeresztnev())
                return i;
        break;
    }
    // Ha nincs találat, -1 visszaadása
    return -1;
}

std::ostream& Konyv::torles(std::ostream& os,size_t i){
    // Ha nincs találat, kiírás és visszatérés
    if(i==static_cast<size_t>(-1)){
        os<<"\nNincs talalat.\n";
        return os;
    }
    // A törlendő sor kiírása
    os<<"Torlesre kerulo sor: ";
    tomb[i].szemely_kiir(os);
    // Méret csökkentése
    meret--;
    // A tömb rendezése a törlendő sor utáni sorok törlése után
    for(size_t j = i; j < meret; j++)
        tomb[j] = tomb[j + 1];
    return os;
}

void Konyv::modositas(size_t i){
    // Ha nincs találat, kiírás és visszatérés
    if(i==static_cast<size_t>(-1)){
        cout<<"\nNincs talalat.\n";
        return;
    }
    // A módosítandó sor kiírása
    cout<<"Modositando sor: ";
    tomb[i].szemely_kiir(cout);
    cout<<"\nMit szeretne modositani rajta?\n1 - keresztnev\n2 - vezeteknev\n3 - privat szam\n4 - munkahelyi szam\n5 - orszag\n6 - varos\n7 - utca\n8 - hazszam\n9 - iranyitoszam\n";
    int bemenet; cin>>bemenet;
    cout<<"Uj ertek: ";
    String ujadat; cin>>ujadat;
    switch(bemenet){
    case 1:
        tomb[i].getteljesnev().setKeresztnev(ujadat);
        break;
    case 2:
        tomb[i].getteljesnev().setVezeteknev(ujadat);
        break;
    case 3:
        tomb[i].getteljesszam().setPrivat(ujadat);
        break;
    case 4:
        tomb[i].getTeljesSzam().setMunkahelyi(ujadat);
        break;
    case 5:
        tomb[i].getteljescim().setOrszag(ujadat);
        break;
    case 6:
        tomb[i].getteljescim().setVaros(ujadat);
        break;
    case 7:
        tomb[i].getteljescim().setUtca(ujadat);
        break;
    case 8:
        tomb[i].getteljescim().setHazszam(ujadat);
        break;
    case 9:
        tomb[i].getteljescim().setIranyitoszam(ujadat);
        break;
    }
}

/**
 * A `mentes` függvény felelős a telefonkönyv tartalmának mentéséért.
 * Az adatokat egy "telefonkonyv.txt" nevű fájlba írja ki tabulátorral elválasztva.
 * A függvény végigmegy a `tomb` tömbön és minden személy adatait kiírja a fájlba.
 */
void Konyv::mentes() {
    std::ofstream file("telefonkonyv.txt");
    if (file.is_open()) {
        for (size_t i = 0; i < meret; ++i) {
            // A személy adatait tabulátorral elválasztva írjuk ki a fájlba
            file << tomb[i].getTeljesNev().getVezetektnev() << "\t"
                 << tomb[i].getTeljesNev().getKeresztnev() << "\t"
                 << tomb[i].getTeljesSzam().getPrivat() << "\t"
                 << tomb[i].getTeljesSzam().getMunkahelyi() << "\t"
                 << tomb[i].getTeljesCim().getOrszag() << "\t"
                 << tomb[i].getTeljesCim().getVaros() << "\t"
                 << tomb[i].getTeljesCim().getUtca() << "\t"
                 << tomb[i].getTeljesCim().getHazszam() << "\t"
                 << tomb[i].getTeljesCim().getIranyitoszam() << "\t"
                 << std::endl;
        }
        file.close();
    }
}

/**
 * A `betoltes` függvény felelős a telefonkönyv tartalmának betöltéséért.
 * A függvény beolvassa az adatokat a "telefonkonyv.txt" nevű fájlból és feltölti velük a `tomb` tömböt.
 */
void Konyv::betoltes() {
    std::ifstream file("telefonkonyv.txt");
    if (file.is_open()) {
        std::string line;
        size_t i = 0;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string vezeteknev, keresztnev, privat, munkahelyi, orszag, varos, utca, hazszam, iranyitoszam;
            // Az adatokat tabulátorral elválasztva beolvassuk a megfelelő változókba
            if (iss >> vezeteknev >> keresztnev >> privat >> munkahelyi >> orszag >> varos >> utca >> hazszam >> iranyitoszam) {
                // Az adatokat felhasználva létrehozzuk egy Szemely objektumot és beillesztjük a `tomb` tömbbe
                tomb[i] = Szemely(Nev(vezeteknev, keresztnev), Szam(privat, munkahelyi), Cim(orszag, varos, utca, hazszam, iranyitoszam));
                i++;
            }
        }
        file.close();
    }
}

/**
 * A `sor_szamol` függvény felelős a sorok számának meghatározásáért a "telefonkonyv.txt" fájlban.
 * Beolvassa a fájlt soronként és minden sor beolvasása után növeli a `darab` változót.
 * Végül visszatér a darab értékével, ami az összes sor számát jelenti.
 */
size_t sor_szamol() {
    size_t darab = 0;
    std::string line;
    std::ifstream file("telefonkonyv.txt");
    if (file.is_open()) {
        while (std::getline(file, line)) {
            // Minden sor beolvasása után növeljük a darab változót
            ++darab;
        }
        file.close();
    }
    return darab;
}
