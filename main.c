#include <stdio.h>
#include <stdlib.h>

#include "textio.h"
#include "my_qsort.h"
#include "comparators.h"


#define CODE_CHECK(FUNC, GOOD_CODE)         \
{                                           \
    int code = FUNC;                        \
    if (code != GOOD_CODE) return code;     \
}

int main(void) {

    char* buffer;

    char* output_file = "./result/output.txt";
    char* input_file  = "./input/input.txt";

    /* CODE_CHECK(get_file_names(input_file, output_file), FILE_OK); */

    CODE_CHECK(clear(output_file), FILE_OK)

    CODE_CHECK(input(&buffer, input_file), FILE_OK);

    int* count = NULL;
    *count = 0;

    string* text = parser(buffer, count, '\n');

    CODE_CHECK(clear(output_file), FILE_OK);

    my_qsort(text, *count, (int(*) (const void*, const void*))forward_cmp);

    CODE_CHECK(write_result(text, output_file), FILE_OK);

    qsort(text, 0, *count, (int(*) (const void*, const void*))reversed_cmp);

    CODE_CHECK(write_result(text, output_file), FILE_OK);

    return 0;
}
