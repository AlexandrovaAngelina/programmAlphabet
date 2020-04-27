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
    switch (error_flag) {
    case (-1): {
        printf("error: File input.txt dont open");
        break;
    }
    case (-2): {
        printf("error: File output.txt dont open");
        break;
    }
    }
    return 0;
}