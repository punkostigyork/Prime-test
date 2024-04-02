/**@file bignum.h
 * @brief A BigNum osztályt határozza meg
 * @author Pünkösti Györk
 */

#ifndef HAZI_BIGNUM_H
#define HAZI_BIGNUM_H

#include <iostream>
#include "memtrace.h"

class BigNum {
    size_t siz;                     ///a bignum számjegyeinek a száma
    unsigned long long base;        ///a számrendszer
    int sign;                       ///a szám előjele
    unsigned long long *digits;     ///a számjegyek tömjére mutató tömb
public:
    /**PARAMÉTERES KONSTRUKTOR
     * @brief default módban siz = 0, base = 10, sign = 0, p4 = nullptr
     *
     * @param p1 - a számjegyek száma
     * @param p2 - a felhasznált számrendszer
     * @param p3 - a szám előjele
     * @param p4 - a számjegyek tömbjére mutató pointer
     */
    BigNum(size_t p1 = 0,  const unsigned long long p2 = 10, const int p3 = 0, const unsigned long long* p4 = nullptr);

    /**KOPIKONSTRUKTOR
     *
     * @param other - a lemásolni kívánt objektum
     */
    BigNum(BigNum& other);

    /**@brief visszatéríti a számjegyek számát
     *
     * @return pozitív egész
     */
    size_t getsize() const;

    /**@brief beállítja a méretet
     *
     * @param size - mekkorára állítsa be
     */
    void setsize(size_t size);

    /**@brief visszatéríti a számrendszer alapját
     *
     * @return pozitív egész
     */
    unsigned long long getbase() const;

    /**@brief visszatéríti a szám előjelét
     *
     * @return -1 v 0 v 1 érték
     */
    int getsign() const;

    /**@brief beállítja a szám előjelét
     *
     * @param p - az előjel értéke
     */
    void setsign(int p);

    /**@brief visszatéríti a számjegyek tömbjére mutató pointer értékét
     *
     * @return a digitsre mutató pointer
     */
    unsigned long long* getdigits() const;

    /**@brief beállítja a számjegyek tömbjét
     *
     * @param dig - beállítandó tömb
     */
    void setdigits(unsigned long long* dig);

    /**@brief adott értékre állít be egy számjegyet
     *
     * @param dig - számjegy
     * @param index - sorszám
     */
    void setdigiti(unsigned long long dig, size_t index);

    /**ÉRTÉKADÓ OPERÁTOR
     *
     * @param rhs - paraméterként átadott szám
     * @return bignum, rhs másolata
     */
    BigNum& operator=(BigNum& rhs);

    /**ÖSSZEADÓ OPERÁTOR
     *
     * @param rhs - hozzáadja a baloldali értékhez
     * @return BigNum, a összeg
     */
    BigNum& operator+(BigNum& rhs);

    /**KIVONÓ
     *
     * @param rhs - kivonja a baloldali értéket
     * @return BigNum, a különbség
     */
    BigNum& operator-(BigNum& rhs);

    /**SZORZÓ OPERÁTOR
     *
     * @param rhs - a jobboldali érték amivel szorozzul a baloldalit
     * @return - BigNum, szorzat
     */
    BigNum& operator*(BigNum& rhs);

    /**OSZTÓ OPERÁTOR
     *
     * @param rhs - a baloldali érték amivel osszuk a baloldali számot
     * @return - BigNum, hányados
     */
    BigNum& operator/(BigNum& rhs);

    /**OSZTÁS EGÉSZ SZÁMMAL
     *
     * @param rhs - osztó egész szám
     * @return - BigNum, hányados
     */
    BigNum& operator/(int rhs);

    /**MARADÉK OPERÁTOR
     *
     * @param rhs - jobboldali szám amivel osztva keressük a maradékot
     * @return - BigNum, maradék
     */
    BigNum& operator%(BigNum& rhs);

    /**EGYENLŐSÉG OPERÁTOR
     *
     * @param rhs - jobboldali érték, amit ellenőrzünk
     * @return - true/false
     */
    bool operator==(BigNum& rhs);

    /**EGYENLŐTLENSÉG OPERÁTOR
     *
     * @param rhs - jobboldali érték, amit ellenörzünk
     * @return - true/false
     */
    bool operator!=(BigNum& rhs);

    /**KISEBB OPERÁTOR
     *
     * @param rhs - jobboldali érték, amit ellenörzünk
     * @return - true/false
     */
    bool operator<(BigNum& rhs);

    /**NAGYOBB OPERÁTOR
     *
     * @param rhs - jobboldali érték, amit ellenörzünk
     * @return - true/false
     */
    bool operator>(BigNum& rhs);

    /**KISEBB-EGYENLŐ OPERÁTOR
     *
     * @param rhs - jobboldali érték, amit ellenörzünk
     * @return - true/false
     */
    bool operator<=(BigNum& rhs);

    /**NAGYOBB-EGYENLŐ OPERÁTOR
     *
     * @param rhs - jobboldali érték, amit ellenörzünk
     * @return - true/false
     */
    bool operator>=(BigNum& rhs);

    /**NULLSZÁMJEGYTÖRLŐ
     *
     * @param num - helytelen nagyszám
     * @return - helyes nagyszám
     */
    static bool remove_0s(BigNum& num);

    /**DESTRUKTOR
     *
     */
    ~BigNum();
};


#endif //HAZI_BIGNUM_H
