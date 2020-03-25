#include <stdio.h>
#include <malloc.h>

int Get_Quantity_Words(const char *file_name)
{
	int q=0;
	FILE *file=NULL;
	file=fopen(file_name,"rb");
	if(file==NULL)
	{
		return -1;
	}
	int check=0;
	while(!feof(file))
	{
		check++;
		char temp=0;
		temp=fgetc(file);
		if(temp==' ')
		{
			q++;
		}
		else
		{
			if((temp==',')||(temp==';')||(temp==':'))
			{
				q++;
				fgetc(file);
			}
			else
			{
				if((temp=='!')||(temp=='?')||(temp=='.'))
				{
					q++;
					for(short int i=0;i<2;i++)
					{
						temp=fgetc(file);
						if(temp!='.')
						{
							break;
						}
					}
					fgetc(file);
				}
			}
		}
	}
	printf("\ncheck=%d\n",check);
	fclose(file);
	return q;
}

int Read_File(const char *file_name,char ***note)
{
	int quantity_words=0;
	quantity_words=Get_Quantity_Words(file_name);
	if(quantity_words==-1)
	{
		return 1;
	}
	printf("\nq=%d\n",quantity_words);
	FILE *file=NULL;
	file=fopen(file_name,"rb");
	if(file==NULL)
	{
		return 1;
	}
	return 0;
}

int main()
{
	char **note=NULL;
	int error_flag=0;
	error_flag=Read_File("input.txt",&note);
	printf("\nerror:%d\n",error_flag);
	return 0;
}
