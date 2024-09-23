#ifndef ADAT_H
#define ADAT_H

#include "string5.h"
using std::cout;

class Adat {
public:
    /// Virtuális függvény, amely felül lesz írva az ebbõl származtatott osztályok függvényével
    virtual void kiir() const {}

    /// Virtuális destruktor
    virtual ~Adat() {}
};

#endif
