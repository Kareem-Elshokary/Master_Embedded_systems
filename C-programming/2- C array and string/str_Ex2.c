/*
 * str_Ex2.c
 *
 *  Created on: Mar 18, 2023
 *      Author: KARIM
 *  Find a length of a string
 */

#include<stdio.h>

int main(){
	char name[20];
	int i;

	printf("Enter a string: \n");
	fflush(stdin); fflush(stdout);
	fgets(name,sizeof(name),stdin);

	for(i=0; name[i]!=0; ++i);
	printf("length of string = %d",i);

	return 0;
}
