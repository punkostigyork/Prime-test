//
// Created by punkostigyork on 2023.05.15..
//

#include <iostream>
#include <cstring>
#include "converter.h"

char *readString() {
    int size = 0;
    char* str = new char[1];
    str[0] = '\0';
    char newchar;

    while (std::cin.get(newchar) && newchar != '\n') {
        char* newstr = new char[size + 1 + 1];
        strcpy(newstr, str);
        newstr[size] = newchar;
        newstr[size + 1] = '\0';

        delete[] str;
        str = newstr;

        size++;
    }

    return str;

}

char* readStringFile(std::ifstream& op) {
    int size = 0;
    char* str = new char[1];
    str[0] = '\0';
    char newchar;

    op.get(newchar);
    if(newchar == '\n')
        op.get(newchar);
    if (!op.good()) {
        delete[] str;
        throw std::runtime_error("ERROR: EMPTY FILE");
    }

    while (newchar != '\n') {
        char* newstr = new char[size + 1 + 1];
        strcpy(newstr, str);
        delete[] str;
        str = newstr;
        newstr[size] = newchar;
        newstr[size + 1] = '\0';
        size++;

        if (!op.get(newchar)) {
            break;
        }
    }

    if (size == 0) {
        delete[] str;
        throw std::runtime_error("ERROR: EMPTY FILE");
    }

    return str;
}

char* buildRatio(char* ratio, int newDigit, int nrDigRat) {
    char* newRat = new char[nrDigRat + 1 + 1];
    strcpy(newRat, ratio);
    delete[] ratio;
    ratio = newRat;
    newRat[nrDigRat] = (char) (newDigit + '0');
    newRat[nrDigRat + 1] = '\0';
    return ratio;
}

unsigned long long* gainDigits(unsigned long long* digits, size_t newSize, unsigned long long newDigit) {
    unsigned long long* nw = new unsigned long long[newSize];
    for(size_t i = 0; i < newSize; i++)
        nw[i] = digits[i];
    delete[] digits;
    digits = nw;
    nw[newSize - 1] = newDigit;
    return digits;
}

void numSysConv(char const* number, BigNum& bignumber) {
    unsigned long long temp = 0, nrDigRat = 0;
    char *ratio = new char[1];
    ratio[0] = '\0';

    for(size_t i = 0; number[i] != '\0'; i++) {
        temp = temp * 10 + (number[i] - '0');
        if(temp >= bignumber.getbase()) {
            unsigned long long digit = temp / bignumber.getbase();
            ratio = buildRatio(ratio, digit, nrDigRat);
            nrDigRat++;
            temp = temp - digit * bignumber.getbase();
        } else if(nrDigRat != 0) {
            ratio = buildRatio(ratio, 0, nrDigRat);
            nrDigRat++;
        }
    }
    bignumber.setsize(bignumber.getsize() + 1);
    bignumber.setdigits(gainDigits(bignumber.getdigits(), bignumber.getsize(), temp));
    if(ratio[0] != '\0')
        numSysConv(ratio, bignumber);
    delete[] ratio;
}

char* num_to_string(const unsigned long long n) {
    unsigned long long cpy1 = n, cpy2 = n;
    size_t size = 0;
    char* num;
    while(cpy1 > 0) {
        size++;
        cpy1 /= 10;
    }
    num = new char[size + 1];
    if(num == nullptr)
        return nullptr;
    for(size_t i = 0; i < size; i++) {
        unsigned long long temp = cpy2 % 10;
        num[i] = (char) (temp + '0');
        cpy2 /= 10;
    }
    num[size] = '\0';
    change_backwards(num);
    return num;
}

void change_backwards(char* str) {
    size_t size = strlen(str);
    for(size_t i = 0; i < size / 2; i++) {
        char tmp2 = str[i];
        str[i] = str[size - i - 1];
        str[size - i - 1] = tmp2;
    }
}

char* shift_right(char *p_one, const unsigned long long p_two) {
    size_t size = strlen(p_one);
    char *tmp = new char[size + p_two + 1];
    if(tmp == nullptr)
        return nullptr;
    for(size_t i = 0; i < size + p_two; i++) {
        if (i >= size)
            tmp[i] = '0';
        else
            tmp[i] = p_one[i];
    }
    tmp[size + p_two] = '\0';
    return tmp;
}

char* multiple_digits(char* p_one, unsigned long long digit) {
    unsigned long long car = 0;
    size_t size = strlen(p_one);
    char* tmp1 = new char[size + 1 + 1];
    char *p_one_cpy = new char[size + 1];

    if(tmp1 == nullptr or p_one_cpy == nullptr)
        return nullptr;

    strcpy(p_one_cpy, p_one);
    change_backwards(p_one_cpy);

    for(size_t i = 0; i < size; i++) {
        unsigned long long tmp2 = (p_one_cpy[i] - '0') * digit + car;
        tmp1[i] = (char) (tmp2 % 10 + '0');
        car = tmp2 / 10;
    }

    if(car == 0)
        tmp1[size] = '\0';
    else {
        tmp1[size] = (char) (car + '0');
        tmp1[size + 1] = '\0';
    }

    delete[] p_one_cpy; ///////////////////////////////////////lehet hiba[]
    change_backwards(tmp1);
    return tmp1;
}

char* add_numbers(char* p_one, char* p_two) {
    size_t size_one = strlen(p_one);
    size_t size_two = strlen(p_two);
    size_t max = size_one > size_two ? size_one : size_two;

    char* p_one_cpy = new char[size_one + 1];
    char* p_two_cpy = new char[size_two + 1];
    char* sum = new char[max + 1 + 1];

    if(p_one_cpy == nullptr or p_two_cpy == nullptr or sum == nullptr)
        return nullptr;

    strcpy(p_one_cpy, p_one);
    strcpy(p_two_cpy, p_two);

    change_backwards(p_one_cpy);
    change_backwards(p_two_cpy);

    unsigned long long tmp1, tmp2, car = 0;
    for(size_t i = 0; i < max; i++) {
        if(i >= size_one)
            tmp1 = 0;
        else
            tmp1 = p_one_cpy[i] - '0';

        if(i >= size_two)
            tmp2 = 0;
        else tmp2 = p_two_cpy[i] - '0';

        unsigned long long tmp3 = tmp1 + tmp2 + car;
        sum[i] = (char) (tmp3 % 10 + '0');
        car = tmp3 / 10;
    }

    if(car == 0)
        sum[max] = '\0';
    else {
        sum[max] = (char) (car + '0');
        sum[max + 1] = '\0';
    }

    delete[] p_one_cpy;
    delete[] p_two_cpy;

    change_backwards(sum);
    return sum;
}

char* multiple_numbers(char* p_one, char* p_two) {
    size_t size_one = strlen(p_one);
    size_t size_two = strlen(p_two);
    size_t size = size_one + size_two;;

    char* p_one_cpy = new char[size_one + 1];
    char* p_two_cpy = new char[size_two + 1];
    char* prod = new char[size_one + 1];

    if(prod == nullptr or p_one_cpy == nullptr or p_two_cpy == nullptr)
        return nullptr;

    strcpy(p_one_cpy, p_one);
    strcpy(p_two_cpy,p_two);

    for(size_t i = 0; i < size_one; i++)
        prod[i] = '0';

    prod[size_one] = '\0';

    change_backwards(p_two_cpy);

    for(size_t i = 0; i < size_two; i++) {
        char *tmp1 = multiple_digits(p_one_cpy, (p_two_cpy[i] - '0'));
        char *help = new char[size + 1 + 1];

        if (help == nullptr)
            return nullptr;

        strcpy(help, tmp1);
        delete[] tmp1;
        tmp1 = shift_right(help, i);
        delete[] help;
        help = new char[size + 1 + 1];

        if (help == nullptr)
            return nullptr;

        strcpy(help, prod);
        delete[] prod;
        prod = add_numbers(help, tmp1);
        delete[] help;
        delete[] tmp1;
    }
    delete[] p_one_cpy;
    delete[] p_two_cpy;
    return prod;
}

char* bignum_to_string(BigNum& p) {
    char* res = new char[2];
    char* base = num_to_string(p.getbase());
    char* pow = new char[2];

    if(res == nullptr or base == nullptr or pow == nullptr)
        return nullptr;

    res[0] = '0';
    res[1] = '\0';
    pow[0] = '1';
    pow[1] = '\0';

    for(size_t i = 0; i < p.getsize(); i++) {
        char* tmp1 = num_to_string(p.getdigits()[i]);
        char* tmp2 = new char[strlen(res) + 1];

        if(tmp1 == nullptr or tmp2 == nullptr)
            return nullptr;

        strcpy(tmp2, res);
        delete[] res;

        char* tmp3 = multiple_numbers(tmp1, pow);
        res = add_numbers(tmp2, tmp3);
        delete[] tmp2;
        delete[] tmp3;

        char* help = new char[strlen(pow) + 1];

        if(help == nullptr)
            return nullptr;

        strcpy(help, pow);
        delete[] pow;
        pow = multiple_numbers(help, base);
        delete[] help;
        delete[] tmp1;
    }
    delete[] pow;
    delete[] base;
    return res;
}