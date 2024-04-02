/**@file fermat.h
 * @brief A Fermat-teszt függvényeit tartalmazza
 * @author Pünkösti Györk
 */

#ifndef HAZI_FERMAT_H
#define HAZI_FERMAT_H

#include "bignum.h"

/**FERMAT-TESZT HATVÁNYOZÓ
 *
 * @param p_one - első szám
 * @param p_two - második szám
 * @param p_three - harmadik szám
 * @return - BigNum, hatvány
 */
BigNum& fermat_power(BigNum& p_one, BigNum& p_two, BigNum& p_three);

/**FERMAT-TESZT LKO KERESŐ
 *
 * @param p_one - első szám
 * @param p_two - második szám
 * @return - LKO
 */
void fermat_GCD(BigNum& p_one, BigNum& p_two, BigNum& gcd);

/**RANDOM NAGYSZÁM GENERÁTOR
 *
 * @param p - felső határ
 * @return - BigNum, random szám
 */
void fermat_random(BigNum& p, BigNum& random);

/**PRÍMTESZT
 *
 * @param p - tesztelendő szám
 * @param limit - tesztesetek száma
 * @return - true/false
 */
bool fermat_prime(BigNum& p, unsigned int limit);

#endif //HAZI_FERMAT_H
