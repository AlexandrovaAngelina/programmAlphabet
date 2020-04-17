#include "work_file.h"

#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool Check_Punctuation_Character(char temp)
{
    if ((temp == ' ') || (temp == '\n') || (temp == '\r') || (temp == '!')
        || (temp == '?') || (temp == ',') || (temp == '.') || (temp == ':')
        || (temp == ';')) {
        return true;
    }
    return false;
}

int Read_File(
        const char* file_name,
        char** note[],
        int* arr_length[],
        int* quantity_words)
{
    quantity_words = Get_Size_for_Array(file_name, &arr_length, quantity_words);
    if (quantity_words == NULL) {
        return 1;
    }
    FILE* file = NULL;
    file = fopen(file_name, "rb");
    if (file == NULL) {
        return 1;
    }
    *note = (char**)calloc((*quantity_words), sizeof(char*));
    for (short int i = 0; i < (*quantity_words); i++) {
        (*note)[i] = (char*)calloc((*arr_length)[i], sizeof(char));
        for (short int j = 0; j < (*arr_length)[i]; j++) {
            while (((Check_Punctuation_Character((*note)[i][j] = getc(file))))
                   && (!feof(file)))
                printf("***%c***", (*note)[i][j]);
        }
    }
    return 0;
}

int* Get_Size_for_Array(
        const char* file_name, int** arr_length[], int* quantity_words)
{
    int length_word = 0;
    char temp = '0';
    FILE* file = NULL;
    file = fopen(file_name, "rb");
    if (file == NULL) {
        return NULL;
    }
    while (!feof(file)) {
        while (Check_Punctuation_Character(temp = getc(file)) != true
               && !feof(file)) {
            length_word++;
            printf("%c", temp);
        }
        while (Check_Punctuation_Character(temp = getc(file)))
            ;
        *quantity_words = *quantity_words + 1;
        if ((*quantity_words) > 1) {
            **arr_length = (int*)realloc(
                    **arr_length, (*quantity_words) * sizeof(int));
        } else {
            **arr_length = (int*)calloc(*quantity_words, sizeof(int));
        }
        printf("\n%c", temp);
        (**arr_length)[(*quantity_words) - 1] = length_word;
        length_word = 1;
    }
    fclose(file);
    printf("\nq=%d\n", *quantity_words);
    return quantity_words;
}

int main()
{
    char** note = NULL;
    int* arr_length = NULL;
    char* file_name = "input.txt";
    int quantity_words = 0;
    int error_flag = 0;
    error_flag = Read_File(file_name, &note, &arr_length, &quantity_words);
    printf("\nq=%d\n", quantity_words);
    for (short int i = 0; i < quantity_words; i++) {
        printf("%d", arr_length[i]);
    }
    if (note != NULL) {
        for (short int i = 0; i < quantity_words; i++) {
            printf("\n");
            for (short int j = 0; j < arr_length[i]; j++) {
                printf("%c", note[i][j]);
            }
        }
    }
    printf("\nerror: %d\n", error_flag);
    return 0;
}