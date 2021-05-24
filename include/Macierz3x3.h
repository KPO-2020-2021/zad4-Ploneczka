#pragma once/**
@file Macierz3x3.h
@brief Tutaj znajduje sie Macierz3x3 wraz z definicja.
*/

#include <iostream>
#include <cstdlib>


#define MIN 0.0000000001
template<typename T,   int SIZE>
class Matrix {

private:
    T value[SIZE][SIZE];               ///< Wartosci macierzy

public:
    /**
    @brief konstruktor parametryczny
    @return Macierz wypelniona wartosciami podanymi w argumencie.  

    */
   
    Matrix(T [SIZE][SIZE]);            
     /**
    @brief konstruktor domyslny 
    @return Macierz wypelniona zerami 

    */
    Matrix();                              

    Matrix operator + (Matrix tmp);  ///< przeciazony operator dodawania macierzy 

    Matrix operator * (Matrix tmp); ///< przeciazony operator mnozenia macierzy 
    /**
    @brief indeks macierzy 
    @return Wartosc macierzy w danym miejscu tablicy. 

    */    
    T  &operator () (unsigned int row, unsigned int column);
    template<typename P,   int SIZE1>
    friend bool operator == (Matrix<P, SIZE1> mat1, Matrix<P, SIZE1> mat2); ///< przeciazony operator porownania macierzy 
    /**
    @brief indeks macierzy 
    @return Wartosc macierzy w danym miejscu tablicy jako stala.

    */  
    const T &operator () (unsigned int row, unsigned int column) const;
};
template<typename T,   int SIZE>
std::istream &operator>>(std::istream &in, Matrix<T, SIZE> &mat);  ///< przeciazony operator wypisywania dla macierzy 
template<typename T,   int SIZE>
std::ostream &operator<<(std::ostream &out, Matrix<T,SIZE> const &mat); ///< przeciazony operator wczytywania dla macierzy 


template<typename T,   int SIZE>
Matrix<T, SIZE>::Matrix() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            value[i][j] = 0;
        }
    }
}


template<typename T,   int SIZE>
Matrix<T, SIZE>::Matrix(T tmp[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            value[i][j] = tmp[i][j];
        }
    }
}

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

template<typename T,   int SIZE>
std::istream &operator>>(std::istream &in, Matrix<T, SIZE> &mat) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            in >> mat(i, j);
        }
    }
    return in;
}


template<typename T,   int SIZE>
std::ostream &operator<<(std::ostream &out, const Matrix<T, SIZE> &mat) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            out << "| " << mat(i, j) << " | "; 
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