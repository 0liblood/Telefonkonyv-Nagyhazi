#ifndef SZAM_H
#define SZAM_H

#include "string5.h"
#include "adat.h"
using std::cout;

class Szam : public Adat {
    String privat;
    String munkahelyi;

public:
    /// Konstruktor be�ll�tja az attrib�tumokat
    /// @param p - priv�t sz�m megnevez�se - String t�pus�, alap�rtelmezett �res string
    /// @param m - munkahelyi sz�m megnevez�se - String t�pus�, alap�rtelmezett �res string
    Szam(String p = "", String m = "") : privat(p), munkahelyi(m) {}

    /// Munkahelyi sz�m lek�rdez�se
    String getMunkahelyi() const { return munkahelyi; }

    /// Priv�t sz�m lek�rdez�se
    String getPrivat() const { return privat; }

    /// Adat ki�r�sa ostream-re
    std::ostream& kiir(std::ostream& os) const {
        return os << privat << " " << munkahelyi << "\t";
    }

    /// Munkahelyi sz�m be�ll�t�sa
    /// @param munkahelyi - munkahelyi sz�m �rt�ke
    void setMunkahelyi(const String& munkahelyi) {
        this->munkahelyi = munkahelyi;
    }

    /// Priv�t sz�m be�ll�t�sa
    /// @param privat - priv�t sz�m �rt�ke
    void setPrivat(const String& privat) {
        this->privat = privat;
    }

    /// Sz�m objektum beolvas�sa cin-r�l
    Szam szam_beolvas() {
        String m, p;
        std::cout << "Maganszam: ";
        std::cin >> p;
        std::cout << "Munkahelyi: ";
        std::cin >> m;

        return Szam(p, m);
    }

    /// Virtu�lis destruktor
    virtual ~Szam() {}
};

/// Ki�rat�s oper�tor
std::ostream& operator<<(std::ostream& os, const Szam& s);

#endif
