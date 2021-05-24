#include "doctest.h"
#include "Wektor3D.h"
#include "Prostopadloscian.h"
#include <sstream>

// Tests that don't naturally fit in the headers/.cpp files directly
// can be placed in a tests/*.cpp file. Integration tests are a good example.

TEST_CASE("konstruktor domyslny wektor")
{
  Vector<double, 3> wek1;
  Vector<double, 3> wek2;
  wek1[0] = 0;
  wek1[1] = 0;
  wek1[2] = 0;

  CHECK_EQ(wek1, wek2);
}
TEST_CASE("konstruktor parametryczny  wektor")
{
  double a[3] = {1,1,2};
  Vector<double, 3> wek1;
  Vector<double, 3> wek2(a);
  
  wek1[0] = 1;
  wek1[1] = 1;
  wek1[2] = 2;

  CHECK_EQ(wek1, wek2);
}
TEST_CASE("<<")
{
  std::stringstream ss;

  Vector<double, 3> wek1;
  ss <<wek1;
  

  CHECK_EQ(ss.str(), "0 0 0 ");
}
TEST_CASE(">>")
{
  std::stringstream ss;

  Vector<double, 3> wek1;
  Vector<double, 3> wek2;
  ss <<"2 2 3 ";
  ss >> wek1;
  wek2[0] = 2;
  wek2[1] = 2;
  wek2[2] = 3;
  

  CHECK_EQ(wek1, wek2);
}
TEST_CASE("ideks")
{
  Vector<double, 3> wek2;
  wek2[0] = 2;
  wek2[1] = 2;
  wek2[2] = 3;
  CHECK_EQ(wek2[2], 3);
}
TEST_CASE("poza indeksem")
{
  Vector<double, 3> wek2;
  wek2[0] = 2;
  wek2[1] = 2;
  wek2[2] = 3;
  WARN_THROWS(wek2[3]);
}
TEST_CASE(" indeks z constem")
{
  Vector<double, 3> wek2;
  const double b = wek2[0];
  CHECK_EQ(b, 0);
}
TEST_CASE("Macierz domyslny")
{
  Matrix<double, 3> m1, m2;
  m2(0,0) = 0;
  m2(0,1) = 0;
  m2(0,2) = 0;
  m2(1,0) = 0;
  m2(1,1) = 0;
  m2(1,2) = 0;
  m2(2,0) = 0;
  m2(2,1) = 0;
  m2(2,2) = 0;
  CHECK_EQ(m1, m2);
}
TEST_CASE("Macierz parametryczna")
{
  double dwu[3][3];
  dwu[0][0] = 0;
  dwu[0][1] = 0;
  dwu[0][2] = 0;
  dwu[1][0] = 0;
  dwu[1][1] = 0;
  dwu[1][2] = 0;
  dwu[2][0] = 0;
  dwu[2][1] = 0;
  dwu[2][2] = 0;
  Matrix<double, 3> m1,m2(dwu);
  
  CHECK_EQ(m1, m2);
}
TEST_CASE("Macierz x Wektor")
{
  Matrix<double, 3> m1;
  Vector<double, 3> a1, wynik;
  wynik[0] = 14;
  wynik[1] = 21;
  wynik[2] = 11;
  a1[0] = 2;
  a1[1] = 3;
  a1[2] = 2;
  m1(0,0) = 1;
  m1(0,1) = 2;
  m1(0,2) = 3;
  m1(1,0) = 4;
  m1(1,1) = 3;
  m1(1,2) = 2;
  m1(2,0) = 2;
  m1(2,1) = 1;
  m1(2,2) = 2;
  CHECK_EQ(m1*a1, wynik);
}
TEST_CASE("Macierz indeks bez const")
{
  Matrix<double, 3> m1;
  m1(0,0) = 1;
  m1(0,1) = 2;
  m1(1,0) = 3;
  m1(1,1) = 2;

  CHECK_EQ(m1(1,0), 3);
}
TEST_CASE("Macierz indeks z consta")
{
  Matrix<double, 3> m1;
  const double b = m1(0,0);
 
  CHECK_EQ(b, 0);
}
TEST_CASE("Macierz obrot wokol osi X")
{
  Vector<double, 3> wek1, wek2;
  double kat = 180;
  wek1[0] = 1;
  wek1[1] = 1;
  wek1[2] = 1;
  wek2[0] = 1;
  wek2[1] = -1;
  wek2[2] = -1;

  wek1 = wek1.rotacja_x(kat);
  CHECK_EQ(wek2, wek1);
}
TEST_CASE("Macierz obrot wokol osi Z")
{
  Vector<double, 3> wek1, wek2;
  double kat = 180;
  wek1[0] = 1;
  wek1[1] = 1;
  wek1[2] = 1;
  wek2[0] = -1;
  wek2[1] = -1;
  wek2[2] = 1;

  wek1 = wek1.rotacja_z(kat);
  CHECK_EQ(wek2, wek1);
}
TEST_CASE("Macierz obrot wokol osi Y")
{
  Vector<double, 3> wek1, wek2;
  double kat = 180;
  wek1[0] = 1;
  wek1[1] = 1;
  wek1[2] = 1;
  wek2[0] = -1;
  wek2[1] = 1;
  wek2[2] = -1;

  wek1 = wek1.rotacja_y(kat);
  CHECK_EQ(wek2, wek1);
}
TEST_CASE("Macierz x Macierz")
{
  Matrix<double, 3> mat1, mat2, mat3;
  mat1(0,0) = 1;
  mat1(0,1) = 2;
  mat1(0,2) = 3;
  mat1(1,0) = 4;
  mat1(1,1) = 3;
  mat1(1,2) = 2;
  mat1(2,0) = 2;
  mat1(2,1) = 1;
  mat1(2,2) = 2;

  mat2(0,0) = 2;
  mat2(0,1) = 4;
  mat2(0,2) = 3;
  mat2(1,0) = 3;
  mat2(1,1) = 2;
  mat2(1,2) = 2;
  mat2(2,0) = 2;
  mat2(2,1) = 1;
  mat2(2,2) = 1;

  mat3(0,0) = 14;
  mat3(0,1) = 11;
  mat3(0,2) = 10;
  mat3(1,0) = 21;
  mat3(1,1) = 24;
  mat3(1,2) = 20;
  mat3(2,0) = 11;
  mat3(2,1) = 12;
  mat3(2,2) = 10;

  CHECK_EQ(mat1*mat2, mat3);
}
TEST_CASE("Prostopadloscian bezparametryczny")
{
  Cuboid cub1, cub2;
  CHECK_EQ(cub1, cub2);
}

TEST_CASE("Prostopadloscian parametryczny")
{
  Vector <double, 3> w[8];
  
  Cuboid cub1, cub2(w);
  CHECK_EQ(cub2, cub1);
}
TEST_CASE("Idenks z constem i bez consta")
{
  Vector<double, 3> w1;
  w1[2] = 4;
  Cuboid cub1;
  cub1[0] =w1;
  CHECK_EQ(cub1[0], w1);

  const Vector<double, 3> w2 = cub1[0];

  CHECK_EQ(w2, w1);
}
TEST_CASE("Prostopadloscian translacja")
{
  Vector<double, 3> w1;
  w1[0] = 1;
  w1[1] = 1;
  w1[2] = 1;
  Cuboid cub1, cub2;
  cub1.translacja(w1);
  for (int i = 0; i < CUBOID_SIZE; i++)
  {
    cub2[i] = w1;
  }
  CHECK_EQ(cub2, cub1);
}
TEST_CASE("Rotacja prostopadlsocian  o katy 90, 90, 90")
{
  Vector<double, 3> w1,w2,w3,w4,w5,w6,w7,w8, wi1,wi2,wi3,wi4,wi5,wi6,wi7,wi8 ;
  double kat1 = 90, kat2 = 90, kat3 = 90;
  
      wi1[0] = 8;
      wi1[1] = 3;
      wi1[2] = 5;

      wi2[0] = 8;
      wi2[1] = 6;
      wi2[2] = 5;

      wi3[0] = 8;
      wi3[1] = 3;
      wi3[2] = 3;

      wi4[0] = 8;
      wi4[1] = 6;
      wi4[2] = 3;

      wi5[0] = 3;
      wi5[1] = 3;
      wi5[2] = 3;
      
      wi6[0] = 3;
      wi6[1] = 6;
      wi6[2] = 3;
      
      wi7[0] = 3;
      wi7[1] = 3;
      wi7[2] = 5;
      
      wi8[0] = 3;
      wi8[1] = 6;
      wi8[2] = 5;
    
    Vector<double, 3> tab2[8] ={wi1, wi2, wi3, wi4, wi5, wi6, wi7, wi8};
    Cuboid cub1(tab2);

  cub1.rotacja_x(kat1);
  cub1.rotacja_y(kat2);
  cub1.rotacja_z(kat3);

      w1[0] = 5;
      w1[1] = 3;
      w1[2] = -8;

      w2[0] = 5;
      w2[1] = 6;
      w2[2] = -8;

      w3[0] = 3;
      w3[1] = 3;
      w3[2] = -8;

      w4[0] = 3;
      w4[1] = 6;
      w4[2] = -8;

      w5[0] = 3;
      w5[1] = 3;
      w5[2] = -3;
      
      w6[0] = 3;
      w6[1] = 6;
      w6[2] = -3;
      
      w7[0] = 5;
      w7[1] = 3;
      w7[2] = -3;
      
      w8[0] = 5;
      w8[1] = 6;
      w8[2] = -3;
  Vector<double, 3> tab[8] ={w1, w2, w3, w4, w5, w6, w7, w8};
  Cuboid cub2(tab);
  CHECK_EQ(cub2, cub1);
}
TEST_CASE("Rowne boki")
{
Vector<double, 3> wi1,wi2,wi3,wi4,wi5,wi6,wi7,wi8 ;
  
      wi1[0] = 8;
      wi1[1] = 3;
      wi1[2] = 5;

      wi2[0] = 8;
      wi2[1] = 6;
      wi2[2] = 5;

      wi3[0] = 8;
      wi3[1] = 3;
      wi3[2] = 3;

      wi4[0] = 8;
      wi4[1] = 6;
      wi4[2] = 3;

      wi5[0] = 3;
      wi5[1] = 3;
      wi5[2] = 3;
      
      wi6[0] = 3;
      wi6[1] = 6;
      wi6[2] = 3;
      
      wi7[0] = 3;
      wi7[1] = 3;
      wi7[2] = 5;
      
      wi8[0] = 3;
      wi8[1] = 6;
      wi8[2] = 5;
    
    Vector<double, 3> tab2[8] ={wi1, wi2, wi3, wi4, wi5, wi6, wi7, wi8};
    Cuboid cub1(tab2);
  CHECK_FALSE(!(cub1.sprawdz_boki()));
}
TEST_CASE("Rozne boki")
{
Vector<double, 3> wi1,wi2,wi3,wi4,wi5,wi6,wi7,wi8 ;
  
      wi1[0] = 8;
      wi1[1] = 3;
      wi1[2] = 5;

      wi2[0] = 8;
      wi2[1] = 6;
      wi2[2] = 5;

      wi3[0] = 8;
      wi3[1] = 3;
      wi3[2] = 3;

      wi4[0] = 8;
      wi4[1] = 6;
      wi4[2] = 3;

      wi5[0] = 3;
      wi5[1] = 3;
      wi5[2] = 3;
      
      wi6[0] = 3;
      wi6[1] = 6;
      wi6[2] = 21;
      
      wi7[0] = 3;
      wi7[1] = 3;
      wi7[2] = 5;
      
      wi8[0] = 3;
      wi8[1] = 5;
      wi8[2] = 7;
    
    Vector<double, 3> tab2[8] ={wi1, wi2, wi3, wi4, wi5, wi6, wi7, wi8};
    Cuboid cub1(tab2);
  CHECK_FALSE(cub1.sprawdz_boki());
}
