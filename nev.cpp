#include "nev.h"
#include "memtrace.h"

/**
 * Az `operator<<` f�ggv�ny a `Nev` objektumot �rja ki a megadott kimeneti adatfolyamra.
 * Az objektum `vezetektnev` �s `keresztnev` adattagjait �rja ki sz�k�zzel elv�lasztva.
 * A f�ggv�ny visszat�r�si �rt�ke a kimeneti adatfolyam referenci�ja, amely lehet�v� teszi a l�ncolt �r�st.
 *
 * @param os A kimeneti adatfolyam, amelyre az objektum ki�r�sra ker�l.
 * @param n A `Nev` objektum, amelyet ki szeretn�nk �rni.
 * @return A kimeneti adatfolyam referenci�ja.
 */
std::ostream& operator<<(std::ostream& os,const Nev& n){
    os<<n.getVezetektnev()<<" "<<n.getKeresztnev()<<"\t";
    return os;
}
