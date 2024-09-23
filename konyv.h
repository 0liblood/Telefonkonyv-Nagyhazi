#ifndef KONYV_H
#define KONYV_H

#include "szemely.h"

/**
 * A `Konyv` oszt�ly egy telefonk�nyvet reprezent�l.
 * Tartalmazza a k�nyv m�ret�t (`meret`) �s a szem�lyek t�mbj�t (`tomb`).
 */
class Konyv {
    size_t meret;       // A telefonk�nyv m�rete
    Szemely* tomb;      // A szem�lyek t�mbje

public:
    /**
     * Az `Konyv` oszt�ly konstruktora.
     * Az oszt�ly p�ld�nyos�t�sakor inicializ�lja a m�retet �s l�trehozza a szem�lyek t�mbj�t.
     */
    Konyv(size_t m = 0) : meret(m), tomb(new Szemely[m]) {}

    // Telefonk�nyv bet�lt�se a f�jlb�l
    void betoltes();
    // Telefonk�nyv list�z�sa
    std::ostream& listazas(std::ostream&);
    // �j szem�ly hozz�ad�sa a telefonk�nyvh�z
    void adatrogzites(const Szemely&);
    // Felhaszn�l�t�l adatok bek�r�se �s hozz�ad�sa a telefonk�nyvh�z
    void adatrogzites();
    // Szem�lyek keres�se a telefonk�nyvben
    std::ostream& kereses(std::ostream&);
    // Szem�lyek keres�se n�v alapj�n a telefonk�nyvben
    std::ostream& kereses_nev(std::ostream&, Nev&);
    // Az els� tal�lat index�t adja vissza
    size_t elso_talalat();
    // Telefonk�nyv ment�se f�jlba
    void mentes();
    // Szem�ly t�rl�se a telefonk�nyvb�l
    std::ostream& torles(std::ostream&, size_t);
    // Szem�ly adatainak m�dos�t�sa
    void modositas(size_t);

    size_t getMeret() const { return meret; }
    // A m�ret lek�rdez�se

    // Az [] oper�tor t�lterhel�se, hogy az oszt�ly p�ld�ny�t haszn�lva lehessen az elemekhez hozz�f�rni
    Szemely operator[](size_t i) const { return tomb[i]; }
    Szemely& operator[](size_t i) { return tomb[i]; }

    /**
     * Az `Konyv` oszt�ly destruktora.
     * Felszabad�tja a dinamikusan lefoglalt t�mb mem�riater�let�t.
     */
    ~Konyv() { delete[] tomb; }
};

/**
 * A `sor_szamol` f�ggv�ny felel�s a sorok sz�m�nak meghat�roz�s��rt a "telefonkonyv.txt" f�jlban.
 * Beolvassa a f�jlt soronk�nt �s minden sor beolvas�sa ut�n n�veli a `darab` v�ltoz�t.
 * V�g�l visszat�r a darab �rt�k�vel, ami az �sszes sor sz�m�t jelenti.
 */
size_t sor_szamol();


#endif
