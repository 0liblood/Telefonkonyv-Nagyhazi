#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cstring>
#include <string>

// String osztály deklarációja
class String {
    char *pData;
    size_t len;
public:
    // Méret lekérdezése
	size_t size() const { return len; }

    // Alapértelmezett konstruktor
    String() : pData(0), len(0) {}

    // Konstruktor std::string-bõl
    String(const std::string& str): pData(new char[str.size() + 1]), len(str.size()){
        std::strcpy(pData, str.c_str());
    }

    // Karakter konstruktor
    String(char ch);

    // Konstruktor karaktertömbbõl
    String(const char *p);

    // Másoló konstruktor
    String(const String& s1);

    // Destruktor
    ~String() { delete[] pData; }

    // C-sztring lekérdezése
    const char* c_str() const { if (pData) return pData; else return "";}

    // Hibaellenõrzéshez használt print függvény
    void printDbg(const char *txt = "") const {
        std::cout << txt << "[" << len << "], "
                  << (pData ? pData : "(NULL)") << std::endl;
    }

    // Értékadó operátor
    String& operator=(const String& rhs_s);

    // Stringhez történõ hozzáadás operátor
    String& operator+=(const String& rhs_s) {
        *this = *this + rhs_s;
        return *this;
    }

    // Egyenlõségvizsgálat operátor
    bool operator==(const String& s1) {
        if (s1.size() != this->size()) {
            return false;
        }
        for (size_t i = 0; i < s1.size(); ++i) {
            if (s1[i] != (*this)[i]) {
                return false;
            }
        }
        return true;
    }

    // Stringhez történõ konkatenáció operátor
    String operator+(const String& rhs_s) const ;

    // Karakterhez történõ konkatenáció operátor
    String operator+(char rhs_c) const { return *this + String(rhs_c);}

    // Indexelõ operátor (nem konstans)
    char& operator[](unsigned int idx);

    // Indexelõ operátor (konstans)
    const char& operator[](unsigned int idx) const;

    // Törlés mûvelet
    void erase() { *this = ""; }
};

// Kiíratás operátor
std::ostream& operator<<(std::ostream& os, const String& s0);

// Beolvasás operátor
std::istream& operator>>(std::istream& is, String& s0);

// Karakterhez történõ konkatenáció operátor (bal oldal)
inline String operator+(char ch, const String& str) { return String(ch) + str; }

#endif
