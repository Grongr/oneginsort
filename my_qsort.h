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
 * @param [in]  <size>  sizeof array types
 * @param [in]  <cmp>   comparator for elements in arr
 *
 * @version 0.1
 */
void my_qsort(void* arr, int left, int right, size_t size,
              int (*cmp)(const void*, const void*));

#endif // MYQSORT_INCLUDED
