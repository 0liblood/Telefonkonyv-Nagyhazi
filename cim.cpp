#include "cim.h"
#include "memtrace.h"

/**
 * Az `operator<<` függvény a `Cim` objektumot írja ki a megadott kimeneti adatfolyamra.
 * Az objektum `orszag`, `iranyitoszam`, `varos`, `utca` és `hazszam` adattagjait írja ki szóközzel elválasztva.
 * A függvény visszatérési értéke a kimeneti adatfolyam referenciája, amely lehetõvé teszi a láncolt írást.
 *
 * @param os A kimeneti adatfolyam, amelyre az objektum kiírásra kerül.
 * @param c A `Cim` objektum, amelyet ki szeretnénk írni.
 * @return A kimeneti adatfolyam referenciája.
 */
std::ostream& operator<<(std::ostream& os,const Cim& c){
    os<<c.getOrszag()<<" "<<c.getIranyitoszam()<<" "<<c.getVaros()<<" "<<c.getUtca()<<" "<<c.getHazszam();
    return os;
}
