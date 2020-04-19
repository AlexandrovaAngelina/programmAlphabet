#include "interface.h"

#include <stdio.h>

int main()
{
    char** note = NULL;
    char* file_name = "input.txt";
    int* arr_length = NULL;
    int quantity_words = 0;
    int error_flag = 0;
    error_flag = User_Choise(file_name, note, arr_length, quantity_words);
    printf("error: %d", error_flag);
    return 0;
}