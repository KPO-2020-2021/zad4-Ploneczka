#pragma once

#include "Wektor3D.h"
#include <fstream>
#include "lacze_do_gnuplota.h"
#define CUBOID_SIZE 8
class Cuboid
{   
    private:
    Vector<double, 3> wierz[CUBOID_SIZE];

    public:
    Cuboid ();
    Cuboid(Vector<double, 3> w[CUBOID_SIZE]);
    friend bool operator == (const Cuboid &cub1, const Cuboid &cub2);

    const Vector<double, 3> &operator [] (int index) const;

    Vector<double, 3> &operator [] (int index);

    void rotacja_x(const double &kat);
    void rotacja_y(const double &kat);
    void rotacja_z(const double &kat);
    void stworz_prostopadloscian() const;

    void translacja(const Vector<double, 3> &wek1);
};
std::ostream &operator << (std::ostream &out, Cuboid const &tmp);
std::istream &operator >> (std::istream &in, Cuboid const &tmp);


Cuboid::Cuboid()
{
    for (int i =0; i <CUBOID_SIZE; i++)
    {
        wierz[i] = Vector<double, 3> ();
    }
}
Cuboid::Cuboid(Vector<double, 3> w[CUBOID_SIZE])
{
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
    for(int i = 0; i <CUBOID_SIZE; i++)
    {
        wierz[i] = wierz[i].rotacja_x(kat);
    }
}
void Cuboid::rotacja_y(const double &kat)
{
    for(int i = 0; i <CUBOID_SIZE; i++)
    {
        wierz[i] = wierz[i].rotacja_y(kat);
    }
}
void Cuboid::rotacja_z(const double &kat)
{
    for(int i = 0; i <CUBOID_SIZE; i++)
    {
        wierz[i] = wierz[i].rotacja_z(kat);
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
    srodek1 = tmp[5] - tmp[0];
    srodek1 = srodek1 /2;
    srodek1 = srodek1 + tmp[0];
    srodek2 = tmp [6] - tmp[3];
    srodek2 = srodek2 /2;
    srodek2 = srodek2 +tmp[3];
    out << srodek1 <<std::endl;
    out << tmp[1] <<std::endl;
    out << tmp[2] <<std::endl;
    out << srodek2 <<std::endl <<'#'<<std::endl <<std::endl;
    out << srodek1 <<std::endl;
    out << tmp[3] <<std::endl;
    out << tmp[4] <<std::endl;
    out << srodek2 <<std::endl <<'#'<<std::endl <<std::endl;
    out << srodek1 <<std::endl;
    out << tmp[5] <<std::endl;
    out << tmp[6] <<std::endl;
    out << srodek2 <<std::endl <<'#'<<std::endl <<std::endl;
    out << srodek1 <<std::endl;
    out << tmp[7] <<std::endl;
    out << tmp[8] <<std::endl;
    out << srodek2 <<std::endl <<'#'<<std::endl <<std::endl;
    out << srodek1 <<std::endl;
    out << tmp[1] <<std::endl;
    out << tmp[2] <<std::endl;
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