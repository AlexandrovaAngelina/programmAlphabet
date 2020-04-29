#include "interface.h"
#include "print.h"
#include "sort.h"
#include "work_file.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void Menu()
{
    printf("1)Print text\n");
    printf("2)Sort text\n");
    printf("3)Write in file\n");
    printf("9)Clear screen\n");
    printf("0)Exit\n");
}

int Check_Correct_Choice(int key_choice)
{
    if ((key_choice < EXIT_FROM_PROGRAMM) || (key_choice > CLEAR_SCREEN)) {
        return INCORECT_CHOICE;
    }
    if ((key_choice > WRITE_IN_FILE) && (key_choice < CLEAR_SCREEN)) {
        return INCORECT_CHOICE;
    }
    return key_choice;
}

char** Free_Note(char** note, int quantity_words)
{
    for (short int i = 0; i < quantity_words; i++) {
        free(note[i]);
    }
    free(note);
    return note;
}

int User_Choice(
        char* file_name, char** note, int* arr_length, int quantity_words)
{
    int error_flag = 0;
    int key_choice = 0;
    bool sort_flag = false;
    error_flag = Read_File(file_name, &note, &arr_length, &quantity_words);
    if(error_flag == ERROR_INPUT_FILE)
    {
        return error_flag;
    }
    while (1) {
        Menu();
        scanf("%d", &key_choice);
        key_choice = Check_Correct_Choice(key_choice);
        if (key_choice == INCORECT_CHOICE) {
            MESSEGE_BY_INCORECT_CHOISE;
            continue;
        }
        switch (key_choice) {
        case (SORT_TEXT): {
            if (sort_flag == false) {
                Sort_Text(&note, arr_length, 0, quantity_words);
                sort_flag = true;
            }
            break;
        }
        case (PRINT_TEXT): {
            Print_Text(note, arr_length, quantity_words);
            break;
        }
        case (WRITE_IN_FILE): {
            error_flag = Write_File(note, arr_length, quantity_words);
            break;
        }
        case (CLEAR_SCREEN): {
            system("clear");
            break;
        }
        case (EXIT_FROM_PROGRAMM): {
            note = Free_Note(note, quantity_words);
            free(arr_length);
            return error_flag;
        }
        }
    }
    return error_flag;
}