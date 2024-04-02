//
// Created by punkostigyork on 2023.05.15..
//

#include "fermat.h"
#include "converter.h"
#include <iostream>
#include <ctime>

void fermat_power(BigNum& p_one, BigNum& p_two, BigNum& p_three, BigNum& res) {
    unsigned long long ONE[] = {1};
    BigNum one(1, 10, 1, ONE);
    res = one;
    BigNum help = p_one % p_three;
    p_one = help;

    unsigned long long ZERO[] = {0}, TWO[] = {2};
    BigNum zero(1, 10, 0, ZERO);
    BigNum two(1, 10, 1, TWO);

    while(zero != p_two) {
        BigNum p_twocpy = p_two;
        BigNum cond = p_two % two;
        p_two = p_twocpy;

        if(cond == one) {
            BigNum help = res * p_one;
            res = help % p_three;
        }

        BigNum help2 = p_two / 2;
        p_two = help2;
        BigNum help3 = p_one * p_one;
        BigNum help4 = help3 % p_three;
        p_one = help4;
    }
}

void fermat_GCD(BigNum& p_one, BigNum& p_two, BigNum& gcd) {
    if(p_one < p_two) {
        BigNum help1 = p_one;
        p_one = p_two;
        p_two = help1;
    }

    BigNum a = p_one;
    BigNum b = p_two;

    unsigned long long NUL[] = {0};
    BigNum nul(1, 10, 1, NUL);

    BigNum p_one_cpy = p_one;
    BigNum tmp = p_one % p_two;
    p_one = p_one_cpy;

    while(tmp != nul) {
        a = b;
        b = tmp;
        BigNum acpy = a;
        tmp = a % b;
        a = acpy;
    }

    gcd = b;
}

void fermat_random(BigNum& p, BigNum& random) {
    unsigned long long TWO[] = {2}, FOUR[] = {4};
    BigNum two(1, 10, 1, TWO), four(1, 10, 1, FOUR);
    srand(time(0));
    unsigned long long number = rand();
    unsigned long long tmp = number;
    size_t nr = 0;
    while(tmp > 0) {
        nr++;
        tmp /= 10;
    }
    char* num = new char[nr + 1];
    for(size_t i = 0; i < nr; i++) {
        num[nr - i - 1] = (char) (number % 10 + '0');
        number = number / 10;
    }
    num[nr] = '\0';

    BigNum help;
    numSysConv(num, help);
    BigNum help2 = p - four;
    BigNum help3 = help % help2;
    random = two + help3;

    delete[] num;
}

bool fermat_prime(BigNum& p, unsigned int limit) {
    unsigned long long ONE[] = {1}, TWO[] = {2}, THREE[] = {3}, FOUR[] = {4};
    BigNum one(1, 10, 1, ONE);
    BigNum two(1, 10, 1, TWO);
    BigNum three(1, 10, 1, THREE);
    BigNum four(1, 10, 1, FOUR);

    if(p <= one or p == four)
        return false;
    if(p <= three)
        return true;

    while(limit > 0) {
        BigNum ran;
        BigNum pcpy = p;
        fermat_random(p, ran);
        p = pcpy;
        BigNum twocpy = two;
        BigNum p_one = two + ran;
        two = twocpy;

        BigNum cond1;
        fermat_GCD(p, p_one, cond1);
        if(cond1 != one)
            return false;

        pcpy = p;
        BigNum p_two = p - one;
        p = pcpy;

        BigNum cond2;
        fermat_power(p_one, p_two, p, cond2);

        if(cond2 != one)
            return false;

        limit--;
    }
    return true;
}