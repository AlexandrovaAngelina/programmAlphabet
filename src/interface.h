#ifndef INTERFACE_H

#define INTERFACE_H

#define PRINT_TEXT 1
#define SORT_TEXT 2
#define WRITE_IN_FILE 3
#define CLEAR_SCREEN 9
#define EXIT_FROM_PROGRAMM 0
#define ERROR_INPUT_FILE -1
#define ERROR_OUTPUT_FILE -2
#define INCORECT_CHOICE -3
#define EMPTY_INPUT_FILE -4

#define MESSEGE_BY_INPUT_DONT_OPEN printf("error: File input.txt dont open\n");
#define MESSEGE_BY_EMPTY_INPUT_FILE printf("error: File input.txt is empty\n");
#define MESSEGE_BY_OUTPUT_DONT_OPEN \
    printf("error: File output.txt dont open\n");
#define MESSEGE_BY_INCORECT_CHOISE \
    printf("\nerror: Please enter 1 or 2 or 3 or 9 or 0\n");

void Menu();
int Check_Correct_Choice(int);
int User_Choice(char*, char**, int*, int);
char** Free_Note(char**, int);

#endif