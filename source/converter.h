/**@file converter.h
 * @brief Az átalakító függvényeket tartalmazza
 * @author Pünkösti Györk
 */

#ifndef HAZI_CONVERTER_H
#define HAZI_CONVERTER_H

#include "bignum.h"

/**STRINGBEOLVASÓ
 *
 * @return - beolvasott stringre mutató pointer
 */
char *readString();

/**STRINGBEOLVASÓ FÁJLBÓL
 *
 * @param op - a fájl operátora
 * @return - a beolvasott string
 */
char* readStringFile(std::ifstream& op);

/**HÁNYADOSFELÉPÍTŐ
 *
 * @param ratio - hányados
 * @param newDigit - új számjegy
 * @param nrDigRat - számjegyek száma
 * @return - számjegyek tömbjére mutató pointer
 */

char *buildRatio(char *ratio, int newDigit, int nrDigRat);

/**SZÁMJEGYGYŰJTŐ
 *
 * @param digits - számjegyek tömbje
 * @param newSize - új méret
 * @param newDigit - új számjegy
 * @return - számjegyek új tömbje
 */
unsigned long long *gainDigits(unsigned long long *digits, size_t newSize, unsigned long long newDigit);

/**SZÁMRENDSZER ÁTVÁLTÓ
 *
 * @param number - a szám
 * @param bignumber - BigNum, a szám
 */
void numSysConv(char const *number, BigNum& bignumber);

/**STRINGKONVERTER
 *
 * @param n - átalakítandó egész szám
 * @return - stringre mutató pointer
 */
char *num_to_string(const unsigned long long n);

/**MEGFORDÍTÓ
 *
 * @param str - a megfordítandó string
 */
void change_backwards(char *str);

/**JOBBSHIFT
 *
 * @param p_one - shiftelendő string
 * @param p_two - mennyivel kell elshiftelni
 * @return - elshiftelt string
 */
char *shift_right(char *p_one, const unsigned long long p_two);

/**SZÁMJEGYSZORZÓ
 *
 * @param p_one - első szám számjegyei
 * @param digit - szorzó számjegy
 * @return - szorzatok stringje
 */
char *multiple_digits(char *p_one, unsigned long long digit);

/**SZÁMÖSSZEADÓ
 *
 * @param p_one - első szám
 * @param p_two - második szám
 * @return - számjegyek tömbje
 */
char *add_numbers(char *p_one, char *p_two);

/**SZÁMSZORZÓ
 *
 * @param p_one - első szám tömbje
 * @param p_two - második szám tömbje
 * @return - szorzat tömbje
 */
char *multiple_numbers(char *p_one, char *p_two);

/**NAGYSZÁMSTRINGKONVERTER
 *
 * @param p - átalakítandó szám
 * @return - átalakított szám stringje
 */
char *bignum_to_string(BigNum& p);

#endif //HAZI_CONVERTER_H
