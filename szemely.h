#ifndef SZEMELY_H
#define SZEMELY_H

#include "nev.h"
#include "szam.h"
#include "cim.h"

class Szemely {
    Nev teljesNev;  // Szem�ly teljes neve
    Szam teljesSzam;  // Szem�ly telefonsz�mai
    Cim teljesCim;  // Szem�ly lakc�me
public:
    /// Alap�rtelmezett konstruktor
    Szemely() {}

    /// Konstruktor, amely be�ll�tja a szem�ly teljes nev�t, telefonsz�mait �s lakc�m�t
    Szemely(Nev n, Szam sz, Cim c) : teljesNev(n), teljesSzam(sz), teljesCim(c) {}

    /// �rt�kad�s oper�tor
    Szemely& operator=(const Szemely& sz) {
        if (this != &sz) {
            teljesNev = sz.teljesNev;
            teljesSzam = sz.teljesSzam;
            teljesCim = sz.teljesCim;
        }
        return *this;
    }

    /// Getter f�ggv�ny, visszaadja a szem�ly teljes nev�t
    Nev getTeljesNev() const { return teljesNev; }

    /// Getter f�ggv�ny, visszaadja a szem�ly teljes nev�t referenciak�nt
    Nev& getteljesnev() { return teljesNev; }

    /// Getter f�ggv�ny, visszaadja a szem�ly telefonsz�mait
    Szam getTeljesSzam() const { return teljesSzam; }

    /// Getter f�ggv�ny, visszaadja a szem�ly telefonsz�mait referenciak�nt
    Szam& getteljesszam() { return teljesSzam; }

    /// Getter f�ggv�ny, visszaadja a szem�ly lakc�m�t
    Cim getTeljesCim() const { return teljesCim; }

    /// Getter f�ggv�ny, visszaadja a szem�ly lakc�m�t referenciak�nt
    Cim& getteljescim() { return teljesCim; }

    /// Beolvas egy szem�lyt a felhaszn�l�t�l
    Szemely szemely_beolvas() {
        Nev n;
        Szam sz;
        Cim c;
        n = n.nev_beolvas();
        sz = sz.szam_beolvas();
        c = c.cim_beolvas();
        return Szemely(n, sz, c);
    }

    /// Ki�rja a szem�lyt a megadott stream-re
    std::ostream& szemely_kiir(std::ostream& os) {
        return os << teljesNev << teljesSzam << teljesCim << "\n";
    }

    /// Virtu�lis destruktor
    virtual ~Szemely() {}
};

#endif
