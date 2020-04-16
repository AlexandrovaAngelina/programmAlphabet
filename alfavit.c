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

int Get_Quantity_Words(const char* file_name)
{
    int q = 0;
    FILE* file = NULL;
    file = fopen(file_name, "rb");
    if (file == NULL) {
        return -1;
    }
    while (!feof(file)) {
        char temp = 0;
        temp = fgetc(file);
        if (temp == ' ') {
            q++;
        } else {
            if ((temp == ',') || (temp == ';') || (temp == ':')) {
                q++;
                fgetc(file);
            } else {
                if ((temp == '!') || (temp == '?') || (temp == '.')) {
                    q++;
                    for (short int i = 0; i < 2; i++) {
                        temp = fgetc(file);
                        if (temp != '.') {
                            break;
                        }
                    }
                    fgetc(file);
                }
            }
        }
    }
    fclose(file);
    return q;
}

int* Get_Length_Words(
        const char* file_name, int* arr_length, int quantity_words)
{
    int q = 0;
    int length_word = 0;
    FILE* file = NULL;
    file = fopen(file_name, "rb");
    if (file == NULL) {
        return NULL;
    }
    arr_length = (int*)calloc(quantity_words, sizeof(int));
    while (!feof(file)) {
        char temp = 0;
        temp = fgetc(file);
        if (temp == ' ') {
            arr_length[q] = length_word;
            length_word = 0;
            q++;
        } else {
            if ((temp == ',') || (temp == ';') || (temp == ':')) {
                arr_length[q] = length_word;
                length_word = 0;
                q++;
                fgetc(file);
            } else {
                if ((temp == '!') || (temp == '?') || (temp == '.')) {
                    arr_length[q] = length_word;
                    length_word = 0;
                    q++;
                    for (short int i = 0; i < 3; i++) {
                        temp = fgetc(file);
                        if (temp != '.') {
                            break;
                        }
                    }
                } else {
                    if (temp != '\n') {
                        length_word++;
                    }
                }
            }
        }
    }
    fclose(file);
    return arr_length;
}

int Read_File(const char* file_name, char*** note)
{
    int quantity_words = 0;
    int* arr_length = NULL;
	char** buffer = NULL;
	char temp = '0';
	FILE* file = NULL;
    quantity_words = Get_Quantity_Words(file_name);
    if (quantity_words == -1) {
        return 1;
    }
    arr_length = Get_Length_Words(file_name, arr_length, quantity_words);
    if (arr_length == NULL) {
        return 1;
    }
    file = fopen(file_name, "rb");
    if (file == NULL) {
        return 1;
    }
    buffer = (char**)calloc(quantity_words, sizeof(char*));
    for (short int i = 0; i < quantity_words; i++) {
    	buffer[i] = (char*)calloc(arr_length[i], sizeof(char));
    }
    for (short int i = 0; (i < quantity_words) && (!feof(file)); i++) {
        for (short int j = 0; (j < arr_length[i]) && (!feof(file)); j++) {
            temp = fgetc(file);
            if (Check_Punctuation_Character(temp) == true) {
                j--;
            } else {
                buffer[i][j] = temp;
                printf("%c", buffer[i][j]);
            }
        }
        printf("\n");
    }
	*note = buffer;
	fclose(file);
    return 0;
}

int main()
{
    char** note = NULL;
    int error_flag = 0;
    error_flag = Read_File("input.txt", &note);
	if(note == NULL)
	{
		printf("crash");
	}
	else
	{
		printf("%c",note[0][0]);
	}
	
    printf("\nerror:%d\n", error_flag);
    return 0;
}