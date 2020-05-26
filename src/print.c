#include "print.h"

#include <stdio.h>

void Print_Text(char** note, int* arr_length, int quantity_words)
{
    printf("\ntext:\n");
    for (short int i = 0; i < quantity_words; i++) {
        for (short int j = 0; j < arr_length[i]; j++) {
            printf("%c", note[i][j]);
        }
        printf("\n");
    }
}