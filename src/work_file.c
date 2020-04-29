#include "work_file.h"
#include "interface.h"

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
    int limit = 0;
    *quantity_words
            = Get_Size_for_Array(file_name, &arr_length, quantity_words);
    if (*quantity_words == ERROR_INPUT_FILE) {
        return ERROR_INPUT_FILE;
    }
    FILE* file = NULL;
    file = fopen(file_name, "rb");
    if (file == NULL) {
        return ERROR_INPUT_FILE;
    }
    *note = (char**)calloc((*quantity_words), sizeof(char*));
    for (short int i = 0; i < (*quantity_words); i++) {
        (*note)[i] = (char*)calloc((*arr_length)[i], sizeof(char));
        for (short int j = 0; j < (*arr_length)[i]; j++) {
            while (((Check_Punctuation_Character((*note)[i][j] = getc(file))))
                   && (!feof(file)) && limit < SYMBOL_LIMIT_IN_FILE) {
                limit++;
            }
        }
    }
    fclose(file);
    return 0;
}

int Get_Size_for_Array(
        const char* file_name, int** arr_length[], int* quantity_words)
{
    int limit = 0;
    int length_word = 0;
    char temp = '0';
    FILE* file = NULL;
    file = fopen(file_name, "rb");
    if (file == NULL) {
        return ERROR_INPUT_FILE;
    }
    while ((!feof(file)) && limit < SYMBOL_LIMIT_IN_FILE) {
        while (Check_Punctuation_Character(temp = getc(file)) != true
               && !feof(file) && limit < SYMBOL_LIMIT_IN_FILE) {
            limit++;
            length_word++;
        }
        while (Check_Punctuation_Character(temp = getc(file))
               && limit < SYMBOL_LIMIT_IN_FILE) {
            limit++;
        }
        *quantity_words = *quantity_words + 1;
        if ((*quantity_words) > 1) {
            **arr_length = (int*)realloc(
                    **arr_length, (*quantity_words) * sizeof(int));
        } else {
            **arr_length = (int*)calloc(*quantity_words, sizeof(int));
        }
        (**arr_length)[(*quantity_words) - 1] = length_word;
        length_word = 1;
    }
    fclose(file);
    return *quantity_words;
}

int Write_File(char** note, int* arr_length, int quantity_words)
{
    FILE* file = NULL;
    file = fopen("text/output.txt", "wb");
    if (file == NULL) {
        return ERROR_OUTPUT_FILE;
    }
    for (short int i = 0; i < quantity_words; i++) {
        for (short int j = 0; j < arr_length[i]; j++) {
            putc(note[i][j], file);
        }
        putc('\r', file);
    }
    fclose(file);
    return 0;
}