#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cstring>
#include <string>

// String oszt�ly deklar�ci�ja
class String {
    char *pData;
    size_t len;
public:
    // M�ret lek�rdez�se
	size_t size() const { return len; }

    // Alap�rtelmezett konstruktor
    String() : pData(0), len(0) {}

    // Konstruktor std::string-b�l
    String(const std::string& str): pData(new char[str.size() + 1]), len(str.size()){
        std::strcpy(pData, str.c_str());
    }

    // Karakter konstruktor
    String(char ch);

    // Konstruktor karaktert�mbb�l
    String(const char *p);

    // M�sol� konstruktor
    String(const String& s1);

    // Destruktor
    ~String() { delete[] pData; }

    // C-sztring lek�rdez�se
    const char* c_str() const { if (pData) return pData; else return "";}

    // Hibaellen�rz�shez haszn�lt print f�ggv�ny
    void printDbg(const char *txt = "") const {
        std::cout << txt << "[" << len << "], "
                  << (pData ? pData : "(NULL)") << std::endl;
    }

    // �rt�kad� oper�tor
    String& operator=(const String& rhs_s);

    // Stringhez t�rt�n� hozz�ad�s oper�tor
    String& operator+=(const String& rhs_s) {
        *this = *this + rhs_s;
        return *this;
    }

    // Egyenl�s�gvizsg�lat oper�tor
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

    // Stringhez t�rt�n� konkaten�ci� oper�tor
    String operator+(const String& rhs_s) const ;

    // Karakterhez t�rt�n� konkaten�ci� oper�tor
    String operator+(char rhs_c) const { return *this + String(rhs_c);}

    // Indexel� oper�tor (nem konstans)
    char& operator[](unsigned int idx);

    // Indexel� oper�tor (konstans)
    const char& operator[](unsigned int idx) const;

    // T�rl�s m�velet
    void erase() { *this = ""; }
};

// Ki�rat�s oper�tor
std::ostream& operator<<(std::ostream& os, const String& s0);

// Beolvas�s oper�tor
std::istream& operator>>(std::istream& is, String& s0);

// Karakterhez t�rt�n� konkaten�ci� oper�tor (bal oldal)
inline String operator+(char ch, const String& str) { return String(ch) + str; }

#endif
