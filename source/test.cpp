//
// Created by punkostigyork on 2023.04.23..
//

#include "converter.h"
#include "bignum.h"
#include "fermat.h"
#include <iostream>
#include <cstring>

int main() {
//    unsigned long long arr[] = {1, 0, 3, 5, 9, 7, 8, 3, 5, 5, 6, 9, 8, 7, 3};
//    size_t size = 15;
//    unsigned long long arr1[] = {9, 9};
//    size_t size1 = 2;
//
//    BigNum a(size, 10, 1, arr);
//    for(size_t i = 0; i < a.getsize(); i++)
//        std::cout << std::endl << i << ": " << a.getdigits()[i];
//    std::cout << std::endl;
//
//    BigNum b(size1, 10, 1, arr1);
//    for(size_t i = 0; i < b.getsize(); i++)
//        std::cout << std::endl << i << ": " << b.getdigits()[i];
//    std::cout << std::endl;
//
//    BigNum c;
//    c = a / b;
//    for(size_t i = 0; i < c.getsize(); i++)
//        std::cout << std::endl << i << ": " << c.getdigits()[i];
//    std::cout << std::endl;


    char* a, *b;
    a = readString();
//    b = readString();

    BigNum A, B;
    numSysConv(a, A);
//    numSysConv(b, B);

//    if(A <= B)
//        std::cout <<"megy";

    BigNum C = A;

    unsigned long long zero[] = {0};
    BigNum ZERO(1, 10, 0, zero);



//    BigNum D = A + B;
//    fermat_GCD(A, B, D);
//
//    std::cout << std::endl;
//    for(size_t i = 0; i < D.getsize(); i++)
//        std::cout << i << ": " << D.getdigits()[i] << std::endl;
//    std::cout << std::endl;

    if(fermat_prime(C, 100))
        std::cout << "prim";
    else std::cout << "nem prim";

    delete[] a;
//    delete[] b;


//    BigNum random;
//    fermat_random(b, random);
//    for(size_t i = 0; i < random.getsize(); i++)
//        std:: cout << i << " " << random.getdigits()[i] << std::endl;
//    std::cout << std::endl;


//   char* egy = multiple_numbers("233", "3");
//   std::cout << egy;
//   delete[] egy;

    //std::cout << copy.getsize() << std::endl << copy.getbase() << std::endl << copy.getsign() << std::endl << copy.getdigits() << std::endl;

    return 0;
}