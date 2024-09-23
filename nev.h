#ifndef NEV_H
#define NEV_H

#include "string5.h"
#include "adat.h"
using std::cout;
using std::cin;

class Nev : public Adat {
    String keresztnev;
    String vezeteknev;

public:
    /// Konstruktor beállítja az attribútumokat
    /// @param v - vezetéknév megnevezése - String típusú, alapértelmezett üres string
    /// @param k - keresztnév megnevezése - String típusú, alapértelmezett üres string
    Nev(String v = "", String k = "") : keresztnev(k), vezeteknev(v) {}

    /// Keresztnév lekérdezése
    String getKeresztnev() const { return keresztnev; }

    /// Vezetéknév lekérdezése
    String getVezetektnev() const { return vezeteknev; }

    /// Keresztnév beállítása
    /// @param keresztnev - keresztnév értéke
    void setKeresztnev(const String& keresztnev) {
        this->keresztnev = keresztnev;
    }

    /// Vezetéknév beállítása
    /// @param vezeteknev - vezetéknév értéke
    void setVezeteknev(const String& vezeteknev) {
        this->vezeteknev = vezeteknev;
    }

    /// Adat kiírása ostream-re
    std::ostream& kiir(std::ostream& os) const {
        return os << vezeteknev << " " << keresztnev << "\t";
    }

    /// Nev objektum beolvasása cin-rõl
    Nev nev_beolvas() {
        String v, k;
        cout << "Vezeteknev: ";
        cin >> v;
        cout << "Keresztnev: ";
        cin >> k;
        return Nev(v, k);
    }

    /// Virtuális destruktor
    virtual ~Nev() {}
};

/// Kiíratás operátor
std::ostream& operator<<(std::ostream& os, const Nev& n);

#endif
