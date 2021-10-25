#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "set.h"




//typedef unsigned char UCHAR;



void strclean(unsigned char *s);
int int_compare(TYPE data1,TYPE data2);
void int_print(TYPE data);


int main()
{
	FILE *fp=fopen("texto.txt","r");

	unsigned char word[50];
	int count = 0;

	SET set=set_create(int_compare,int_print);

	if(fp==NULL)
	{
	fprintf(stderr,"Error al abrir archivo\n");
	exit(1);
	}

	while(!feof(fp))
	{
	fscanf(fp,"%s",word);

	strclean(word);

	set_add(set,string_create(word));

	printf("%s\n",set_size(set));

	++count;

	}

	printf("El numero de palabras en el texto es de: %d \n", count);
	printf("%s\n",set_size(set));

	fclose(fp);
}




void strclean(unsigned char *s)
{



while(*s)
{
if(*s=='.' || *s==',' || *s=='!' || *s=='?' || *s==')' || *s==':')
*s='\0';



if(*s>=192 && *s<=197)
*s='A';
if(*s>=224 && *s<=229)
*s='a';
if(*s>=200 && *s<=203)
*s='E';
if(*s>=232 && *s<=235)
*s='e';
if(*s>=204 && *s<=207)
*s='I';
if(*s>=236 && *s<=239)
*s='i';
if(*s>=210 && *s<=214)
*s='O';
if(*s>=242 && *s<=246)
*s='o';
if(*s>=217 && *s<=220)
*s='U';
if(*s>=249 && *s<=252)
*s='u';



// Si es mayúscula
if(*s>='A' && *s<='Z')
*s+=32; // Convertirlo a minúscula 'A'=65 'a'=97



s++;
}
}

int int_compare(TYPE data1,TYPE data2)
{
	int *np1 = data1;
	int *np2 = data2;
	return(*np1 - *np2);
}

void int_print(TYPE data)
{
	printf("%d\n",*((int *)data));
}
