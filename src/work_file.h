#ifndef WORK_H

#define WORK_H

#include <stdbool.h>

int Write_File(char**, int*, int);
int Read_File(const char*, char***, int**, int*);
bool Check_Punctuation_Character(char);
int Get_Size_for_Array(const char*, int***, int*);

#endif