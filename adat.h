#ifndef ADAT_H
#define ADAT_H

#include "string5.h"
using std::cout;

class Adat {
public:
    /// Virtu�lis f�ggv�ny, amely fel�l lesz �rva az ebb�l sz�rmaztatott oszt�lyok f�ggv�ny�vel
    virtual void kiir() const {}

    /// Virtu�lis destruktor
    virtual ~Adat() {}
};

#endif
