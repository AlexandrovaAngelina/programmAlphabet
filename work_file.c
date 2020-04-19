#include "work_file.h"

#include <stdio.h>

int Write_File(char** note, int* arr_length, int quantity_words)
{
    FILE* file = NULL;
    file = fopen("output.txt", "wb");
    if (file == NULL) {
        return 1;
    }
    for (short int i = 0; i < quantity_words; i++) {
        for (short int j = 0; j < arr_length[i]; j++) {
            putc(note[i][j], file);
        }
        putc('\r', file);
    }
    return 0;
}