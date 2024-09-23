#include <iostream>
#include "konyv.h"

using std::cout;
using std::cin;

#include "memtrace.h"
#include "gtest_lite.h"


void teszt_1(Konyv& telefonkonyv)
{
    TEST(Teszt_1, adatrogzites)
    EXPECT_EQ(1, telefonkonyv.getMeret()) << "Rossz meret" << std::endl;
    telefonkonyv.adatrogzites(Szemely(Nev("Teszt","Istvan"),Szam("061234569","+367210124"),Cim("Magyarorszag","Szeged","Petofi utca","98","4391")));
    EXPECT_EQ(2, telefonkonyv.getMeret()) << "Rossz meret" << std::endl;
    Szemely sz = Szemely(Nev("Pelda","Jozsef"),Szam("+362398741","062381301"),Cim("Magyarorszag","Szekesfehervar","Jozsef Attila utca","1","1234"));
    telefonkonyv.adatrogzites(sz);
    EXPECT_EQ(3, telefonkonyv.getMeret()) << "Rossz meret" << std::endl;
    END

    TEST(Teszt_2, listazas)
    std::stringstream ss;
    telefonkonyv.listazas(ss);
    std::string s = ss.str();
    std::string str = "\nBenedek Oliver\t0612345678 +3630124234\tMagyarorszag 17 Budapest Irinyi utca\nTeszt Istvan\t061234569 +367210124\tMagyarorszag 4391 Szeged Petofi utca 98\nPelda Jozsef\t+362398741 062381301\tMagyarorszag 1234 Szekesfehervar Jozsef Attila utca 1\n\n";
    EXPECT_EQ(str,s) << "Hibas listazas" << std::endl;
    END

    TEST(Teszt_3, torles_2._sor)
    std::stringstream dump;
    telefonkonyv.torles(dump,1);
    EXPECT_EQ(2, telefonkonyv.getMeret()) << "Rossz meret" << std::endl;
    std::stringstream ss;
    telefonkonyv.listazas(ss);
    std::string s = ss.str();
    std::string str = "\nBenedek Oliver\t0612345678 +3630124234\tMagyarorszag 17 Budapest Irinyi utca\nPelda Jozsef\t+362398741 062381301\tMagyarorszag 1234 Szekesfehervar Jozsef Attila utca 1\n\n";
    EXPECT_EQ(str,s) << "Hibas listazas" << std::endl;
    END

    TEST(Teszt_4, torles_2._sor)
    std::stringstream dump;
    telefonkonyv.torles(dump,1);
    EXPECT_EQ(1, telefonkonyv.getMeret()) << "Rossz meret" << std::endl;
    std::stringstream ss;
    telefonkonyv.listazas(ss);
    std::string s = ss.str();
    std::string str = "\nBenedek Oliver\t0612345678 +3630124234\tMagyarorszag 17 Budapest Irinyi utca\n\n";
    EXPECT_EQ(str,s) << "Hibas listazas" << std::endl;
    END

    TEST(Teszt_5, valodi_nev_kereses)
    Nev valodinev = Nev("Benedek","Oliver");
    std::stringstream ss;
    telefonkonyv.kereses_nev(ss,valodinev);
    std::string s = ss.str();
    std::string str = "\nTalalt sor(ok):\nBenedek Oliver\t0612345678 +3630124234\tMagyarorszag 17 Budapest Irinyi utca\n";
    EXPECT_EQ(str,s) << "Hibas kereses" << std::endl;
    END

    TEST(Teszt_6, hibas_nev_kereses)
    Nev hibasnev = Nev("Nincs","Ilyen");
    std::stringstream ss;
    telefonkonyv.kereses_nev(ss,hibasnev);
    std::string s = ss.str();
    std::string str = "\nNincs talalat.\n";
    EXPECT_EQ(str,s) << "Hibas kereses" << std::endl;
    END
    cout<<"\n---> Teszt_6.Mentes\n";
    telefonkonyv.mentes();
}

int main()
{
    cout<<"\n    ######## ######## ##       ######## ########  #######  ##    ## ##    ##  #######  ##    ## ##    ## ##     ## \n       ##    ##       ##       ##       ##       ##     ## ###   ## ##   ##  ##     ## ###   ##  ##  ##  ##     ## \n       ##    ##       ##       ##       ##       ##     ## ####  ## ##  ##   ##     ## ####  ##   ####   ##     ## \n       ##    ######   ##       ######   ######   ##     ## ## ## ## #####    ##     ## ## ## ##    ##    ##     ## \n       ##    ##       ##       ##       ##       ##     ## ##  #### ##  ##   ##     ## ##  ####    ##     ##   ##  \n       ##    ##       ##       ##       ##       ##     ## ##   ### ##   ##  ##     ## ##   ###    ##      ## ##   \n       ##    ######## ######## ######## ##        #######  ##    ## ##    ##  #######  ##    ##    ##       ###    \n\n";

    // Sorok sz�m�nak meghat�roz�sa
    size_t sorok = sor_szamol();

    // Konyv objektum l�trehoz�sa a meghat�rozott sorok sz�m�val
    Konyv telefonkonyv(sorok);

    // Telefonk�nyv bet�lt�se
    telefonkonyv.betoltes();

    //Tesztel�s
    teszt_1(telefonkonyv);

bool futas = true;
while (futas == true) {
    char betu;

    // Felhaszn�l�t�l bek�rj�k a v�laszt a k�v�nt m�velethez
    cout << "\nMit szeretne csinalni?\n\t[A] - adatrogzites\n\t[L] - adatok listazasa\n\t[K] - kereses\n\t[M] - modositas\n\t[T] - torles\n\t[S] - mentes\n\t[E] - kilepes\n";
    cin >> betu;
    betu = tolower(betu);

    // A bek�rt v�laszt alapj�n el�gazunk a megfelel� m�velet v�grehajt�s�hoz
    switch (betu) {
        case 'a':
            // Adat r�gz�t�se
            telefonkonyv.adatrogzites();
            break;
        case 'l':
            // Adatok list�z�sa
            telefonkonyv.listazas(std::cout);
            break;
        case 'k':
            // Keres�s
            cout << "\nMi alapjan szeretne keresni?";
            telefonkonyv.kereses(std::cout);
            break;
        case 't':
            // T�rl�s
            cout << "\nMi alapjan szeretne torolni?";
            telefonkonyv.torles(cout, telefonkonyv.elso_talalat());
            break;
        case 'm':
            // M�dos�t�s
            cout << "\nMi alapjan szeretne modositani?";
            telefonkonyv.modositas(telefonkonyv.elso_talalat());
            break;
        case 's':
            // Ment�s
            telefonkonyv.mentes();
            break;
        case 'e':
            // Kil�p�s
            futas = false;
            break;
        }
    }
    return 0;
}
