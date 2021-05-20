#pragma once

#include <iostream>
#include <cstdlib>


#define MIN 0.0000000001
template<typename T,   int SIZE>
class Matrix {

private:
    T value[SIZE][SIZE];               // Wartosci macierzy

public:
    Matrix(T [SIZE][SIZE]);            // Konstruktor klasy

    Matrix();                               // Konstruktor klasy

    Matrix operator + (Matrix tmp);

    Matrix operator * (Matrix tmp);

    T  &operator () (unsigned int row, unsigned int column);
    template<typename P,   int SIZE1>
    friend bool operator == (Matrix<P, SIZE1> mat1, Matrix<P, SIZE1> mat2);
    
    const T &operator () (unsigned int row, unsigned int column) const;
};
template<typename T,   int SIZE>
std::istream &operator>>(std::istream &in, Matrix<T, SIZE> &mat);
template<typename T,   int SIZE>
std::ostream &operator<<(std::ostream &out, Matrix<T,SIZE> const &mat);

/******************************************************************************
 |  Konstruktor klasy Matrix.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Macierz wypelnione wartoscia 0.                                       |
 */
template<typename T,   int SIZE>
Matrix<T, SIZE>::Matrix() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            value[i][j] = 0;
        }
    }
}


/******************************************************************************
 |  Konstruktor parametryczny klasy Matrix.                                              |
 |  Argumenty:                                                                |
 |      tmp - dwuwymiarowa tablica z elementami typu double.                               |
 |  Zwraca:                                                                   |
 |      Macierz wypelniona wartosciami podanymi w argumencie.                 |
 */
template<typename T,   int SIZE>
Matrix<T, SIZE>::Matrix(T tmp[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            value[i][j] = tmp[i][j];
        }
    }
}

/******************************************************************************
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy.                             |
 */
template<typename T,   int SIZE>
T &Matrix<T, SIZE>::operator()(unsigned int row, unsigned int column) {

    if (row >= SIZE) {
       throw std::out_of_range("Error: Macierz jest poza zasiegiem");
    }

    if (column >= SIZE) {
        throw std::out_of_range("Error: Macierz jest poza zasiegiem");
    }

    return value[row][column];
}


/******************************************************************************
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy jako stala.                  |
 */
template<typename T,   int SIZE>
const T &Matrix<T, SIZE>::operator () (unsigned int row, unsigned int column) const {

    if (row >= SIZE) {
           throw std::out_of_range("Error: Macierz jest poza zasiegiem");
    }

    if (column >= SIZE) {
          throw std::out_of_range("Error: Macierz jest poza zasiegiem");
    }

    return value[row][column];
}

/******************************************************************************
 |  Przeciążenie dodawania macierzy                                                          |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik dodawania,                     |
 |      v - wektor, czyli drugi skladnik dodawania.                                               |
 |  Zwraca:                                                                   |
 |      Macierz - iloczyn dwóch podanych macierzy.                  |
 */
template<typename T,   int SIZE>
Matrix<T, SIZE> Matrix<T, SIZE>::operator + (Matrix<T, SIZE> tmp) {
    Matrix<T, SIZE> result;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result(i, j) = this->value[i][j] + tmp(i, j);
        }
    }
    return result;
}
template<typename T,   int SIZE>
Matrix<T, SIZE> Matrix<T, SIZE>::operator * (Matrix<T, SIZE> tmp){
Matrix<T, SIZE> wynik;
for (int i = 0; i < SIZE; ++i)
{
    for (int j = 0; j < SIZE; ++j)
    {
        for (int k = 0; k < SIZE; ++k)
        {
            wynik(i,j) += value[i][k] * tmp(k,j);
        }
    }
}
 return wynik;
}

/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      mat - macierz.                                                         |
 */
template<typename T,   int SIZE>
std::istream &operator>>(std::istream &in, Matrix<T, SIZE> &mat) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            in >> mat(i, j);
        }
    }
    return in;
}


/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      mat - macierz.                                                        |
 */
template<typename T,   int SIZE>
std::ostream &operator<<(std::ostream &out, const Matrix<T, SIZE> &mat) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            out << "| " << mat(i, j) << " | "; //warto ustalic szerokosc wyswietlania dokladnosci liczb
        }
        std::cout << std::endl;
    }
    return out;
}
template<typename T,   int SIZE>
bool operator == (Matrix<T, SIZE> mat1, Matrix<T, SIZE> mat2)
{
    for (int i=0 ; i <SIZE ;i++)
    {
        for (int j=0 ; j <SIZE ;j++)
        {
            if (abs(mat1(i,j) - mat2(i,j)) > MIN)
            {   
                return false;
            }
        
        }
    }
    return true;
}