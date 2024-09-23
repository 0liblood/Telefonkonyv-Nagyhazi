#include "szam.h"
#include "memtrace.h"

/**
 * Az `operator<<` függvény a `Szam` objektumot írja ki a megadott kimeneti adatfolyamra.
 * Az objektum `privat` és `munkahelyi` adattagjait írja ki szóközzel elválasztva.
 * A függvény visszatérési értéke a kimeneti adatfolyam referenciája, amely lehetõvé teszi a láncolt írást.
 *
 * @param os A kimeneti adatfolyam, amelyre az objektum kiírásra kerül.
 * @param s A `Szam` objektum, amelyet ki szeretnénk írni.
 * @return A kimeneti adatfolyam referenciája.
 */
std::ostream& operator<<(std::ostream& os,const Szam& s){
    os<<s.getPrivat()<<" "<<s.getMunkahelyi()<<"\t";
    return os;
}

