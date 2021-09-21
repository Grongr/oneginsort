#include <assert.h>
#include <string.h>
#include <ctype.h>

#include "comparators.h"

const char* ignore = ",.\"\'?!:;\t";

int forward_cmp(const string* s1, const string* s2) {

    assert(s1 != NULL);
    assert(s2 != NULL);

    char* p1 = s1->ptr;
    char* p2 = s2->ptr;

    do {

        p1 += strspn(p1, ignore);
        p2 += strspn(p2, ignore);

        if (*p1 == '\0')
            return 0;

        if (tolower(*p1) == tolower(*p2)) {

            ++p1;
            ++p2;
        }

    } while (tolower(*p1) == tolower(*p2) && 
             *p1 != '\0' && *p2 != '\0');

    return (*p1 - *p2);
}

int reversed_cmp(const string* s1, const string* s2) {

    assert(s1 != NULL);
    assert(s2 != NULL);

    string ss1 = *s1;
    string ss2 = *s2;

    ss1.ptr += ss1.length - 1;
    ss2.ptr += ss2.length - 1;

    do {
        while (strspn(ss1.ptr, ignore)) --ss1.ptr;
        while (strspn(ss2.ptr, ignore)) --ss2.ptr;

        if (*(ss1.ptr) == '\0')
            return 0;

        if (tolower(*(ss1.ptr)) == tolower(*(ss2.ptr))) {

            --ss1.ptr;
            --ss2.ptr;
        }

    } while (tolower(*(ss1.ptr)) == tolower(*(ss2.ptr)));

    return (*(ss1.ptr) - *(ss2.ptr));
}

int ptr_cmp(const void* pa, const void* pb) {

    const size_t p1 = (size_t) (((string*)pa)->ptr);
    const size_t p2 = (size_t) (((string*)pb)->ptr);

    return (p1 - p2);
}
