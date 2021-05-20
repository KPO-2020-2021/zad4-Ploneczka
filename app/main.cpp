// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#endif

#include <iostream>
#include <stdlib.h>
#include "Wektor3D.h"
#include "Prostopadloscian.h"

#include "exampleConfig.h"


/*
 * Simple main program that demontrates how access
 * CMake definitions (here the version number) from source code.
 */
char wybor;
int main() {
      Vector<double, 3> przesuniecie, w1, w2, w3, w4, w5, w6,w7, w8;
      Vector<double, 3> tab[8] ={w1, w2, w3, w4, w5, w6, w7, w8};
      w1[0] = 3;
      w1[1] = 3;
      w1[2] = 3;
      w2[0] = 8;
      w2[1] = 3;
      w2[2] = 3;
      w3[0] = 8;
      w3[1] = 3;
      w3[2] = 5;
      w4[0] = 3;
      w4[1] = 3;
      w4[2] = 5;
      w5[0] = 3;
      w5[1] = 6;
      w5[2] = 3;
      w6[0] = 8;
      w6[1] = 6;
      w6[2] = 3;
      w7[0] = 8;
      w7[1] = 6;
      w7[2] = 5;
      w8[0] = 3;
      w8[1] = 6;
      w8[2] = 5;
       

       Cuboid cub(tab);
      
       std::cout << "Aby wyswietlic menu wpisz m ...." <<std::endl;
       std::cout << "o - obrot prostokata o zadany kat" << std::endl;
       std::cout << "t - powtorzenie poprzedniego obrotu" <<std::endl;
       std::cout << "r - wyswietlenie macierzy rotacji" <<std::endl;
       std::cout << "p - przesuniecie prostokata o zadany wektor" << std::endl;
       std::cout << "w - wyswietlenie wspolrzednych wierzcholkow" << std::endl;
       std::cout << "m - wyswietl menu" << std::endl;
       std::cout << "k - koniec dzialania programu" << std::endl;
       
       do 
       {   
              std:: cin >> wybor ;
              switch (wybor)
              {
              case 'o':
              std::cout << "Wybrales obrot prostokata o dany kat. Podaj jego miare w stopniach : " <<std::endl;
                     double kat;
                     std::cin >> kat;
                    //  cub = cub.rotacja(kat);
              
                    //  rec.stworz_prost();
              
                    //  std:: cin.get();
                  
                     break;
              case 'p':
              std::cout << "Wybrales przesuniecie prostokata o dany wektor. Podaj jego wspolrzedne : " <<std::endl;
                     int x,y,z;
                     std::cin >> x >> y >> z;
                     przesuniecie[0] = x;
                     przesuniecie[1] = y;
                     przesuniecie[2] = z;
                     cub.translacja(przesuniecie);
              
                     cub.stworz_prostopadloscian();
                     std:: cin.get();
                     // std:: cin.get();
                     break;
              case 'w':
                     std::cout << "Wybrales wyswietlenie wspolrzednych protopadloscianu. Oto one : " <<std::endl << cub <<std::endl;
                     break;
              case 'm':
                     std::cout << "o - obrot prostokata o zadany kat" << std::endl;
                     std::cout << "p - przesuniecie prostokata o zadany wektor" << std::endl;
                     std::cout << "w - wyswietlenie wspolrzednych wierzcholkow" << std::endl;
                     std::cout << "m - wyswietl menu" << std::endl;
                     std::cout << "k - koniec dzialania programu" << std::endl;
                     break;
              case 'k':
                     std::cout << "Koniec programu. Zegnam ! " <<std::endl;
                     break;
              
              default:
                     break;
              }
       }while (wybor != 'k');
}

