#ifndef TEXTIO_INClUDED
#define TEXTIO_INClUDED

#include <stdio.h>

/*!
 * @brief Funcs returns the code from this enum
 *
 * @version 0.1
 */
enum FileLog {
    FILE_OK           = 0, //< Means that all is ok
    CANNOT_FIND_FILE  = 1, //< Means that file is not in current directory
    CANNOT_READ_FILE  = 2, //< Means that file isn't avalible for reading 
    CANNOT_WRITE_FILE = 3, //< Means that file isn't avalible for writing
    NO_MEMORY         = 4  //< Means that there is not enough memory
};

typedef enum FileLog FileLog;

/*!
 * @brief Struct of string...
 *
 * Nothing to say about it...
 *
 * @version 0.1
 */
struct string {
    char*  ptr;    //< Pointer to the string
    size_t length; //< Length of this string
};

typedef struct string string;

/*!
 * @brief Func which is needed to bufferise file.
 *
 * It reads from input file all strings and
 * optinally safes them to memory.
 *
 * @param [out] <buffer> array of pointers
 *                       to the strings
 * 
 * @return code of error or 0 if all was ok
 *         (see FileLog enum for more details)
 * 
 * @version 0.1
 */
FileLog input(char** buffer, const char* input_file);

/*!
 * @brief Makes an array of strings
 *
 * From big cstring <buffer> creates an array
 * of strings
 *
 * @param [in]  <buffer> pointer to the beginning of buffer
 * @param [out] <count>  count of strings in buffer
 * @param [in]  <ch>     delimeter of strings in <buffer>
 */
string* parser(char* buffer, int* count, char ch);

/*!
 * @brief This func clears the <filename> file
 *
 * You need to clear output file before
 * you add something to it (if you wanna
 * to get useful output)
 *
 * @param [in] <filename> the name of file to clear
 */
FileLog clear(const char* filename);

/*!
 * @brief Use it to change filenames
 *
 * Changes names of <input> and <output> files
 *
 * @return code of error or 0 if all was ok
 *         (see FileLog enum for more details)
 *
 * @version 0.1
 */
FileLog get_file_names(char* input, char* output);

/*!
 * @brief Writes in file <output>
 *
 * Use it to write text from string arra <text>
 * in the file <output>
 *
 * @param [in]  <text>    pointer to the array of strings
 * @param [in]  <output>  name of ouput file
 *
 * @return code of error or 0 if all was ok
 *         (see FileLog enum for more details)
 *
 * @version 0.1
 */
FileLog write_result(string* text, const char* output);

#endif // TEXTIO_INClUDED