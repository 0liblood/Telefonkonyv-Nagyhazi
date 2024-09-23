#include "nev.h"
#include "memtrace.h"

/**
 * Az `operator<<` függvény a `Nev` objektumot írja ki a megadott kimeneti adatfolyamra.
 * Az objektum `vezetektnev` és `keresztnev` adattagjait írja ki szóközzel elválasztva.
 * A függvény visszatérési értéke a kimeneti adatfolyam referenciája, amely lehetõvé teszi a láncolt írást.
 *
 * @param os A kimeneti adatfolyam, amelyre az objektum kiírásra kerül.
 * @param n A `Nev` objektum, amelyet ki szeretnénk írni.
 * @return A kimeneti adatfolyam referenciája.
 */
std::ostream& operator<<(std::ostream& os,const Nev& n){
    os<<n.getVezetektnev()<<" "<<n.getKeresztnev()<<"\t";
    return os;
}
