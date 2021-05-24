#pragma once/**
@file Prostopadloscian.h
@brief Tutaj znajduje sie Prostopadloscian wraz z definicja.
*/

#include "Wektor3D.h"
#include <fstream>
#include "lacze_do_gnuplota.h"
#define CUBOID_SIZE 8
class Cuboid
{   
    private:
    Vector<double, 3> wierz[CUBOID_SIZE];
    Matrix<double, 3> Macierz_obortu;

    public:
    /**
    @brief konstruktor domyslny 
    @return Wierzcholki prostopadlsocianu  wypelnione zerami 

    */
    Cuboid ();
    /**
    @brief konstruktor parametryczny
    @return Wierzcholki prospadloscianu wypelniona wartosciami podanymi w argumencie.  

    */
    Cuboid(Vector<double, 3> w[CUBOID_SIZE]);
    friend bool operator == (const Cuboid &cub1, const Cuboid &cub2);  ///< operator porownania dwoch prostopadloscianow
    /**
    @brief indeks prostopadloscianu
    @return Wartosc prostopadloscianu w danym miejscu tablicy jako stala.

    */  
    const Vector<double, 3> &operator [] (int index) const;
    /**
    @brief indeks prostopadloscianu
    @return Wartosc prostopadloscianu s w danym miejscu tablicy. 

    */    
    Vector<double, 3> &operator [] (int index);

    void rotacja_x(const double &kat); ///< Rotacja prospadloscianu wzgledem osi OX
    void rotacja_y(const double &kat);  ///< Rotacja prospadloscianu wzgledem osi OX
    void rotacja_z(const double &kat);  ///< Rotacja prospadloscianu wzgledem osi OX
    void stworz_prostopadloscian() const;  ///< Tworzenie prostopadloscianu i rysowanie go w Gnuplocie
    bool sprawdz_boki() const; ///< Funkcja sprawdzajacy czy boki powstalej figury sa rowne, a za tem czy jest on prostopadloscianem
    void wyswietl_macierz() const ; ///< Funkcja pozwalajaca na wyswietlenie danej macierzy

    void translacja(const Vector<double, 3> &wek1); ///< Funckja, ktora przesuwa prostopadloscian w 3 wymiarach o zadany wektor
};
std::ostream &operator << (std::ostream &out, Cuboid const &tmp); ///< przeciazony operator wypisywania
std::istream &operator >> (std::istream &in, Cuboid const &tmp); ///< przeciazony operator wczytywania


Cuboid::Cuboid()
{
    Macierz_obortu(0,0) = 1;
    Macierz_obortu(1,1) = 1;
    Macierz_obortu(2,2) = 1;
    for (int i =0; i <CUBOID_SIZE; i++)
    {
        wierz[i] = Vector<double, 3> ();
    }
}
Cuboid::Cuboid(Vector<double, 3> w[CUBOID_SIZE])
{
    Macierz_obortu(0,0) = 1;
    Macierz_obortu(1,1) = 1;
    Macierz_obortu(2,2) = 1;
    for (int i =0; i <CUBOID_SIZE; i++)
    {
        wierz[i] = w[i];
    }
} 
bool operator == (const Cuboid &cub1, const Cuboid &cub2)
{
    for(int i =0; i < CUBOID_SIZE; i++)
    {
        if(!(cub1[i] == cub2[i]))
        {
            return false;
        }
    
    }
    return true;
}
const Vector<double, 3> &Cuboid::operator [] (int index) const
{   
     if (index < 0 || index >= CUBOID_SIZE) {
        throw std::out_of_range("Error: Cuboid jest poza zasiegiem!" );
    }
    return wierz[index];
}
Vector<double, 3> &Cuboid::operator [] (int index)
{
    if (index < 0 || index >= CUBOID_SIZE) {
        throw std::out_of_range("Error: Cuboid jest poza zasiegiem!" );
    }
    return wierz[index];
}
void Cuboid::rotacja_x(const double &kat)
{
     Matrix<double, 3> obrot;
    double kat_radiany = M_PI *kat /180;
    obrot(0,0) = 1;
    obrot(1,1) = cos(kat_radiany);
    obrot(1,2) = -sin(kat_radiany);
    obrot(2,1) = sin(kat_radiany);
    obrot(2,2) = cos(kat_radiany);
    Macierz_obortu = Macierz_obortu*obrot;
    for(int i = 0; i <CUBOID_SIZE; i++)
    {
        wierz[i] = obrot *wierz[i];
    }
}
void Cuboid::rotacja_y(const double &kat)
{
    Matrix<double, 3> obrot;
    double kat_radiany = M_PI *kat /180;
    obrot(0,0) = cos(kat_radiany);
    obrot(0,2) = sin(kat_radiany);
    obrot(1,1) = 1;
    obrot(2,0) = -sin(kat_radiany);
    obrot(2,2) = cos(kat_radiany);
    Macierz_obortu = Macierz_obortu*obrot;
    for(int i = 0; i <CUBOID_SIZE; i++)
    {
        wierz[i] = obrot *wierz[i];
    }
}
void Cuboid::rotacja_z(const double &kat)
{
    Matrix<double, 3> obrot;
    double kat_radiany = M_PI *kat /180;
    obrot(0,0) = cos(kat_radiany);
    obrot(0,1) = -sin(kat_radiany);
    obrot(1,0) = sin(kat_radiany);
    obrot(1,1) = cos(kat_radiany);
    obrot(2,2) = 1;
    Macierz_obortu = Macierz_obortu*obrot;
    for(int i = 0; i <CUBOID_SIZE; i++)
    {
        wierz[i] = obrot *wierz[i];
    }
}

void Cuboid::translacja(const Vector<double, 3> &wek1)
{
    for(int i = 0; i < CUBOID_SIZE; i++)
    {
        wierz[i] = wierz[i]+wek1;
    }

}
std::ostream &operator << (std::ostream &out, Cuboid const &tmp) {
    Vector<double, 3> srodek1, srodek2;
    srodek1 = tmp[2] - tmp[0];
    srodek1 = srodek1 /2;
    srodek1 = srodek1 + tmp[0];
    srodek2 = tmp [6] - tmp[4];
    srodek2 = srodek2 /2;
    srodek2 = srodek2 +tmp[4];
    out << srodek1 <<std::endl;
    out << tmp[2] <<std::endl;
    out << tmp[6] <<std::endl;
    out << srodek2 <<std::endl <<'#'<<std::endl <<std::endl;
    out << srodek1 <<std::endl;
    out << tmp[1] <<std::endl;
    out << tmp[5] <<std::endl;
    out << srodek2 <<std::endl <<'#'<<std::endl <<std::endl;
    out << srodek1 <<std::endl;
    out << tmp[0] <<std::endl;
    out << tmp[4] <<std::endl;
    out << srodek2 <<std::endl <<'#'<<std::endl <<std::endl;
    out << srodek1 <<std::endl;
    out << tmp[3] <<std::endl;
    out << tmp[7] <<std::endl;
    out << srodek2 <<std::endl <<'#'<<std::endl <<std::endl;
    out << srodek1 <<std::endl;
    out << tmp[2] <<std::endl;
    out << tmp[6] <<std::endl;
    out << srodek2 <<std::endl <<'#'<<std::endl <<std::endl;
    
    return out;
}
void Cuboid::stworz_prostopadloscian() const
{
    std::ofstream os("data.xy");
    if( !os.is_open())
    {
        throw std::invalid_argument("Plik sie nie otworzyl!.");
    }
    os <<*this;
    PzG::LaczeDoGNUPlota plot;
    plot.DodajNazwePliku("data.xy");
    plot.UstawZakresX(-20,20);
    plot.UstawZakresY(-20,20);
    plot.UstawZakresZ(-20,20);
    plot.Inicjalizuj();
    plot.ZmienTrybRys(PzG::TR_3D);
    plot.Rysuj();

}
bool Cuboid::sprawdz_boki() const
{
    Vector<double, 3> bok_AB,bok_BC,bok_CD,bok_DA,bok_EF,bok_FG,bok_GH,bok_HE,bok_AE,bok_BF,bok_CG,bok_DH;
    bok_AB = wierz[1] - wierz[0];
    bok_BC = wierz[2] - wierz[1];
    bok_CD = wierz[3] - wierz[2];
    bok_DA = wierz[0] - wierz[3];
    bok_EF = wierz[5] - wierz[4];
    bok_FG = wierz[6] - wierz[5];
    bok_GH = wierz[7] - wierz[6];
    bok_HE = wierz[4] - wierz[7];
    bok_AE = wierz[4] - wierz[0];
    bok_BF = wierz[5] - wierz[1];
    bok_CG = wierz[6] - wierz[2];
    bok_DH = wierz[7] - wierz[3];

    if((bok_AB.dl_boku() == bok_EF.dl_boku() && bok_AE.dl_boku() == bok_CG.dl_boku()))
    {
        return true;
    }
    return false;
}
void Cuboid::wyswietl_macierz() const 
{
    std::cout <<Macierz_obortu <<std::endl;
}