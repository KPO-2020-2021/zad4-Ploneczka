#include "Macierz3x3.h"
#include "Wektor3D.h"

typedef Matrix<double, 4> Macierz4x4;

Macierz4x4 Obroty_przesun(double alfa, double beta, double gamma, Vector<double, 3> przesun )
{
    Macierz4x4 wynik;
    double alfa2 = alfa*M_PI/180;
    double beta2 = beta*M_PI/180;
    double gamma2 = gamma*M_PI/180;
     wynik(0,0) = cos(alfa2) * cos(beta2);
     wynik(0,1) = cos(alfa2) * sin(beta2) * sin(gamma2) - sin(alfa2) * cos(gamma2);
     wynik(0,2) = cos(alfa2) * sin(beta2) * cos(gamma2) + sin(alfa2) * sin(gamma2);
     wynik(0,3) = przesun[0];
     wynik(1,0) = sin(alfa2) * cos(beta2);
     wynik(1,1) = sin(alfa2) * sin(beta2) * sin(gamma2) + cos(alfa2) * cos(gamma2);
     wynik(1,2) = sin(alfa2) * sin(beta2) * cos(gamma2) - cos(alfa2) * sin(gamma2);
     wynik(1,3) = przesun[1];
     wynik(2,0) = -sin(beta2);
     wynik(2,1) = cos(beta2) * sin(gamma2);
     wynik(2,2) = cos(beta2) * cos(gamma2);
     wynik(2,3) = przesun[2];
     wynik(3,0) = 0;
     wynik(3,1) = 0;
     wynik(3,2) = 0;
     wynik(3,3) = 1;
    return wynik;
}