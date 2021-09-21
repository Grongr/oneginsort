#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "textio.h"
#include "my_qsort.h"
#include "comparators.h"

#define MAX_PATH 100

#define CODE_CHECK(FUNC, GOOD_CODE)         \
{                                           \
    FileLog code = FUNC;                    \
    if (code != GOOD_CODE) return code;     \
}

int main(void) {

    char* buffer;

    char output_file[MAX_PATH] = "../result/output.txt";
    char input_file[MAX_PATH]  = "../input/input.txt";

    /* CODE_CHECK(get_file_names(input_file, output_file), FILE_OK); */

    CODE_CHECK(input(&buffer, input_file), FILE_OK);

    size_t count = 0;

    string* text = parser(buffer, &count, '\n');

    CODE_CHECK(clear(output_file), FILE_OK);

    my_qsort(text, 0, count - 1,
            (int(*) (const string*, const string*))forward_cmp);

    CODE_CHECK(write_result(text, count, output_file), FILE_OK);

    qsort(text, count, sizeof(string),
         (int(*) (const void*, const void*))reversed_cmp);

    CODE_CHECK(write_result(text, count, output_file), FILE_OK);

    qsort(text, count, sizeof(string),
         (int(*) (const void*, const void*))ptr_cmp);

    CODE_CHECK(write_result(text, count, output_file), FILE_OK);

    free_text_buf(text, buffer);
    return 0;
}
