#include <time.h>
#include <stdlib.h>

#include "my_qsort.h"

/*!
 * @brief Swap func for array <arr>
 *
 * It swaps elements with indexes i and j of
 * array <arr>
 *
 * @param [in] <arr> array of strings
 * @param [in] <i>   index of first swapping items
 * @param [in] <j>   index of the second item
 *
 * @version 0.1
 */
static void swap(string* arr, int i, int j);

void my_qsort(string* arr, int left, int right,
              int (*cmp)(const string *, const string *)) {

    if (left >= right)
        return;

    int i, last;
    swap(arr, left, (right + left) / 2);
    last = left;
    for (i = left + 1; i <= right; ++i)
        if (cmp((arr + i), (arr + left)) < 0)
            swap(arr, ++last, i);

    swap(arr, left, last);

    //       arr      left     right                                  comparator
    my_qsort(arr,     left, last - 1, (int(*) (const string*, const string*))cmp);
    my_qsort(arr, last + 1,    right, (int(*) (const string*, const string*))cmp);

}

static void swap(string* arr, int i, int j) {

    string temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
