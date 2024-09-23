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
    /// Konstruktor be�ll�tja az attrib�tumokat
    /// @param o - orsz�g megnevez�se - String t�pus�, alap�rtelmezett �res string
    /// @param v - v�ros megnevez�se - String t�pus�, alap�rtelmezett �res string
    /// @param u - utca megnevez�se - String t�pus�, alap�rtelmezett �res string
    /// @param h - h�zsz�m megnevez�se - String t�pus�, alap�rtelmezett �res string
    /// @param i - ir�ny�t�sz�m megnevez�se - String t�pus�, alap�rtelmezett �res string
    Cim(String o = "", String v = "", String u = "", String h = "", String i = "")
        : orszag(o), varos(v), utca(u), hazszam(h), iranyitoszam(i) {}

    /// V�ros lek�rdez�se
    String getVaros() const { return varos; }

    /// V�ros be�ll�t�sa
    /// @param varos - v�ros �rt�ke
    void setVaros(const String& varos) { this->varos = varos; }

    /// Orsz�g lek�rdez�se
    String getOrszag() const { return orszag; }

    /// Orsz�g be�ll�t�sa
    /// @param orszag - orsz�g �rt�ke
    void setOrszag(const String& orszag) { this->orszag = orszag; }

    /// Utca lek�rdez�se
    String getUtca() const { return utca; }

    /// Utca be�ll�t�sa
    /// @param utca - utca �rt�ke
    void setUtca(const String& utca) { this->utca = utca; }

    /// H�zsz�m lek�rdez�se
    String getHazszam() const { return hazszam; }

    /// H�zsz�m be�ll�t�sa
    /// @param hazszam - h�zsz�m �rt�ke
    void setHazszam(const String& hazszam) { this->hazszam = hazszam; }

    /// Ir�ny�t�sz�m lek�rdez�se
    String getIranyitoszam() const { return iranyitoszam; }

    /// Ir�ny�t�sz�m be�ll�t�sa
    /// @param iranyitoszam - ir�ny�t�sz�m �rt�ke
    void setIranyitoszam(const String& iranyitoszam) { this->iranyitoszam = iranyitoszam; }

    /// C�m objektum beolvas�sa cin-r�l
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
    /// Virtu�lis destruktor
    virtual ~ Cim(){}
};

/// Ki�rat�s oper�tor
std::ostream& operator<<(std::ostream& os,const Cim& c);





#endif

