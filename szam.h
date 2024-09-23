#ifndef SZAM_H
#define SZAM_H

#include "string5.h"
#include "adat.h"
using std::cout;

class Szam : public Adat {
    String privat;
    String munkahelyi;

public:
    /// Konstruktor beállítja az attribútumokat
    /// @param p - privát szám megnevezése - String típusú, alapértelmezett üres string
    /// @param m - munkahelyi szám megnevezése - String típusú, alapértelmezett üres string
    Szam(String p = "", String m = "") : privat(p), munkahelyi(m) {}

    /// Munkahelyi szám lekérdezése
    String getMunkahelyi() const { return munkahelyi; }

    /// Privát szám lekérdezése
    String getPrivat() const { return privat; }

    /// Adat kiírása ostream-re
    std::ostream& kiir(std::ostream& os) const {
        return os << privat << " " << munkahelyi << "\t";
    }

    /// Munkahelyi szám beállítása
    /// @param munkahelyi - munkahelyi szám értéke
    void setMunkahelyi(const String& munkahelyi) {
        this->munkahelyi = munkahelyi;
    }

    /// Privát szám beállítása
    /// @param privat - privát szám értéke
    void setPrivat(const String& privat) {
        this->privat = privat;
    }

    /// Szám objektum beolvasása cin-rõl
    Szam szam_beolvas() {
        String m, p;
        std::cout << "Maganszam: ";
        std::cin >> p;
        std::cout << "Munkahelyi: ";
        std::cin >> m;

        return Szam(p, m);
    }

    /// Virtuális destruktor
    virtual ~Szam() {}
};

/// Kiíratás operátor
std::ostream& operator<<(std::ostream& os, const Szam& s);

#endif
