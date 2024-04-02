//
// Created by punkostigyork on 2023.05.15..
//

#include <fstream>
#include <limits>
#include "menu.h"
#include "bignum.h"
#include "converter.h"
#include "fermat.h"
#include "gtest_lite.h"

void menu_add() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    char* a = readString();
    char* b = readString();
    BigNum A, B;
    numSysConv(a, A);
    numSysConv(b, B);
    BigNum C = A + B;
    char* c = bignum_to_string(C);
    std::cout << c << std::endl;
    TEST(c, 0);     ///ellenőrzi az eredményt
    delete[] a;
    delete[] b;
    delete[] c;
}

void menu_file_add() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::ifstream f("input.in");
    char* a = readStringFile(f);
    char* b = readStringFile(f);
    BigNum A, B;
    numSysConv(a, A);
    numSysConv(b, B);
    BigNum C = A + B;
    char* c = bignum_to_string(C);
    std::cout << c << std::endl;
    TEST(c, 1);     ///ellenőrzi az eredményt
    delete[] a;
    delete[] b;
    delete[] c;
}

void menu_sub() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    char* a = readString();
    char* b = readString();
    BigNum A, B;
    numSysConv(a, A);
    numSysConv(b, B);
    BigNum C = A - B;
    char* c = bignum_to_string(C);
    std::cout << c << std::endl;
    TEST(c, 2);     ///ellenőrzi az eredményt
    delete[] a;
    delete[] b;
    delete[] c;
}

void menu_file_sub() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::ifstream f("input.in");
    char* a = readStringFile(f);
    char* b = readStringFile(f);
    BigNum A, B;
    numSysConv(a, A);
    numSysConv(b, B);
    BigNum C = A - B;
    char* c = bignum_to_string(C);
    std::cout << c << std::endl;
    TEST(c, 3);     ///ellenőrzi az eredményt
    delete[] a;
    delete[] b;
    delete[] c;
}

void menu_mul() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    char* a = readString();
    char* b = readString();
    BigNum A, B;
    numSysConv(a, A);
    numSysConv(b, B);
    BigNum C = A * B;
    char* c = bignum_to_string(C);
    std::cout << c << std::endl;
    TEST(c, 4);     ///ellenőrzi az eredményt
    delete[] a;
    delete[] b;
    delete[] c;
}

void menu_file_mul() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::ifstream f("input.in");
    char* a = readStringFile(f);
    char* b = readStringFile(f);
    BigNum A, B;
    numSysConv(a, A);
    numSysConv(b, B);
    BigNum C = A * B;
    char* c = bignum_to_string(C);
    std::cout << c << std::endl;
    TEST(c, 5);     ///ellenőrzi az eredményt
    delete[] a;
    delete[] b;
    delete[] c;
}

void menu_div() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    char* a = readString();
    char* b = readString();
    BigNum A, B;
    numSysConv(a, A);
    numSysConv(b, B);
    BigNum C = A / B;
    char* c = bignum_to_string(C);
    std::cout << c << std::endl;
    TEST(c, 6);     ///ellenőrzi az eredményt
    delete[] a;
    delete[] b;
    delete[] c;
}

void menu_file_div() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::ifstream f("input.in");
    char* a = readStringFile(f);
    char* b = readStringFile(f);
    BigNum A, B;
    numSysConv(a, A);
    numSysConv(b, B);
    BigNum C = A / B;
    char* c = bignum_to_string(C);
    std::cout << c << std::endl;
    TEST(c, 7);     ///ellenőrzi az eredményt
    delete[] a;
    delete[] b;
    delete[] c;
}

void menu_fermat() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    char* a = readString();
    std::cout << a << std::endl;
    BigNum A;
    numSysConv(a, A);
    if(bool flag = fermat_prime(A, 100)) {
        std::cout << "PRIME" << std::endl;
        TEST_PRIME(flag, 0);     ///ellenőrzi az eredményt
    } else {
        std::cout << "NOT PRIME" << std::endl;
        TEST_PRIME(flag, 0);     ///ellenőrzi az eredményt
    }
    delete[] a;
}

void menu_file_fermat() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::ifstream f("input_prime.in");
    size_t n = 0;
    f >> n;
    if(n == 0)
        throw std::runtime_error("ERROR: EMPTY FILE");
    char* str;
    for(size_t i = 0; i < n; i++) {
        str = readStringFile(f);
        std::cout << std::endl << str << "  " << std::endl;
        BigNum A;
        numSysConv(str, A);
        if(bool flag = fermat_prime(A, 100)) {
            std::cout << "PRIME" << std::endl;
            TEST_PRIME(flag, i + 1);     ///ellenőrzi az eredményt
        } else {
            std::cout << "NOT PRIME" << std::endl;
            TEST_PRIME(flag, i + 1);     ///ellenőrzi az eredményt
        }
        delete[] str;
    }
}