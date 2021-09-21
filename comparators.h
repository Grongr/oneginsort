#ifndef COMPARATORS_INCLUDED
#define COMPARATORS_INCLUDED

#include "textio.h"

/* @brief Func to compare the strings
 *
 * Compares strings in direct way, ignoring the
 * symbols from <ignore> param that inits in
 * .c file
 *
 * @param [in] <s1> First string to compare
 * @param [in] <s2> Secong string to compare
 *
 * @return bigger, equal or less zero if <s1> is bigger,
 *         equal or less then <s2>
 *
 * @version 0.1
 */
int forward_cmp(const string* s1, const string* s2);

/*!
 * @brief Func to compare strings
 *
 * Compares strings in reverst direction. Ignores
 * all the simbols from <ignore> string from .c file
 *
 * @param [in] <s1> First string to compare
 * @param [in] <s2> Secong string to compare
 * 
 * @return bigger, equal or less zero if <s1> is bigger,
 *         equal or less then <s2>
 *
 * @version 0.1
 */
int reversed_cmp(const string* s1, const string* s2);

/*!
 * @This func compares to int numbers
 *
 * @param [in] <pa> pointer to the first number to compare
 * @param [in] <pb> pointer to the second number to compare
 * 
 * @return bigger, equal or less zero if <pa> is bigger,
 *         equal or less then <pb>
 */
int ptr_cmp(const void* pa, const void* pb);

#endif // COMPARATORS_INCLUDED
