#include "interface.h"
#include "print.h"
#include "sort.h"
#include "work_file.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void Menu()
{
    printf("1)Read from file\n");
    printf("2)Sort text\n");
    printf("3)Print text\n");
    printf("4)Write in file\n");
    printf("9)Clear screen\n");
    printf("0)Exit\n");
}

int User_Choice(
        char* file_name, char** note, int* arr_length, int quantity_words)
{
    int error_flag = 0;
    int key_choice = 0;
    bool sort_flag = true;
    while (1) {
        Menu();
        scanf("%d", &key_choice);
        switch (key_choice) {
        case (1): {
            error_flag
                    = Read_File(file_name, &note, &arr_length, &quantity_words);
            sort_flag = false;
            break;
        }
        case (2): {
            if (sort_flag == false) {
                Sort_Text(&note, arr_length, 0, quantity_words);
                sort_flag = true;
            }
            break;
        }
        case (3): {
            Print_Text(note, arr_length, quantity_words);
            break;
        }
        case (4): {
            error_flag = Write_File(note, arr_length, quantity_words);
            break;
        }
        case (9): {
            system("clear");
            break;
        }
        case (0): {
            return error_flag;
        }
        }
    }
    for (short int i = 0; i < quantity_words; i++) {
        free(note[i]);
    }
    free(note);
    free(file_name);
    free(arr_length);
    return error_flag;
}