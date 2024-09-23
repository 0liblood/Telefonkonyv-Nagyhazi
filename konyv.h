#ifndef KONYV_H
#define KONYV_H

#include "szemely.h"

/**
 * A `Konyv` osztály egy telefonkönyvet reprezentál.
 * Tartalmazza a könyv méretét (`meret`) és a személyek tömbjét (`tomb`).
 */
class Konyv {
    size_t meret;       // A telefonkönyv mérete
    Szemely* tomb;      // A személyek tömbje

public:
    /**
     * Az `Konyv` osztály konstruktora.
     * Az osztály példányosításakor inicializálja a méretet és létrehozza a személyek tömbjét.
     */
    Konyv(size_t m = 0) : meret(m), tomb(new Szemely[m]) {}

    // Telefonkönyv betöltése a fájlból
    void betoltes();
    // Telefonkönyv listázása
    std::ostream& listazas(std::ostream&);
    // Új személy hozzáadása a telefonkönyvhöz
    void adatrogzites(const Szemely&);
    // Felhasználótól adatok bekérése és hozzáadása a telefonkönyvhöz
    void adatrogzites();
    // Személyek keresése a telefonkönyvben
    std::ostream& kereses(std::ostream&);
    // Személyek keresése név alapján a telefonkönyvben
    std::ostream& kereses_nev(std::ostream&, Nev&);
    // Az elsõ találat indexét adja vissza
    size_t elso_talalat();
    // Telefonkönyv mentése fájlba
    void mentes();
    // Személy törlése a telefonkönyvbõl
    std::ostream& torles(std::ostream&, size_t);
    // Személy adatainak módosítása
    void modositas(size_t);

    size_t getMeret() const { return meret; }
    // A méret lekérdezése

    // Az [] operátor túlterhelése, hogy az osztály példányát használva lehessen az elemekhez hozzáférni
    Szemely operator[](size_t i) const { return tomb[i]; }
    Szemely& operator[](size_t i) { return tomb[i]; }

    /**
     * Az `Konyv` osztály destruktora.
     * Felszabadítja a dinamikusan lefoglalt tömb memóriaterületét.
     */
    ~Konyv() { delete[] tomb; }
};

/**
 * A `sor_szamol` függvény felelõs a sorok számának meghatározásáért a "telefonkonyv.txt" fájlban.
 * Beolvassa a fájlt soronként és minden sor beolvasása után növeli a `darab` változót.
 * Végül visszatér a darab értékével, ami az összes sor számát jelenti.
 */
size_t sor_szamol();


#endif
