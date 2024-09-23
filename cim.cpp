#include "cim.h"
#include "memtrace.h"

/**
 * Az `operator<<` f�ggv�ny a `Cim` objektumot �rja ki a megadott kimeneti adatfolyamra.
 * Az objektum `orszag`, `iranyitoszam`, `varos`, `utca` �s `hazszam` adattagjait �rja ki sz�k�zzel elv�lasztva.
 * A f�ggv�ny visszat�r�si �rt�ke a kimeneti adatfolyam referenci�ja, amely lehet�v� teszi a l�ncolt �r�st.
 *
 * @param os A kimeneti adatfolyam, amelyre az objektum ki�r�sra ker�l.
 * @param c A `Cim` objektum, amelyet ki szeretn�nk �rni.
 * @return A kimeneti adatfolyam referenci�ja.
 */
std::ostream& operator<<(std::ostream& os,const Cim& c){
    os<<c.getOrszag()<<" "<<c.getIranyitoszam()<<" "<<c.getVaros()<<" "<<c.getUtca()<<" "<<c.getHazszam();
    return os;
}
