#ifndef WORK_H

#define WORK_H

#include <stdbool.h>

#define SYMBOL_LIMIT_IN_FILE 300
#define QUANTITY_SYMBOL_IN_ENGLISH 26

int Write_File(char**, int*, int);
int Read_File(const char*, char***, int**, int*);
bool Check_English_Symbol(char);
int Get_Size_for_Array(const char*, int***, int*);

#endif