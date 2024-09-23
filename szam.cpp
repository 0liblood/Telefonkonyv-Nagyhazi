#include "szam.h"
#include "memtrace.h"

/**
 * Az `operator<<` f�ggv�ny a `Szam` objektumot �rja ki a megadott kimeneti adatfolyamra.
 * Az objektum `privat` �s `munkahelyi` adattagjait �rja ki sz�k�zzel elv�lasztva.
 * A f�ggv�ny visszat�r�si �rt�ke a kimeneti adatfolyam referenci�ja, amely lehet�v� teszi a l�ncolt �r�st.
 *
 * @param os A kimeneti adatfolyam, amelyre az objektum ki�r�sra ker�l.
 * @param s A `Szam` objektum, amelyet ki szeretn�nk �rni.
 * @return A kimeneti adatfolyam referenci�ja.
 */
std::ostream& operator<<(std::ostream& os,const Szam& s){
    os<<s.getPrivat()<<" "<<s.getMunkahelyi()<<"\t";
    return os;
}

