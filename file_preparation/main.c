#include <stdio.h>
#include <stdlib.h>

#include "../textio.h"

#define MAX_PATH 100

#define CODE_CHECK(FUNC, GOOD_CODE)         \
{                                           \
    FileLog code = FUNC;                    \
    if (code != GOOD_CODE) return code;     \
}

int main(void) {
    
    char inout_file[MAX_PATH] = "../input.txt";
    char out[MAX_PATH]        = "../output.txt";

    char* buffer;

    CODE_CHECK(input(&buffer, inout_file), FILE_OK);

    CODE_CHECK(file_preparation(buffer), FILE_OK);

    CODE_CHECK(preparation_write(buffer, out), FILE_OK);

    free(buffer);
    return 0;
}
