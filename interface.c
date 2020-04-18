#include "interface.h"

#include <stdio.h>
#include <stdlib.h>

void Menu()
{
    printf("1)Read from file\n");
    printf("2)Sort text\n ");
    printf("3)Print text\n ");
    printf("4)Write in file\n");
    printf("5)Clear screen\n ");
    printf("0)Exit\n");
}

int User_Choise()
{
    int error_flag = 0;
    int key_choise = 0;
    bool sort_flag = true;
    scanf("%d", &key_choise);
    while (1) {
        Menu();
        switch (key_choise) {
        case (1): {
            error_flag = Read_File();
            sort_flag = false;
            break;
        }
        case (2): {
            if (sort_flag == false) {
                Sort_Text();
            }
            break;
        }
        case (3): {
            Print_Text();
            break;
        }
        case (4): {
            error_flag = Write_File();
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
    return error_flag;
}