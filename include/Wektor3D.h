#pragma once

#include "Macierz3x3.h"
#include <iostream>
#include <math.h>
#define MIN 0.0000000001

template<typename T,   int SIZE>
class Vector {

private:

    T tab[SIZE];     //Tablica wektora

public:

    Vector();

    Vector(T a[SIZE]);

    Vector operator + (const Vector &v) const;

    Vector operator - (const Vector &v) const;

    Vector operator * (const T &tmp) const;

    Vector operator / (const T &tmp) const;
    template<typename T1,   int SIZE1>
    friend Vector<T1, SIZE1> operator * (Matrix<T1, SIZE1> m1, Vector<T1, SIZE1> tmp);           // Operator mnożenia przez wektor
   
    template<typename T1,   int SIZE1>
    friend bool operator == (Vector<T1, SIZE1> vec1, Vector<T1, SIZE1> vec2);
    
    const T &operator [] (int index) const;

    T &operator [] (int index);

    Vector rotacja_x(const double &kat) const;
    Vector rotacja_y(const double &kat) const;
    Vector rotacja_z(const double &kat) const;

    double dl_boku () const;

};
template<typename T,   int SIZE>
std::ostream &operator << (std::ostream &out, Vector<T, SIZE> const &tmp);
template<typename T,   int SIZE>
std::istream &operator >> (std::istream &in, Vector<T, SIZE> &tmp);

/******************************************************************************
 |  Konstruktor klasy Vector.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartoscia 0.                                       |
 */
template<typename T,   int SIZE>
Vector<T, SIZE>::Vector() {
    for ( int i = 0; i < SIZE; i++) {
        tab[i] = 0;
    }
}


/******************************************************************************
 |  Konstruktor klasy Vector.                                                 |
 |  Argumenty:                                                                |
 |      tmp - Jednowymiarowa tablica typu double.                             |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartosciami podanymi w argumencie.                 |
 */
template<typename T,   int SIZE>
Vector<T, SIZE>::Vector(T tmp[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        tab[i] = tmp[i];
    }
}


/******************************************************************************
 |  Realizuje dodawanie dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik dodawania,                                   |
 |      v - drugi skladnik dodawania.                                         |
 |  Zwraca:                                                                   |
 |      Sume dwoch skladnikow przekazanych jako wskaznik                      |
 |      na parametr.                                                          |
 */
template<typename T,   int SIZE>
Vector<T, SIZE> Vector<T, SIZE>::operator + (const Vector<T, SIZE> &v) const{
    Vector<T, SIZE> result;
    for (int i = 0; i < SIZE; i++) {
        result[i] = tab[i] + v[i];
    }
    return result;
}


/******************************************************************************
 |  Realizuje odejmowanie dwoch wektorow.                                     |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik odejmowania,                                 |
 |      v - drugi skladnik odejmowania.                                       |
 |  Zwraca:                                                                   |
 |      Roznice dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */
template<typename T,   int SIZE>
Vector<T, SIZE> Vector<T,SIZE>::operator - (const Vector<T,SIZE> &v) const {
    Vector<T, SIZE> result;
    for (int i = 0; i < SIZE; i++) {
        result[i] = tab[i] - v[i];
    }
    return result;
}


/******************************************************************************
 |  Realizuje mnozenie wektora przez liczbe zmiennoprzecinkowa.               |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik mnozenia (wektor),                           |
 |      v - drugi skladnik mnozenia (liczba typu double).                     |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */
template<typename T,   int SIZE>
Vector<T,SIZE> Vector<T, SIZE>::operator * (const T &tmp) const {
    Vector<T, SIZE> result;
    for (int i = 0; i < SIZE; i++) {
        result[i] =  tab[i] * tmp;
    }
    return result;
}


/******************************************************************************
 |  Realizuje dzielenie dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - licznik dzielenia,                                             |
 |      v - mianownik dzielenia.                                              |
 |  Zwraca:                                                                   |
 |      Iloraz dwoch skladnikow przekazanych jako wskaznik                    |
 |      na parametr.                                                          |
 */
template<typename T,   int SIZE>
Vector<T,SIZE> Vector<T, SIZE>::operator / (const T &tmp)const{
    Vector<T, SIZE> result;

    for (int i = 0; i < SIZE; i++) {
        result[i] = tab[i] / tmp;
    }

    return result;
}


/******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy jako stala.                   |
 */
template<typename T,   int SIZE>
const T &Vector<T, SIZE>::operator [] (int index) const {
    if (index < 0 || index >= SIZE) {
        throw std::out_of_range("Error: Wektor jest poza zasiegiem!" );
    }
    return tab[index];
}


/******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy.                              |
 */
template<typename T,   int SIZE>
T &Vector<T, SIZE>::operator[](int index) {
    return const_cast<T &>(const_cast<const Vector<T, SIZE> *>(this)->operator[](index));
}


/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      tmp - wektor.                                                         |
 */
template<typename T,   int SIZE>
std::ostream &operator << (std::ostream &out, Vector<T, SIZE> const &tmp) {
    for (int i = 0; i < SIZE; i++) {
        out << tmp[i] << " ";
    }
    return out;
}
template<typename T,   int SIZE>
bool operator == (Vector<T, SIZE> vec1, Vector<T, SIZE> vec2)
{
    for(int i = 0; i< SIZE;i++)
    {
        if (abs(vec1[i] - vec2[i]) >MIN)
        {   
            return false;
        }
    }
    return true; 
}


/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      tmp - wektor.                                                         |
 */
template<typename T,   int SIZE>
std::istream &operator >> (std::istream &in, Vector <T, SIZE>&tmp) {
    for (int i = 0; i < SIZE; i++) {
        in >> tmp[i];
    }
    std::cout << std::endl;
    return in;
}

template<typename T,   int SIZE>
Vector<T, SIZE> Vector<T, SIZE>::rotacja_x(const double &kat) const
{
    if (SIZE != 3)
    {
        throw std::invalid_argument("zly wymiar");
    }
    Matrix<T, SIZE> obrot;
    double kat_radiany = M_PI *kat /180;
    obrot(0,0) = 1;
    obrot(1,1) = cos(kat_radiany);
    obrot(1,2) = -sin(kat_radiany);
    obrot(2,1) = sin(kat_radiany);
    obrot(2,2) = cos(kat_radiany);
    return obrot* *this;

}
template<typename T,   int SIZE>
Vector<T, SIZE> Vector<T, SIZE>::rotacja_y(const double &kat) const
{
    if (SIZE != 3)
    {
        throw std::invalid_argument("zly wymiar");
    }
    Matrix<T, SIZE> obrot;
    double kat_radiany = M_PI *kat /180;
    obrot(0,0) = cos(kat_radiany);
    obrot(0,2) = sin(kat_radiany);
    obrot(1,1) = 1;
    obrot(2,0) = -sin(kat_radiany);
    obrot(2,2) = cos(kat_radiany);
    return obrot* *this;
    
}
template<typename T,   int SIZE>
Vector<T, SIZE> Vector<T, SIZE>::rotacja_z(const double &kat) const
{
    if (SIZE != 3)
    {
        throw std::invalid_argument("zly wymiar");
    }
    Matrix<T, SIZE> obrot;
    double kat_radiany = M_PI *kat /180;
    obrot(0,0) = cos(kat_radiany);
    obrot(0,1) = -sin(kat_radiany);
    obrot(1,0) = sin(kat_radiany);
    obrot(1,1) = cos(kat_radiany);
    obrot(2,2) = 1;
    return obrot* *this;
}

/******************************************************************************
 |  Realizuje mnozenie macierzy przez wektor.                                 |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik mnozenia,                     |
 |      v - wektor, czyli drugi skladnik mnozenia.                            |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wektor.                    |
 */
template<typename T,   int SIZE>
Vector<T, SIZE> operator * (Matrix<T, SIZE> m1, Vector<T, SIZE> tmp) {
    Vector<T, SIZE> result;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i] += m1(i,j) * tmp[j];
        }
    }
    return result;
}
template<typename T,   int SIZE>
double Vector<T, SIZE>::dl_boku() const
{
    double dlugosc = 0;
    for (int i= 0;i<SIZE; i++)
    {
        dlugosc += pow(tab[i], 2);
    }
    return sqrt(dlugosc);
}