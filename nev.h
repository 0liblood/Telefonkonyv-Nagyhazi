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
    /// Konstruktor be�ll�tja az attrib�tumokat
    /// @param v - vezet�kn�v megnevez�se - String t�pus�, alap�rtelmezett �res string
    /// @param k - keresztn�v megnevez�se - String t�pus�, alap�rtelmezett �res string
    Nev(String v = "", String k = "") : keresztnev(k), vezeteknev(v) {}

    /// Keresztn�v lek�rdez�se
    String getKeresztnev() const { return keresztnev; }

    /// Vezet�kn�v lek�rdez�se
    String getVezetektnev() const { return vezeteknev; }

    /// Keresztn�v be�ll�t�sa
    /// @param keresztnev - keresztn�v �rt�ke
    void setKeresztnev(const String& keresztnev) {
        this->keresztnev = keresztnev;
    }

    /// Vezet�kn�v be�ll�t�sa
    /// @param vezeteknev - vezet�kn�v �rt�ke
    void setVezeteknev(const String& vezeteknev) {
        this->vezeteknev = vezeteknev;
    }

    /// Adat ki�r�sa ostream-re
    std::ostream& kiir(std::ostream& os) const {
        return os << vezeteknev << " " << keresztnev << "\t";
    }

    /// Nev objektum beolvas�sa cin-r�l
    Nev nev_beolvas() {
        String v, k;
        cout << "Vezeteknev: ";
        cin >> v;
        cout << "Keresztnev: ";
        cin >> k;
        return Nev(v, k);
    }

    /// Virtu�lis destruktor
    virtual ~Nev() {}
};

/// Ki�rat�s oper�tor
std::ostream& operator<<(std::ostream& os, const Nev& n);

#endif
