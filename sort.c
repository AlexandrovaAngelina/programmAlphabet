#include "sort.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool Less(char* a, char* b, int a_length, int b_length)
{
    int i = 0;
    int j = 0;
    while (1) {
        if ((i < a_length) && (j < a_length)) {
            if (a[i] < b[j]) {
                return true;
            }
            if (a[i] > b[j]) {
                return false;
            }
            if ((i == a_length - 1) && (j < b_length - 1)) {
                i--;
            } else {
                if ((j == b_length - 1) && (i < a_length - 1)) {
                    j--;
                }
            }
            i++;
            j++;
        } else {
            break;
        }
    }
    return false;
}

int Sort_Text(char*** note, int* arr_length, int left_limit, int right_limit)
{
    int i = left_limit;
    int j = right_limit;
    int mediana = 0;
    char* host_item = NULL;
    char* temp = NULL;
    int temp_l;
    mediana = (left_limit + right_limit) / 2;
    host_item = (*note)[mediana];
    while (i <= j) {
        while (Less(
                (*note)[i], host_item, arr_length[i], arr_length[mediana])) {
            i++;
        }
        while ((Less((*note)[j], host_item, arr_length[j], arr_length[mediana]))
               == false) {
            j--;
        }
        if (i <= j) {
            temp_l = arr_length[i];
            arr_length[i] = arr_length[j];
            arr_length[j] = temp_l;
            temp = (*note)[j];
            (*note)[j] = (*note)[i];
            (*note)[i] = temp;
            i++;
            j--;
        }
    }
    if (left_limit < j) {
        Sort_Array(note, arr_length, left_limit, j - 1);
    }
    if (i < right_limit) {
        Sort_Array(note, arr_length, i, right_limit - 1);
    }
    return 0;
}