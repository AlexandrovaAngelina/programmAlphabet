#include "sort.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool Less(char* a, char* b, int a_length, int b_length)
{
	printf("zahod\n");
	printf("al = %d\tbl = %d",a_length,b_length);
    int i = 0;
    int j = 0;
    while(1)
    {
        if( (i < a_length) && (j < a_length) )
        {
        	printf("i=%d j=%d",i,j);
            printf("\n%c = %c\n",a[i],b[j]);
			if(a[i] < b[j])
            {
            	printf("\n%c < %c\n",a[i],b[j]);
                return true;
            }
            if(a[i] > b[j])
            {
                return false;
            }
            if( (i == a_length - 1) && (j < b_length - 1) )
            {
                i--;
            }
            else
            {
            	if( (j == b_length - 1) && (i < a_length -1) )
	            {
	                j--;
	            }	
			}
        	i++;
        	j++;
		}
		else
		{
			break;
		}
    }
    return false;
}

int Sort_Text(char*** note, int* arr_length, int left_limit, int right_limit)
{
	printf("\n qqq \n");
    int i=left_limit;
    int j=right_limit;
    int mediana = 0;
	char *host_item = NULL;
    char *temp = NULL;
    int temp_l;
    mediana = (left_limit+right_limit)/2;
    host_item = (*note)[mediana];
	while(i<=j)
	{
		while( Less((*note)[i],host_item,arr_length[i],arr_length[mediana]) )
		{
			printf("vihod I\n i == %d",i);
			i++;
		}
		while( (Less((*note)[j],host_item,arr_length[j],arr_length[mediana])) == false ) 
        {
			printf("vihod J\n j == %d",j);
			j--;
		}
		if(i <= j)
		{
			temp_l = arr_length[i];
			arr_length[i] = arr_length[j];
			arr_length[j] = temp_l;
			temp=(*note)[j];
			(*note)[j]=(*note)[i];
			(*note)[i]=temp;
			i++;
			j--;
		}
	}
	if(left_limit<j)
	{
		printf("l\n");
		Sort_Array(note,arr_length,left_limit,j-1);	
	}
	if(i<right_limit)
	{
		printf("r");
		Sort_Array(note,arr_length,i,right_limit-1);	
	}
	return 0;
}

int main()
{
    char** note = NULL;
    int *arr_length = NULL;
    int quantity_words = 4;
    int error_flag = 0;
    arr_length = (int*) calloc (quantity_words,sizeof(int));
    arr_length[0] = 3;
    arr_length[1] = 3;
    arr_length[2] = 1;
    arr_length[3] = 4;
    note = (char**) calloc (quantity_words,sizeof(char*));
    for(short int i = 0; i < quantity_words; i++)
    {
        note[i] = (char*) calloc (arr_length[i],sizeof(char));
    }
    note[0][0] = 'f';
    note[0][1] = 'd';
    note[0][2] = 'c';
    note[1][0] = 'f';
    note[1][1] = 'd';
    note[1][2] = 'c';
    note[2][0] = 'f';
    note[3][0] = 'b';
    note[3][1] = 'a';
    note[3][2] = 'f';
    note[3][3] = 'g';
    for(short int i = 0; i < quantity_words; i++)
    {
        printf("\n%d) ",i);
        for(short int j = 0; j < arr_length[i]; j++)
        {
            printf("%c",note[i][j]);
        }
    }
	error_flag = Sort_Array(&note,arr_length,0,quantity_words-1);
    for(short int i = 0; i < quantity_words; i++)
    {
        printf("\n%d) ",i);
        for(short int j = 0; j < arr_length[i]; j++)
        {
            printf("%c",note[i][j]);
        }
    }
    printf("\nerror: %d\n",error_flag);
    return 0;
}