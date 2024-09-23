#ifndef SZEMELY_H
#define SZEMELY_H

#include "nev.h"
#include "szam.h"
#include "cim.h"

class Szemely {
    Nev teljesNev;  // Személy teljes neve
    Szam teljesSzam;  // Személy telefonszámai
    Cim teljesCim;  // Személy lakcíme
public:
    /// Alapértelmezett konstruktor
    Szemely() {}

    /// Konstruktor, amely beállítja a személy teljes nevét, telefonszámait és lakcímét
    Szemely(Nev n, Szam sz, Cim c) : teljesNev(n), teljesSzam(sz), teljesCim(c) {}

    /// Értékadás operátor
    Szemely& operator=(const Szemely& sz) {
        if (this != &sz) {
            teljesNev = sz.teljesNev;
            teljesSzam = sz.teljesSzam;
            teljesCim = sz.teljesCim;
        }
        return *this;
    }

    /// Getter függvény, visszaadja a személy teljes nevét
    Nev getTeljesNev() const { return teljesNev; }

    /// Getter függvény, visszaadja a személy teljes nevét referenciaként
    Nev& getteljesnev() { return teljesNev; }

    /// Getter függvény, visszaadja a személy telefonszámait
    Szam getTeljesSzam() const { return teljesSzam; }

    /// Getter függvény, visszaadja a személy telefonszámait referenciaként
    Szam& getteljesszam() { return teljesSzam; }

    /// Getter függvény, visszaadja a személy lakcímét
    Cim getTeljesCim() const { return teljesCim; }

    /// Getter függvény, visszaadja a személy lakcímét referenciaként
    Cim& getteljescim() { return teljesCim; }

    /// Beolvas egy személyt a felhasználótól
    Szemely szemely_beolvas() {
        Nev n;
        Szam sz;
        Cim c;
        n = n.nev_beolvas();
        sz = sz.szam_beolvas();
        c = c.cim_beolvas();
        return Szemely(n, sz, c);
    }

    /// Kiírja a személyt a megadott stream-re
    std::ostream& szemely_kiir(std::ostream& os) {
        return os << teljesNev << teljesSzam << teljesCim << "\n";
    }

    /// Virtuális destruktor
    virtual ~Szemely() {}
};

#endif
