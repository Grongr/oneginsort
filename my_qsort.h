#ifndef MYQSORT_INCLUDED
#define MYQSORT_INCLUDED

#include "textio.h"

/*!
 * @brief Qsort
 *
 * Sorts depends on which func <cmp> gets
 *
 * @param [in]  <arr>   array to be sorted
 * @param [in]  <left>  left edge of sorting
 * @param [in]  <right> right edge of sorting
 * @param [in]  <cmp>   comparator for elements in arr
 *
 * @version 0.1
 */
void my_qsort(string* arr, int left, int right,
              int (*cmp)(const string*, const string*));

#endif // MYQSORT_INCLUDED
