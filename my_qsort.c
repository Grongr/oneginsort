#include <time.h>
#include <stdlib.h>

#include "my_qsort.h"

/*!
 * @brief Swap func for array <arr>
 *
 * It swaps elements with indexes i and j of
 * array <arr>
 *
 * @param [in] <a>    ptr to the first elment to swap
 * @param [in] <b>    ptr to the second element to swap
 * @param [in] <size> sizeof a and b type
 *
 * @version 0.1
 */
void swap(void* a, void* b, size_t size);

void my_qsort(void* arr, int left, int right, size_t size,
              int (*cmp)(const void *, const void*)) {

    if (left >= right)
        return;

    int i, last;
    swap( (arr + left * size), (arr + (right + left) / 2 * size), size );
    last = left;
    for (i = left + 1; i <= right; ++i)
        if (cmp((arr + i * size), (arr + left * size)) < 0)
            swap( (arr + (++last) * size), (arr + i * size), size );

    swap( (arr + left * size), (arr + last * size), size );

    //       arr      left     right  tsize                               comparator
    my_qsort(arr,     left, last - 1,  size, (int(*) (const void*, const void*))cmp);
    my_qsort(arr, last + 1,    right,  size, (int(*) (const void*, const void*))cmp);

}

void swap(void* pa, void* pb, size_t size) {

    unsigned char tmp = 0;
    unsigned char* a = (unsigned char*)pa;
    unsigned char* b = (unsigned char*)pb;

    while (size--) {

        tmp = *a;
        *a++ = *b;
        *b++ = tmp;
    }
}
