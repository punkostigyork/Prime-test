#include "bignum.h"
#include <iostream>

#define Pr(a) std::cout << a << std::endl;

//inline függvények

inline size_t max(size_t a, size_t b) { return a > b ? a : b; }

///a BigNum osztály tagfüggvényei

BigNum::BigNum(size_t p1, const unsigned long long p2, const int p3, const unsigned long long* p4) : siz(p1), base(p2), sign(p3) {
    digits = new unsigned long long[siz];
    for(size_t i = 0; i < siz; i++)
        digits[i] = p4[i];
    //Pr("PARAMÉTERES KONSTRUKTOR: MEGSZÜLETTEM!");
}

BigNum::BigNum(BigNum& other) {
    siz = other.siz;
    base = other.base;
    sign = other.sign;
    digits = new unsigned long long[siz];
    for(size_t i = 0; i < siz; i++)
        digits[i] = other.digits[i];
    //Pr("KOPIKONSTRUKTOR MEGSZÜLETTEM!");
}

size_t BigNum::getsize() const {
    return siz;
}

void BigNum::setsize(size_t size) {
    siz = size;
    unsigned long long* temp = new unsigned long long[siz];
    for(size_t i = 0; i < siz; i++)
        temp[i] = digits[i];
    delete[] digits;
    digits = temp;
}

unsigned long long BigNum::getbase() const {
    return base;
}

int BigNum::getsign() const {
    return sign;
}

void BigNum::setsign(int p) {
    sign = p;
}

unsigned long long* BigNum::getdigits() const {
    return digits;
}

void BigNum::setdigits(unsigned long long *dig) {
    digits = dig;
}

void BigNum::setdigiti(unsigned long long dig, size_t index) {
    digits[index] = dig;
}

BigNum& BigNum::operator=(BigNum &rhs) {
    if(this != &rhs) {
        this->siz = rhs.getsize();
        this->base = rhs.getbase();
        this->sign = rhs.getsign();
        delete[] this->digits;
        this->digits = new unsigned long long[this->getsize()];
        for(size_t i = 0; i < this->getsize(); i++)
            this->digits[i] = rhs.getdigits()[i];
    }
    //Pr("ÉRTÉKADÓ OPERÁTOR: FELVETTEM AZ ÉRTÉKET!");
    return *this;
}

BigNum& BigNum::operator+(BigNum &rhs) {
    BigNum help = *this;
    this->siz = max(help.getsize(), rhs.getsize());
    delete[] this->digits;
    unsigned long long tmp1, tmp2, tmp = 0;
    this->digits = new unsigned long long[this->getsize()];
    for(size_t i = 0; i < this->getsize(); i++) {
        if(i >= help.getsize())
            tmp1 = 0;
        else
            tmp1 = help.getdigits()[i];

        if(i >= rhs.getsize())
            tmp2 = 0;
        else
            tmp2 = rhs.getdigits()[i];

        tmp = tmp + tmp1 + tmp2;
        this->digits[i] = tmp % this->getbase();
        tmp = tmp / this->getbase();
    }

    if(tmp != 0) {
        help = *this;
        delete[] this->digits;
        this->siz = this->getsize() + 1;
        this->digits = new unsigned long long[this->getsize()];
        for(size_t i = 0; i < this->getsize() - 1; i++)
            this->digits[i] = help.getdigits()[i];
        this->digits[this->getsize() - 1] = tmp;
    }
    //Pr("ÖSSZEADÓDTUNK!");
    return *this;
}

BigNum& BigNum::operator-(BigNum &rhs) {
    BigNum tmp1, tmp2;
    BigNum dif;

    if(this->siz < rhs.siz) {
        tmp1 = rhs;
        tmp2 = *this;
        dif.sign = -1;
    } else if(this->siz == rhs.siz) {
        size_t i = this->siz;
        while (this->digits[i] == rhs.digits[i])
            i--;
        if (this->digits[i] > rhs.digits[i]) {
            tmp1 = *this;
            tmp2 = rhs;
            dif.sign = 1;
        } else {
            tmp1 = rhs;
            tmp2 = *this;
            dif.sign = -1;
        }
    } else {
        tmp1 = *this;
        tmp2 = rhs;
        dif.sign = 1;
    }

    size_t mx = max(this->siz, rhs.siz);
    dif.siz = mx;

    delete[] dif.digits;
    dif.digits = new unsigned long long[mx];

    long long int *help = new long long int[mx];

    long long int temp1, temp2, temp, car = 0;

    for(size_t i = 0; i < mx; i++) {
        if(i >= this->siz)
            temp1 = 0;
        else
            temp1 = (long long int)this->digits[i];

        temp1 -= car;

        if(i >= rhs.siz)
            temp2 = 0;
        else
            temp2 = (long long int)rhs.digits[i];

        if(temp2 > temp1)
            car = 1;
        else
            car = 0;

        temp = car * dif.base + temp1 - temp2;
        help[i] = temp;
    }

    for(size_t i = 0; i < mx; i++)
        dif.digits[i] = help[i];

    delete[] help;

    remove_0s(dif);
    *this = dif;
    return *this;
}

bool BigNum::remove_0s(BigNum& num) {
    size_t index = num.siz - 1, nr = 0;
    while(num.digits[index] == 0 and num.siz - nr > 1) {
        nr++;
        index--;
    }
    if(nr == 0)
        return false;

    size_t newsize = index + 1;
    unsigned long long *NEW = new unsigned long long[newsize];
    if(NEW == nullptr)
        return false;
    for(size_t i = 0; i < newsize; i++)
        NEW[i] = num.getdigits()[i];
    delete[] num.digits;
    num.digits = NEW;
    num.siz = newsize;
    return true;
}

BigNum &BigNum::operator*(BigNum &rhs) {
    BigNum prod;
    prod.sign = this->sign * rhs.sign;
    prod.base = this->base;

    BigNum tmp1 = *this, tmp2 = rhs;

    prod.siz = tmp1.siz + tmp2.siz;
    delete[] prod.digits;
    prod.digits = new unsigned long long[prod.siz + 1];
    for(size_t i = 0; i < prod.siz + 1; i++)
        prod.digits[i] = 0;

    unsigned long long **temp = new unsigned long long*[tmp2.siz];

    for(size_t i = 0; i < tmp2.siz; i++)
        temp[i] = new unsigned long long[prod.siz];

    for(size_t i = 0; i < tmp2.siz; i++)
        for(size_t j = 0; j < prod.siz; j++)
            temp[i][j] = 0;

    for(size_t i = 0; i < tmp2.siz; i++) {
        for(size_t j = i; j < i + tmp1.siz; j++) {
            unsigned long long res = temp[i][j] + tmp1.digits[j - i] * tmp2.digits[i];
            temp[i][j] = res % prod.base;
            temp[i][j + 1] = res / prod.base;
        }
    }

    for(size_t j = 0; j < prod.siz; j++) {
        unsigned long long help, res = 0, car = 0;

        for(size_t i = 0; i < tmp2.siz; i++) {
            help = res + temp[i][j];
            res = help % prod.base;
            car += help / prod.base;
        }

        help = prod.digits[j] + res;
        res = help % prod.base;
        car += help / prod.base;

        prod.digits[j] = res;
        prod.digits[j + 1] = car;
    }

    remove_0s(prod);

    for(size_t i = 0; i < tmp2.siz; i++)
        delete[] temp[i];
    delete[] temp;
    *this = prod;
    return *this;
}

BigNum& BigNum::operator/(BigNum& rhs) {
    unsigned long long one1[] = {1}, nul[] = {0};
    BigNum low(1, this->base, 0, nul);
    BigNum one(1, this->base, 1, one1);
    BigNum high = *this;

    if(rhs == one)
        return *this;

    BigNum lowcpy = low;
    BigNum mid = (low + high) / 2;
    low = lowcpy;

    BigNum midcpy = mid;
    BigNum help1 = mid * rhs;
    mid = midcpy;

    midcpy = mid;
    BigNum help2 = mid + one;
    mid = midcpy;

    BigNum help2cpy = help2;
    BigNum help3 = help2 * rhs;
    help2 = help2cpy;

    unsigned int cond1 = (help1 <= *this);
    unsigned int cond2 = (*this < help3);
    unsigned int condition = (cond1 & cond2);

    while(!condition) {
        unsigned int ifcond = (help1 < *this);
        if(ifcond)
            low = mid;
        else
            high = mid;

        lowcpy = low;
        mid = (low + high) / 2;
        low = lowcpy;

        midcpy = mid;
        help1 = mid * rhs;
        mid = midcpy;

        midcpy = mid;
        help2 = mid + one;
        mid = midcpy;

        help2cpy = help2;
        help3 = help2 * rhs;
        help2 = help2cpy;

        cond1 = (help1 <= *this);
        cond2 = (*this < help3);
        condition = (cond1 & cond2);
    }
    *this = mid;
    return *this;
}

BigNum& BigNum::operator/(int rhs) {
    BigNum res;
    res.base = this->base;
    res.sign = this->sign;
    delete[] res.digits;
    res.digits = new unsigned long long[this->siz];

    unsigned long long temp = 0;

    for(int i = (int)this->siz - 1; i >= 0; i--) {
        temp = temp * res.base + this->digits[i];
        res.digits[res.siz] = temp / rhs;
        res.siz++;
        temp = temp % rhs;
    }

    for(size_t i = 0; i < res.siz / 2; i++) {
        temp = res.digits[i];
        res.digits[i] = res.digits[res.siz - 1 - i];
        res.digits[res.siz - 1 - i] = temp;
    }

    remove_0s(res);
    *this = res;
    return *this;
}

BigNum& BigNum::operator%(BigNum& rhs) {
    BigNum tmp1 = *this;
    BigNum tmp2 = tmp1 / rhs;
    BigNum help1 = tmp2 * rhs;
    BigNum help2 = *this;
    BigNum help3 = help2 - help1;
    *this = help3;
    return *this;
}

bool BigNum::operator==(BigNum& rhs) {
    if(this->siz == 1 and rhs.siz == 1 and this->digits[0] == 0 and rhs.digits[0] == 0)
        return true;
    if(this->siz != rhs.siz)
        return false;
    for(size_t i = 0; i < this->siz; i++)
        if(this->digits[i] != rhs.digits[i])
            return false;
    return true;
}

bool BigNum::operator!=(BigNum& rhs) {
    return !(*this == rhs);
}

bool BigNum::operator<(BigNum& rhs) {
    BigNum help = *this;
    BigNum tmp = help - rhs;
    if(tmp.sign == -1)
        return true;
    return false;
}

bool BigNum::operator>(BigNum& rhs) {
    return !(*this <= rhs);
}

bool BigNum::operator<=(BigNum& rhs) {
    BigNum help = *this;
    if(*this == rhs)
        return true;
    BigNum tmp = help - rhs;
    if(tmp.sign == -1)
        return true;
    else
        return false;
}

bool BigNum::operator>=(BigNum& rhs) {
    return !(*this < rhs);
}

BigNum::~BigNum() {
    delete[] digits;
    //Pr("ITT A VÉGE FUSS EL VÉLE!");
}









