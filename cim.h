#ifndef CIM_H
#define CIM_H

#include "string5.h"
#include "adat.h"
using std::cout;

class Cim : public Adat {
    String orszag;
    String varos;
    String utca;
    String hazszam;
    String iranyitoszam;

public:
    /// Konstruktor beállítja az attribútumokat
    /// @param o - ország megnevezése - String típusú, alapértelmezett üres string
    /// @param v - város megnevezése - String típusú, alapértelmezett üres string
    /// @param u - utca megnevezése - String típusú, alapértelmezett üres string
    /// @param h - házszám megnevezése - String típusú, alapértelmezett üres string
    /// @param i - irányítószám megnevezése - String típusú, alapértelmezett üres string
    Cim(String o = "", String v = "", String u = "", String h = "", String i = "")
        : orszag(o), varos(v), utca(u), hazszam(h), iranyitoszam(i) {}

    /// Város lekérdezése
    String getVaros() const { return varos; }

    /// Város beállítása
    /// @param varos - város értéke
    void setVaros(const String& varos) { this->varos = varos; }

    /// Ország lekérdezése
    String getOrszag() const { return orszag; }

    /// Ország beállítása
    /// @param orszag - ország értéke
    void setOrszag(const String& orszag) { this->orszag = orszag; }

    /// Utca lekérdezése
    String getUtca() const { return utca; }

    /// Utca beállítása
    /// @param utca - utca értéke
    void setUtca(const String& utca) { this->utca = utca; }

    /// Házszám lekérdezése
    String getHazszam() const { return hazszam; }

    /// Házszám beállítása
    /// @param hazszam - házszám értéke
    void setHazszam(const String& hazszam) { this->hazszam = hazszam; }

    /// Irányítószám lekérdezése
    String getIranyitoszam() const { return iranyitoszam; }

    /// Irányítószám beállítása
    /// @param iranyitoszam - irányítószám értéke
    void setIranyitoszam(const String& iranyitoszam) { this->iranyitoszam = iranyitoszam; }

    /// Cím objektum beolvasása cin-rõl
    Cim cim_beolvas(){
        String o,i,v,u,h;
        std::cout << "Orszag: ";
        std::cin >> o;
        std::cout << "Iranyitoszam: ";
        std::cin >> i;
        std::cout << "Varos: ";
        std::cin >> v;
        std::cout << "Utca: ";
        std::cin >> u;
        std::cout << "Hazszam: ";
        std::cin >> h;
        return Cim(o,v,u,h,i);
    }
    /// Virtuális destruktor
    virtual ~ Cim(){}
};

/// Kiíratás operátor
std::ostream& operator<<(std::ostream& os,const Cim& c);





#endif

