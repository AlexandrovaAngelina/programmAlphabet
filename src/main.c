#include "interface.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char** note = NULL;
    char* file_name = "text/input.txt";
    int* arr_length = NULL;
    int quantity_words = 0;
    int error_flag = 0;
    error_flag = User_Choice(file_name, note, arr_length, quantity_words);
    if (error_flag == ERROR_INPUT_FILE) {
        MESSEGE_BY_INPUT_DONT_OPEN;
    } else {
        if (error_flag == ERROR_OUTPUT_FILE) {
            MESSEGE_BY_OUTPUT_DONT_OPEN;
        } else {
            if (error_flag == EMPTY_INPUT_FILE) {
                MESSEGE_BY_EMPTY_INPUT_FILE;
            }
        }
    }
    return 0;
}