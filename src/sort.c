#include "sort.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int Comparison(char* a, char* b, int a_length, int b_length)
{
    int i = 0;
    int j = 0;
    while (1) {
        if ((i < a_length) && (j < a_length)) {
            if (a[i] < b[j]) {
                return LESS;
            }
            if (a[i] > b[j]) {
                return LARGE;
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
    return EQUALLY;
}

int Sort_Text(char*** note, int** arr_length, int left_limit, int right_limit)
{
    int i = left_limit;
    int j = right_limit;
    int mediana = 0;
    char* host_item = NULL;
    char* temp_word = NULL;
    int temp_length;
    mediana = (left_limit + right_limit) / 2;
    host_item = (*note)[mediana];
    while (i <= j) {
        while (Comparison(
                       (*note)[i],
                       host_item,
                       (*arr_length)[i],
                       (*arr_length)[mediana])
               == LESS) {
            i++;
        }
        while ((Comparison(
                       (*note)[j],
                       host_item,
                       (*arr_length)[j],
                       (*arr_length)[mediana]))
               == LARGE) {
            j--;
        }
        if (i <= j) {
            temp_length = (*arr_length)[i];
            (*arr_length)[i] = (*arr_length)[j];
            (*arr_length)[j] = temp_length;
            temp_word = (*note)[j];
            (*note)[j] = (*note)[i];
            (*note)[i] = temp_word;
            i++;
            j--;
        }
    }
    if (left_limit < j) {
        Sort_Text(&(*note), &(*arr_length), left_limit, j);
    }
    if (i < right_limit) {
        Sort_Text(&(*note), &(*arr_length), i, right_limit);
    }
    return 0;
}