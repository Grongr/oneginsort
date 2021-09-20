#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/io.h>

#include "textio.h"

FileLog input(char** buffer, const char *input_file) {

    assert(input_file != NULL);

    FILE* fin = fopen(input_file, "r");

    if (fin == NULL)
        return CANNOT_FIND_FILE;

    struct stat information;
    stat(input_file, &information);

    *buffer = (char*) calloc((size_t) information.st_size + 4ul, sizeof(char));
    if (*buffer == NULL)
        return NO_MEMORY;

    size_t size = fread(*buffer, sizeof(char), (size_t) information.st_size, fin);

    if (size < 0)
        return CANNOT_READ_FILE;

    *(*buffer + size + 1) = '\n';
    *(*buffer + size + 2) = '\0';

    fclose(fin);
    return FILE_OK;
}

string* parser(char* buffer, size_t* count, char ch) {

    assert(buffer != NULL);
    assert(count  != NULL);

    char* iter = buffer;
    *count = 0;

    while ( (iter = strchr(iter, ch)) != NULL ) {

        while (*iter == ch)
            ++iter;
        ++(*count);
    }

    string* text = (string*) calloc(*count, sizeof(string));

    if (text == NULL)
        return NULL;

    iter = buffer;
    char* last;
    size_t length;

    for (int i = 0; i < *count; ++i) {

        (text + i)->ptr = iter;
        last = iter;

        iter = strchr(iter, ch);
        length = (size_t) (iter - last);
        (text + i)->length = length;

        while (*iter == ch) ++iter;
    }

    return text;
}

FileLog write_result(string* text, int count, const char* output) {

    assert(text != NULL);

    FILE* fout = fopen(output, "w");

    if (fout == NULL)
        return CANNOT_WRITE_FILE;

    for (int i = 0; i < count; ++i) {

        *((text + i)->ptr + (text + i)->length) = '\0';
    }

    for (int i = 0; i < count; ++i) {

        fputs((text + i)->ptr, fout);
        fputs("\n", fout);
    }

    // To separate different texts
    fputs("", fout);
    fputs("", fout);

    fclose(fout);
    return FILE_OK;
}

FileLog clear(const char* filename) {

    assert(filename != NULL);

    FILE* fo = fopen(filename, "w");

    if (fo == NULL)
        return CANNOT_FIND_FILE;

    fclose(fo);
    return FILE_OK;
}

FileLog get_file_names(char* input, char* output) {

    puts("Enter path to input file:");
    scanf("%s", input);

    FILE* fin = fopen(input, "r");
    if (fin == NULL)
        return CANNOT_READ_FILE;

    fclose(fin);

    puts("Enter path to output file:");
    scanf("%s", output);

    FILE* fout = fopen(output, "w");
    if (fout == NULL)
        return CANNOT_WRITE_FILE;

    fclose(fout);

    return FILE_OK;
}

void free_text_buf(string* text, char* buf) {

    assert(text != NULL);
    assert(buf  != NULL);

    free(text);
    free(buf);
}
