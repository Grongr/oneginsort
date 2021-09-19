#ifndef COMPARATORS_INCLUDED
#define COMPARATORS_INCLUDED

#include "textio.h"

const char* ignore = ",.\"\'?!:;";

/* @brief Func to compare the strings
 *
 * Compares strings in direct way, ignoring the
 * symbols from <ignore> param that inits in
 * .c file
 *
 * @param [in] <s1> First string to compare
 * @param [in] <s2> Secong string to compare
 *
 * @return 1 if s1 is bigger, 0 if equal and -1
 *         if <s1> is less
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
 * @return 1 if s1 is bigger, 0 if equal and -1
 *         if <s1> is less
 *
 * @version 0.1
 */
int reversed_cmp(const string* s1, const string s2);

#endif // COMPARATORS_INCLUDED
