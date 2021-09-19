#ifndef MYQSORT_INCLUDED
#define MYQSORT_INCLUDED

#include "textio.h"

/*!
 * @brief Qsort
 *
 * Sorts depends on which func <cmp> gets
 *
 * @param [in]  <arr>   array to be sorted
 * @param [in]  <count> count of elements in array
 * @param [in]  <cmp>   comparator for elements in arr
 */
void my_qsort(string* arr, int count, int (*cmp)(const void*, const void*));

#endif // MYQSORT_INCLUDED
